--- src/activity/activity.h.orig	Thu Nov 21 12:13:38 2002
+++ src/activity/activity.h	Thu Nov 21 12:13:53 2002
@@ -462,6 +462,7 @@
 #ifndef DEFINED_timeval_t
 #define DEFINED_timeval_t
 
+typedef unsigned long timeval_t;
 //T: Values of this type are used as keys when inserting actions into a
 //T: schedule at a particular time, or for querying the current time value
 //T: of a swarm or schedule during its execution.  (The shorter name time_t
@@ -478,7 +479,6 @@
 //T: a containing schedule or swarm.  (.. Currently, all this extended time
 //T: unit support is unsupported, though there is an example of scheduling
 //T: at subunit times in a GridTurtle test program.)
-typedef unsigned long timeval_t;
 #endif
 
 
