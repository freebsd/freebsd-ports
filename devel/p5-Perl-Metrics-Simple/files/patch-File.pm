Obtained from http://perl-users.jp/articles/advent-calendar/2011/test/11

--- ./lib/Perl/Metrics/Simple/Analysis/File.pm.orig	2011-12-31 17:19:26.800034766 +0900
+++ ./lib/Perl/Metrics/Simple/Analysis/File.pm	2011-12-31 17:20:16.967169838 +0900
@@ -327,6 +327,7 @@
             name              => $sub->name,
             lines             => $sub_length,
             mccabe_complexity => $self->measure_complexity($sub),
+            line_number       => $sub->line_number,
             };
     }
     return \@subs;
