--- lib/forks.pm.orig	2014-06-27 02:47:00 UTC
+++ lib/forks.pm
@@ -1567,8 +1567,8 @@ sub _server {
     
 # Localize Storable variables to allow CODE refs, if using Storable >= 2.05
 
-    local $Storable::Deparse = 1 if $Storable::VERSION >= 2.05;
-    local $Storable::Eval = 1 if $Storable::VERSION >= 2.05;
+    local $Storable::Deparse = 1 if eval { Storable->VERSION('2.05') };
+    local $Storable::Eval = 1 if eval { Storable->VERSION('2.05') };
 
 # Initialize the number of polls
 # While we're running in the main dispatch loop
