#! /usr/bin/perl -w
# $FreeBSD$
use strict;

unless (defined $ENV{WRKDIRPREFIX} and
	defined $ENV{REALCURDIR} and
	defined $ENV{MKDIR} and
	defined $ENV{LOCALBASE})
{
   die "this script should not be run like that!\n";
}

my $batch = $ENV{BATCH} || 0;

my $makedir = "$ENV{WRKDIRPREFIX}$ENV{REALCURDIR}";
my $makefile = "$makedir/Makefile.inc";
my $mkdircmd = $ENV{MKDIR};
exit if -f $makefile;

my @modules = (
  {
     module => 'ApacheLog',
     check  => 'Apache::Log',
#     file   => '${PERL_ARCH}/Apache/Log.pm',
     port   => 'www/mod_perl',
#     man3   => 'Log::Dispatch::ApacheLog',
  },
  {
     module => 'Email::MIMELite',
     check  => 'MIME::Lite',
     port   => 'mail/p5-MIME-Lite',
  },
  {
     module => 'Email::MailSend',
     check  => 'Mail::Send',
     port   => 'mail/p5-Mail-Tools',
  },
  {
     module => 'Email::MailSendmail',
     check  => 'Mail::Sendmail',
     port   => 'mail/p5-Mail-Sendmail',
  },
  {
     module => 'Mail::Sender',
     check  => 'Mail::Sender',
     port   => 'mail/p5-Mail-Sender',
  },
  {
     module => 'Syslog',
     check  => 'Sys::Syslog',
     port   => 'base perl',
     nodepend=> 1,
  }
);

scan_modules(@modules);
@modules = select_modules(@modules);
generate_makefile_inc(@modules);
exit;

sub generate_makefile_inc
{
   my @modules = @_;

   system("$mkdircmd $makedir");
   open INC, "> $makefile" or die "open: $makefile: $!\n";

   for my $m (@modules) {
      next if $m->{nodepend};
      my $mpath = $m->{found} || "/nonexistent";
      $mpath = varify_hardcoded_paths($mpath);
      my $port = $m->{port};
      print INC "BUILD_DEPENDS+=	$mpath:\${PORTSDIR}/$port\n";
   }
   close INC;
}

sub varify_hardcoded_paths
{
   local ($_) = @_;
   s|(perl5/site_perl/)([\d._]+)/|$1\${PERL_VER}/|;
   s|(perl5/site_perl/\${PERL_VER}/)mach/|$1\${PERL_ARCH}/|;
   s|^$ENV{LOCALBASE}/|\${LOCALBASE}/|;
   $_;
}

sub got_module
{
   my ($m) = @_;

   $m =~ s|::|/|g;
   $m .= ".pm";
   for (@INC) {
      my $f = "$_/$m";
      return $f if -r $f;
   }
   return 0;
}

sub scan_modules
{
   my @modules = @_;
   for my $module (@modules) {
      $module->{found} = got_module($module->{check});
   }
}

sub select_modules
{
   my @modules = @_;
   my @selected;
   if ($batch) {
      @selected = batch_select(@_);
   } else {
      @selected = ask_user(@_);
   }
   my @mod;
   my %modules = map { $_->{module} => $_ } @modules;
   for my $module (@selected) {
      push @mod, $modules{$module} if exists $modules{$module};
   }
   @mod;
}

sub batch_select
{
   my @modules = @_;
   my @selected;
   for my $module (@modules) {
      push @selected, $module->{module} if $module->{found};
   }
   @selected;
}

sub ask_user
{
   my @modules = @_;
   my @dlg;
   push @dlg, "/usr/bin/dialog";
   push @dlg, "--title", "Log::Dispatch configuration";
   push @dlg, "--clear", "--checklist", <<EOF;
Log::Dispatch distribution provides several predefined output objects.
Select output objects you will likely need.  Those output objects for
which no extra software packages need to be installed are preselected.

  Please choose options by pressing SPACE to TOGGLE on option ON/OFF
EOF
   push @dlg, -1, -1, 9;
   for my $module (@modules) {
      push @dlg, $module->{module}, "requires $module->{check}" .
	 ($module->{found} ? " (already installed)" : ""),
         ($module->{found} ? "ON" : "OFF");
   }

   my @selected;

   my $pid = open(RESULT, "-|");
   if ($pid) {
      # parent
      my $r = "";
      while (<RESULT>) {
	 $r .= $_;
      }
      close(RESULT) or die "dialog(1) exited with non-zero return code\n";
      $r =~ s/"//g;
      $r =~ s/\s+/ /g;
      @selected = split ' ', $r;
   } elsif (defined $pid) {
      # child
      open XCHG, ">& STDOUT" or die "dup: $!\n";
      open STDOUT, ">& STDERR" or die "dup: $!\n";
      open STDERR, ">& XCHG" or die "dup: $!\n";
      close XCHG if fileno(XCHG) > 2;
      exec @dlg or die "cannot exec: $!\n";
   } else {
      die "cannot fork: $!\n";
   }

   return @selected;
}
