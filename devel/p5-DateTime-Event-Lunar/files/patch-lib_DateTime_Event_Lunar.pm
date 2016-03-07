--- lib/DateTime/Event/Lunar.pm.orig	2007-05-27 15:50:16 UTC
+++ lib/DateTime/Event/Lunar.pm
@@ -11,7 +11,7 @@ use DateTime::Set;
 use DateTime::Util::Calc qw(
     min max search_next moment dt_from_moment mod binary_search
 );
-use DateTime::Util::Astro::Moon qw(MEAN_SYNODIC_MONTH);
+use DateTime::Astro qw(MEAN_SYNODIC_MONTH);
 use Exporter;
 use Math::Round qw(round);
 BEGIN {
@@ -26,7 +26,7 @@ use constant NEW_MOON        => 0;
 use constant FIRST_QUARTER   => 90;
 use constant FULL_MOON       => 180;
 use constant LAST_QUARTER    => 270;
-use constant ZEROTH_NEW_MOON => DateTime::Util::Astro::Moon::nth_new_moon(0);
+use constant ZEROTH_NEW_MOON => DateTime::Astro::nth_new_moon(0);
 
 sub _new
 {
@@ -81,19 +81,19 @@ sub new_moon_before
     my $dt = $args{datetime};
     return $dt if $dt->is_infinite;
 
-    my $phi = DateTime::Util::Astro::Moon::lunar_phase($dt);
+    my $phi = DateTime::Astro::lunar_phase($dt);
     my $n = round( (moment($dt) - moment(ZEROTH_NEW_MOON)) /
         MEAN_SYNODIC_MONTH - $phi / 360 );
 
     my $nm_index = search_next(
         base  => $n,
         check => sub {
-            my $p = DateTime::Util::Astro::Moon::nth_new_moon($_[0]);
+            my $p = DateTime::Astro::nth_new_moon($_[0]);
             $args{on_or_before} ? $p <= $dt : $p < $dt
         },
         next  => sub { $_[0] - 1 }
     );
-    my $rv = DateTime::Util::Astro::Moon::nth_new_moon($nm_index);
+    my $rv = DateTime::Astro::nth_new_moon($nm_index);
     $rv->set_time_zone($dt->time_zone);
     return $rv;
 }
@@ -106,18 +106,18 @@ sub new_moon_after
     my $dt = $args{datetime};
     return $dt if $dt->is_infinite;
 
-    my $phi = DateTime::Util::Astro::Moon::lunar_phase($dt);
+    my $phi = DateTime::Astro::lunar_phase($dt);
     my $n = round( (moment($dt) - moment(ZEROTH_NEW_MOON)) /
         MEAN_SYNODIC_MONTH - $phi / 360 );
 
     my $nm_index = search_next(
         base  => $n,
         check => sub {
-            my $p = DateTime::Util::Astro::Moon::nth_new_moon($_[0]);
+            my $p = DateTime::Astro::nth_new_moon($_[0]);
             $args{on_or_after} ? $p >= $dt : $p > $dt },
         next  => sub { $_[0] + 1 }
     );
-    my $rv = DateTime::Util::Astro::Moon::nth_new_moon($nm_index);
+    my $rv = DateTime::Astro::nth_new_moon($nm_index);
     $rv->set_time_zone($dt->time_zone);
     return $rv;
 }
@@ -136,13 +136,13 @@ sub lunar_phase_before
 
     my $dt_moment = moment($dt);
     my $tau       = $dt_moment - MEAN_SYNODIC_MONTH_FRAG *
-        mod(DateTime::Util::Astro::Moon::lunar_phase($dt) - $phi, 360);
+        mod(DateTime::Astro::lunar_phase($dt) - $phi, 360);
     my $l         = $tau - 2;
     my $u         = min($dt_moment, $tau + 2);
 
     my $moment = binary_search($l, $u,
         sub { abs($_[0] - $_[1]) <= LUNAR_PHASE_DELTA },
-        sub { mod(DateTime::Util::Astro::Moon::lunar_phase(
+        sub { mod(DateTime::Astro::lunar_phase(
             dt_from_moment($_[0])) - $phi, 360) < 180 } );
     my $rv = dt_from_moment($moment);
     $rv->set_time_zone($dt->time_zone);
@@ -156,20 +156,20 @@ sub lunar_phase_after
     my %args = @_; # datetime => $dt, phase => $phase, on_or_after => $boolean
     my($dt, $phi) = ($args{datetime}, $args{phase});
 
-    my $current_phase = DateTime::Util::Astro::Moon::lunar_phase($dt);
+    my $current_phase = DateTime::Astro::lunar_phase($dt);
     return $dt if $dt->is_infinite;
 
     my $dt_moment = moment($dt);
     my $tau     = 
         $dt_moment + MEAN_SYNODIC_MONTH_FRAG *
-        mod($phi - DateTime::Util::Astro::Moon::lunar_phase($dt), 360)
+        mod($phi - DateTime::Astro::lunar_phase($dt), 360)
     ;
     my $l       = max($dt_moment, $tau - 2);
     my $u       = $tau + 2;
 
     my $rv_moment = binary_search($l, $u,
         sub { abs($_[0] - $_[1]) <= LUNAR_PHASE_DELTA },
-        sub { mod(DateTime::Util::Astro::Moon::lunar_phase(
+        sub { mod(DateTime::Astro::lunar_phase(
             dt_from_moment($_[0])) - $phi, 360) < 180 } );
     my $rv = dt_from_moment($rv_moment);
 
@@ -365,7 +365,6 @@ See http://www.perl.com/perl/misc/Artist
 L<DateTime>
 L<DateTime::Set>
 L<DateTime::Span>
-L<DateTime::Util::Astro::Moon>
-L<DateTime::Util::Astro::Sun>
+L<DateTime::Astro>
 
 =cut
