--- aspects/profiler/lib/rbprof.rb.orig	2016-06-20 14:57:12 UTC
+++ aspects/profiler/lib/rbprof.rb
@@ -1,5 +1,5 @@
 require 'aspectr'
-require 'trap_method_definitions'
+require 'rbprof/trap_method_definitions'
 
 class Profiler < AspectR::Aspect
   def initialize
