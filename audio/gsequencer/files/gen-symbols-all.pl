#!/usr/bin/env perl
# Generate lib*.sym.in files for the BSD build in place of the missing
# upstream gen-symbols-all.pl script.

use strict;
use warnings;
use File::Find;

sub generate {
    my ($outfile, $license, $dirs, $patterns, $extras) = @_;

    open(my $out, '>', $outfile) or die "Cannot open $outfile: $!";

    if (defined $license && -f $license) {
        open(my $lic, '<', $license) or die "Cannot open $license: $!";
        while (<$lic>) { print $out $_; }
        close($lic);
        print $out "\n";
    }

    my @matches;
    find(
        sub {
            return unless -f $_ && /\.h$/;
            open(my $fh, '<', $_) or return;
            while (my $line = <$fh>) {
                next if $line =~ /^\s*#define\b/;
                foreach my $re (@$patterns) {
                    while ($line =~ /$re/g) {
                        push @matches, $1;
                    }
                }
            }
            close($fh);
        },
        @$dirs
    );

    if (defined $extras) {
        push @matches, @$extras;
    }

    print $out join("\n", @matches), "\n";
    close($out);
}

my $re_func = qr/\s(ags_[a-z0-9_]+)\s*\(/;
my $re_marshal = qr/(ags_cclosure_marshal_[a-zA-Z0-9_]+)/;
my $re_widget_marshal = qr/(ags_widget_cclosure_marshal_[a-zA-Z0-9_]+)/;

generate('libags.sym.in', 'license-notice-gnu-gpl-3-0+-sym.txt',
         ['ags/util', 'ags/lib', 'ags/object', 'ags/file'],
         [$re_func, $re_marshal],
         ['ags_application_context']);

generate('libags_thread.sym.in', 'license-notice-gnu-gpl-3-0+-sym.txt',
         ['ags/thread'], [$re_func], undef);

generate('libags_server.sym.in', 'license-notice-gnu-agpl-3-0+-sym.txt',
         ['ags/server'], [$re_func], undef);

generate('libags_audio.sym.in', 'license-notice-gnu-gpl-3-0+-sym.txt',
         ['ags/plugin', 'ags/audio'], [$re_func], undef);

generate('libags_vst.sym.in', 'license-notice-gnu-gpl-3-0+-sym.txt',
         ['ags/vst3-capi'], [$re_func], undef);

generate('libags_gui.sym.in', 'license-notice-gnu-gpl-3-0+-sym.txt',
         ['ags/widget'], [$re_func, $re_widget_marshal], undef);

print "Generated all symbols\n";
