#!/usr/bin/perl -w
#
# Copyright (c) 2004 Oliver Eikemeier. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# 1. Redistributions of source code must retain the above copyright notice
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# 3. Neither the name of the author nor the names of its contributors may be
#    used to endorse or promote products derived from this software without
#    specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
# INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# $FreeBSD$
#
# MAINTAINER=   eik@FreeBSD.org
#

require 5.005;
use strict;
use Getopt::Std;

my $pkgname;

my %description;
my %values;
my @order;
my @section;
my %haswithout;
my %hasoverride;
my %default;
my %value;
my $isoverride;
my $isedit;

sub parsemaster {
    my $currdesc;
    my ($master) = @_;

    -r $master
      or return 1;

    open MASTER, "<$master"
      or die "Can't read $master: $!\n";

    push @section, "Configurable options for $pkgname";
    push @order, $#section;
    $description{0} = [];

    while(<MASTER>) {
        chomp;
        last if /^##/;
        next if /^#?\s*$/;
        if (/^#!\s*(.*)$/) {
            if ($1 =~ /MAIN/i) {
                $currdesc = \@{$description{0}};
            }
            else {
                push @section, $1;
                $currdesc = \@{$description{$#section}};
                push @order, $#section;
            }
        }
        elsif(/^#WITH(OUT)?_([A-Z][A-Z0-9_]*)(?:=\s*(.*))?$/) {
            my ($without, $name, $val) = ($1, $2, $3);
            if (defined $values{$name}) {
                print STDERR ">> $pkgname: Duplicate parameter $name at $master line $.: $_.\n";
                next;
            }
            if (defined $val) {
                my @v;
                foreach my $r (split /,\s*/, $val) {
                    $r =~ s/\s+$//;
                    if (length $r > 0) {
                        push @v, $r;
                        $haswithout{$name} = 1
                          if $r =~ /^(?:no|none|off|false)$/i;
                    }
                }
                if ($#v == -1 || $#v == 0 && $v[0] =~ /^auto$/i) {
                    push @v, qw(yes no);
                    $haswithout{$name} = 1;
                }
                $values{$name} = \@v;
                $default{$name} = defined $without && $haswithout{$name} ? 'no' : $values{$name}->[0];
            }
            else {
                @{$values{$name}} = qw(yes no);
                $haswithout{$name} = 1;
                $default{$name} = defined $without ? 'no' : 'yes';
            }
            $currdesc = \@{$description{$name}};
            push @order, $name;
        }
        elsif (/^# (.*)$/) {
            push @{$currdesc}, $1
              if defined $currdesc;
        }
        elsif (/^##$/) {
            last;
        }
        else {
            print STDERR ">> $pkgname: Parse error at $master line $.: $_.\n"
        }
    }
    close MASTER;
}

sub parseoverride {
    my $currdesc;
    my ($override) = @_;

    -r $override
      or return 1;

    open OVERRIDE, "<$override"
      or die "Can't read $override: $!\n";

    while(<OVERRIDE>) {
        chomp;
        last if /^##/;
        next if /^#?\s*$/;
        next if /^#\s*\$FreeBSD/;
        if (/^#!/) {
            undef $currdesc;
        }
        elsif(/^#WITH(OUT)?_([A-Z][A-Z0-9_]*)(?:=\s*(.*))?$/) {
            my ($without, $name, $val) = ($1, $2, $3);
            if (!defined $values{$name}) {
                print STDERR ">> $pkgname: Override parameter $name not in master file.\n";
                next;
            }
            if (defined $val) {
                my @v;
                foreach my $r (split /,\s*/, $val) {
                    $r =~ s/\s+$//;
                    if (length $r > 0) {
                        push @v, $r;
                        $haswithout{$name} = 1
                          if $r =~ /^(?:no|none|off|false)$/i;
                    }
                }
                if ($#v == -1 || $#v == 0 && $v[0] =~ /^auto$/i) {
                    push @v, qw(yes no);
                    $haswithout{$name} = 1;
                }
                $values{$name} = \@v;
                $default{$name} = defined $without && $haswithout{$name} ? 'no' : $values{$name}->[0];
            }
            else {
                @{$values{$name}} = qw(yes no);
                $haswithout{$name} = 1;
                $default{$name} = defined $without ? 'no' : 'yes';
            }
            delete $description{$name};
            $currdesc = \@{$description{$name}};
            $hasoverride{$name} = 1;
        }
        elsif (/^# (.*)$/) {
            push @{$currdesc}, $1
              if defined $currdesc;
        }
        elsif (/^##$/) {
            last;
        }
        else {
            print STDERR ">> $pkgname: Parse error at $override line $.: $_.\n"
        }
    }
    close OVERRIDE;

    $isoverride = 1;
}

sub parseoptions {
    my ($options) = @_;
    -r $options
      or return 1;
    open OPTIONS, "<$options"
      or die "Can't open $options: $!\n";
    while (<OPTIONS>) {
      chomp;
      next if /^(:?#|\s*$)/;
      next if /^_OPTIONS/;
      next if /^\./;
      if (/^WITH(OUT)?_([A-Z][A-Z0-9_]*)\??=(.*)$/) {
          my ($without, $name, $val) = ($1, $2, $3);
          next if !defined $values{$name};
          next if defined $value{$name};
          if (defined $without) {
              $value{$name} = 'no';
          }
          else {
              $value{$name} = $val;
          }
      }
      else {
          print STDERR ">> $pkgname: Parse error at $options line $.: $_\n";
      }
    }
}

sub parseeditoptions {
    my ($options) = @_;
    -r $options
      or return 1;
    open OPTIONS, "<$options"
      or die "Can't open $options: $!\n";
    while (<OPTIONS>) {
        chomp;
        s/\s*#.*$//;
        next if /^$/;
        if (/^([A-Z][A-Z0-9_]*)\s*=\s*(.*)$/) {
            my ($name, $val) = ($1, $2);
            next if !defined $values{$name};
            next if $#{$values{$name}} == 0 && $values{$name}->[0] =~ /^ignore$/i;
            next if $isoverride && $#{$values{$name}} == 0;
            my $candidate;
            foreach my $c (@{$values{$name}}) {
                if ($c eq '*' || $c eq $val) {
                    $candidate = $val;
                    last;
                }
                elsif (lc $c eq lc $val) {
                    $candidate = $c;
                }
                elsif ($c eq 'yes' && $val =~ /^(?:y|yes|on|t|true)$/i) {
                    $candidate = $c;
                }
                elsif ($c eq 'no' && $val =~ /^(?:n|no|off|f|false)$/i) {
                    $candidate = $c;
                }
            }
            $value{$name} = $candidate
              if defined $candidate;
        }
        else {
            print STDERR ">> $pkgname: Parse error at $options line $.: $_\n";
        }
    }
    $isedit = 1;
}

sub print_editoptions {
    foreach my $name (@order) {
        if ($name =~ /^\d/) {
            my $headline;
            foreach (1..length $section[$name]) {
                $headline .= "#";
            }
            print "##$headline##\n";
            print "# $section[$name] #\n";
            print "##$headline##\n";
            print @{$description{$name}} ? "#\n" : "\n";
        }
        else {
            my $val = $default{$name};
            next if $#{$values{$name}} == 0 && $values{$name}->[0] =~ /^ignore$/i;
            if (defined $value{$name} && !($isoverride && $#{$values{$name}} == 0)) {
                $val = $value{$name};
            }
            print "$name=", $val,
              " # valid values: ", join(", ", @{$values{$name}}), "\n";
        }
        if (@{$description{$name}}) {
            foreach (@{$description{$name}}) {
                if ($_ eq '.') {
                    print "#\n";
                }
                elsif ($_ =~ /^#/) {
                    print "#$_\n";
                }
                else {
                    print "# $_\n";
                }
            }
            print "\n";
        }
    }
}

sub print_dialogoptions {
    foreach my $name (@order) {
        next if $name =~ /^\d/;
        next if !$isedit && $isoverride && !$hasoverride{$name};
        next if !$isedit && $#{$values{$name}} == 0 && $values{$name}->[0] =~ /^ignore$/i;
        my $val = defined $value{$name} ? $value{$name} : $default{$name};
        next if $val ne 'yes' && $val ne 'no';
        $val = $val eq 'yes' ? 'On' : 'Off';
        my $desc = join ' ', @{$description{$name}};
        $desc = "$name support"
          if !$desc;
        $desc =~ s/\. .*//;
        $desc = substr($desc, 0, 38) . '...'
          if length $desc > 41;
        $desc =~ s/["\$]/\\&/g;
        print ' ', $name, ' "', $desc, '" ', $val;
    }
    print "\n";
}

sub print_options {
    print "_OPTIONSNG_READ?=$pkgname\n";
    foreach my $name (@order) {
        next if $name =~ /^\d/;
        next if !$isedit && $isoverride && !$hasoverride{$name};
        next if !$isedit && $#{$values{$name}} == 0 && $values{$name}->[0] =~ /^ignore$/i;
        my $val = defined $value{$name} ? $value{$name} : $default{$name};
        if ($haswithout{$name}) {
            if ($val =~ /^(no|none|off|false)$/i) {
                print ".undef WITH_$name\n"
                    if (!$isedit && $isoverride && $#{$values{$name}} == 0);
                print ".ifndef WITH_$name\n";
                print "WITHOUT_$name?=yes\n";
                print ".endif\n";
            }
            else {
                print ".undef WITHOUT_$name\n"
                    if (!$isedit && $isoverride && $#{$values{$name}} == 0);
                print ".ifndef WITHOUT_$name\n";
                print "WITH_$name?=$val\n";
                print ".endif\n";
            }
        }
        else {
            print "WITH_$name?=$val\n";
        }
    }
}

my %opts;

getopts('p:M:O:g:t:edo', \%opts);

$pkgname = defined $opts{p} ? $opts{p} : "anonyous";

parsemaster $opts{M}
  if defined $opts{M};

parseoverride $opts{O}
  if defined $opts{O};

parseoptions $opts{g}
  if defined $opts{g};

parseeditoptions $opts{t}
  if defined $opts{t};

print_editoptions
  if $opts{e};

print_dialogoptions
  if $opts{d};

print_options
  if $opts{o};
