#!/usr/bin/perl
# $FreeBSD$

use File::Basename;
use File::Find;
use File::Path;

my $debug	= 1;
my $fake	= 0;
my $pkg_ext     = "tbz";

my %discs;
my %distfiles;
my %index;
my %unplaced;

sub copyDist($$) {
    my $disc = shift;
    my $name = shift;

    my $distfile = "$disc/distfiles/$name";
    my $dir = dirname($distfile);
    mkpath($dir);

    debugPrint("copying $distfile");
    if ($fake) {
        system("touch $distfile");
    } else {
        system("cp $distDir/$name $distfile");
    }
}

sub copyPkg($$) {
    my $disc = shift;
    my $name = shift;
    my $pkg  = $index{$name};
    my $base = $pkg->{base};
    my $text = $pkg->{INDEX};

  # Copy over the package.
    debugPrint("copying $disc/packages/All/$name.$pkg_ext");
    mkpath("$disc/packages/All");
    if ($fake) {
        system("touch $disc/packages/All/$name.$pkg_ext");
    } else {
        system("cp -f $pkgDir/All/$name.$pkg_ext $disc/packages/All");
    }

  # Create symlinks in each category.
    foreach $cat (@{$pkg->{cats}}) {
        debugPrint("creating $disc/packages/$cat/$name.$pkg_ext");
        mkpath("$disc/packages/$cat");
        symlink("../All/$name.$pkg_ext", "$disc/packages/$cat/$name.$pkg_ext");
    }

  # If required created the Latest symlink.
    mkpath("$disc/packages/Latest");
    if ($pkg->{latest}) {
        symlink("../All/$name.$pkg_ext", "$disc/packages/Latest/$base.$pkg_ext");
    }

  # Add the package to INDEX.
    open(BAR, ">>$disc/packages/INDEX");
    print(BAR "$text\n");
    close(BAR);
}

sub debugPrint($) {
    my $line = shift;
    print STDERR $line . "\n" if $debug;
}

sub addDistfile() {
    return if -d;

    my $name = $File::Find::name;
    my $size = (stat($name))[7];

  # Don't record distfiles that are of zero length.
    if ($size == 0) {
        debugPrint("zero length distfile: $name");
        return;
    }

    $name =~ s!$distDir/!!;
    $distfiles{$name} = $size;
}

sub doDistfiles() {
    my %clumps;

  # Get a list of all the disfiles and their sizes.
    find(\&addDistfile, $distDir);

  # xxx Need to clump distfiles so that all the ones for a port end up
  # xxx on the same disc.  For now each distfile is it's own clump. :(
    foreach $distfile (sort keys %distfiles) {
        my @a = ($distfile);
        $clumps{$distfiles{$distfile}} = \@a;
    }

  # Place as many clumps as we can fit on each disc.
    foreach $disc (sort keys %discs) {
        next if ! $discs{$disc}->{distFlag};

        my $d = $discs{$disc};
        my @keys = sort { $a <=> $b } (keys %clumps);

        debugPrint("placing distfiles on $disc ...");

        while ($d->{avail} > 0) {
            my $workDone = 0;

            foreach $size (@keys) {
                last if ($size > $d->{avail});
                placeDist($disc, $size, @{$clumps{$size}});
                delete $clumps{$size};
                $workDone++;
            }

            debugPrint("workDone = $workDone");
            last if (!$workDone);
        }
    }

  # Put the remaining clumps on the scratch disc.
    foreach $size (keys %clumps) {
        placeDist('scratch', $size, @{$clumps{$size}});
    }
}

sub doPackages() {
  # Place as many packages as we can fit on each disc.
    foreach $disc (sort keys %discs) {
        next if ! $discs{$disc}->{pkgFlag};

        my $d = $discs{$disc};

        debugPrint("placing packages on $disc ...");
        my $d = $discs{$disc};

        while ($d->{avail} > 0) {
            redoImpact($disc);

            my $workDone = 0;
            my @keys = sort { $impact{$a} <=> $impact{$b} } (keys %unplaced);

            foreach $name (@keys) {
                if ($impact{$name} <= $d->{avail}) {
                    placePkg($disc, $name, 0);
                    $workDone = 1;
                    last;
                }
            }

            last if (!$workDone);
        }
    }

  # Put all the unplaced packages on the scratch disc.
    redoImpact('scratch');
    foreach $name (keys %unplaced) {
        debugPrint("uplaced package: $name");
        placePkg('scratch', $name, 0);
    }
}

sub isLatest($$) {
    my ($name, $base) = @_;
    my $link = "$pkgDir/Latest/$base.$pkg_ext";
    my $pkg = "$pkgDir/All/$name.$pkg_ext";

    return 0 if ! -l $link;

    my ($dev1, $ino1) = stat($pkg);
    my ($dev2, $ino2) = stat($pkg);

    return $dev1 == $dev2 && $ino1 == $ino2;
}

sub placeDist($$@) {
    my $disc      = shift;
    my $size      = shift;
    my @distfiles = @_;
    my $d         = $discs{$disc};

  # Adjust sizes of disc based on the impact of this package.
    $d->{used} += $size;
    $d->{avail} -= $size;

  # Add each of the distfiles to this disc.
    foreach $name (@distfiles) {
        debugPrint("placing $name on $disc");
        $d->{distfiles}->{$name}++;
    }
}

