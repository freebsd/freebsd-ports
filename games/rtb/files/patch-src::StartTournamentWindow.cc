--- src/StartTournamentWindow.cc.orig	Tue Sep 21 18:05:42 2004
+++ src/StartTournamentWindow.cc	Tue Sep 21 18:06:01 2004
@@ -660,7 +660,7 @@
         max_value = 10000;
       else
         {
-          max_value = min( the_opts.get_l( OPTION_MAX_ROBOTS_ALLOWED ),robot_number);
+          max_value = Min( the_opts.get_l( OPTION_MAX_ROBOTS_ALLOWED ),robot_number);
         }
       if(i != 1)
         min_value = 1;
@@ -805,7 +805,7 @@
         max_value = 10000;
       else
         {
-          max_value = min(the_opts.get_l( OPTION_MAX_ROBOTS_ALLOWED ),robot_number);
+          max_value = Min(the_opts.get_l( OPTION_MAX_ROBOTS_ALLOWED ),robot_number);
         }
       if(i != 1)
         min_value = 1;
