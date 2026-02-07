Obtained from http://perl-users.jp/articles/advent-calendar/2011/test/11

--- lib/Perl/Metrics/Simple/Analysis/File.pm.orig	2021-03-21 15:14:01 UTC
+++ lib/Perl/Metrics/Simple/Analysis/File.pm
@@ -340,6 +340,7 @@ sub _iterate_over_subs {
             name              => $sub->name,
             lines             => $sub_length,
             mccabe_complexity => $self->measure_complexity($sub),
+            line_number       => $sub->line_number,
             };
     }
     return \@subs;