sub placeNeeded() {
    local *NEEDED;

    debugPrint("reading $neededPkgs and placing packages ...");
    open(NEEDED, $neededPkgs)
      or die "unable to read $neededPkgs: $!\n";

    my $disc;

    $_ = <NEEDED>;
    chomp;

    if (/^disc (\w+)/) {
        $disc = $1;
    } else {
        die "invalid first line in $neededPkgs: $_";
    }

    while (<NEEDED>) {
        chomp;

        if (/^disc (\w+)/) {
            $disc = $1;
            next;
        }

        if (defined($index{$_})) {
            placePkg($disc, $_, 1);
        } else {
          # die "missing needed package: $_";
        }
    }

    close(NEEDED);
}

sub placePkg($$$) {
    my $disc   = shift;
    my $name   = shift;
    my $nodeps = shift;

    debugPrint(" placing $name on $disc");

    my $size;

    if ($nodeps) {
        $size = $index{$name}->{size};
    } else {
        $size = $impact{$name};
    }

  # Adjust sizes of disc based on the impact of this package.
    my $d = $discs{$disc};

    $d->{used} += $size;
    $d->{avail} -= $size;

  # Remove this package from unplaced and place it on this disc.
    delete $unplaced{$name};
    $d->{pkgs}->{$name}++;

  # Now do the same thing for the dependencies.
    return if $nodeps;

    foreach (@{$index{$name}->{rdeps}}) {
        delete $unplaced{$_};
        $d->{pkgs}->{$_}++;
    }
}

sub readDiscInfo() {
    local *INFO;

  # Make sure we have at least disc that will be the place overflow will go.
    my $disc = {
      'avail'           => 0,
      'distFlag'	=> 0,
      'distfiles'       => {},
      'name'            => 'scratch',
      'pkgFlag'		=> 0,
      'pkgs'            => {},
      'size'            => 0,
      'used'            => 0
    };
    $discs{'scratch'} = $disc;

    debugPrint("reading $discInfo ...");
    open(INFO, $discInfo)
      or die "unable to read $discInfo: $!";

    while (<INFO>) {
        chomp;
	next if (/^#/);

        my @f = split(/\s+/);
        next if (@f != 4);

        my $disc = {
          'avail'	=> $f[3],
          'distFlag'	=> $f[2],
          'distfiles'	=> {},
          'name'	=> $f[0],
          'pkgFlag'	=> $f[1],
          'pkgs'	=> {},
          'size'	=> $f[3],
          'used'	=> 0
        };

        $discs{$f[0]} = $disc;
    }

    close(INFO);
}

sub readIndex() {
    local *INDEX;

    debugPrint("reading $indexFilename ...");
    open(INDEX, $indexFilename)
      or die "unable to read $indexFilename: $!";

    while (<INDEX>) {
        chomp;

        my @f    = split(/\|/);
        my $name = $f[0];
        my $base = $name;

        $base =~ s/-[^-]*$//;

        my $pkg = {
          'INDEX'	=> $_,
          'base'	=> $base,
          'cats'	=> [split(/\s+/, $f[6])],
          'distfiles'	=> {},
          'latest'	=> isLatest($name, $base),
          'name'	=> $name,
          'rdeps'	=> [split(/\s+/, $f[8])],
          'size'	=> (stat("$pkgDir/All/$name.$pkg_ext"))[7],
        };

      # debugPrint("adding " . $pkg->{name});
      # die "duplicate package: $name" if ($debug && defined($index{$name}));
        $index{$name} = $pkg;
        $unplaced{$name} = 1;
    }

    close(INDEX);
}

sub _impact($$) {
    my $disc = shift;
    my $name = shift;

  # Return previously calculated value if we have it.
    return $impact{$name} if defined($impact{$name});

    my $pkg   = $index{$name};
    my @rdeps = @{$pkg->{rdeps}};
    my $size  = $pkg->{size};

  # If no dependencies then the impact is the size of this package.
    return $impact{$name} = $size if (!@rdeps);

  # Otherwise the impact is this package's size plus any dependencies
  # that are not already on this disc.
    foreach (@rdeps) {
        $size += $index{$_}->{size} if !defined($discs{$disc}->{pkgs}->{$_});
    }

    return $impact{$name} = $size;
}

sub redoImpact($) {
    my $disc = shift;

  # Reset the impact hashtable.
    %impact = undef;

  # Calculate the impact for each unplaced package.
    foreach $pkg (keys %unplaced) {
        $impact{$pkg} = _impact($disc, $pkg);
    }
}

MAIN: {
    if ($#ARGV != 5) {
        die "$0 <disc_info> <needed_pkgs> <INDEX> <ports_dir> <pkg_dir> <dist_dir>";
    }

    $discInfo      = shift(@ARGV);
    $neededPkgs    = shift(@ARGV);
    $indexFilename = shift(@ARGV);
    $portsDir      = shift(@ARGV);
    $pkgDir        = shift(@ARGV);
    $distDir       = shift(@ARGV);

    readDiscInfo();
    readIndex();
    placeNeeded();

  # bail if any of the discs have overflowed.
    foreach (keys %discs) {
        my $avail = $discs{$_}->{avail};
        die "disc $_ has overflowed: avail = $avail\n" if ($avail < 0);
        print "avail for disc $_ = $avail\n" if ($debug);
    }

    doPackages();
    doDistfiles();

  # Now that we know where everything should go.  Make it so.
    foreach $disc (sort keys %discs) {
        debugPrint("copying packages to $disc ...");
        foreach $name (keys %{$discs{$disc}->{pkgs}}) {
            copyPkg($disc, $name);
        }

        debugPrint("copying distfiles to $disc ...");
        foreach $name (keys %{$discs{$disc}->{distfiles}}) {
            copyDist($disc, $name);
        }
    }

    foreach $disc (sort keys %discs) {
        debugPrint("$disc: avail = " . $discs{$disc}->{avail});
    }
}
