--- ef.sh.orig	Wed May  2 21:17:33 2001
+++ ef.sh	Wed May  2 21:17:40 2001
@@ -1,3 +1,3 @@
-#!/bin/bash
+#!/bin/sh
 
 #
@@ -16,5 +16,5 @@
 # Set the environment to load eletric fence.
 (\
-export LD_PRELOAD=libefence.so.0.0;\
+export LD_PRELOAD=libefence.so.0;\
 exec $*;\
 )
