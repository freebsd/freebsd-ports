--- aspects/profiler/lib/rbprof.rb.orig	Tue Jan 29 07:45:45 2002
+++ aspects/profiler/lib/rbprof.rb	Fri Oct  3 18:02:23 2003
@@ -1,5 +1,5 @@
 require 'aspectr'
-require 'trap_method_definitions'
+require 'rbprof/trap_method_definitions'
 
 class Profiler < AspectR::Aspect
   def initialize
