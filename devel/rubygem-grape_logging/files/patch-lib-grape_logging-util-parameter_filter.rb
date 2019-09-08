--- lib/grape_logging/util/parameter_filter.rb.orig	2019-09-07 15:56:34 UTC
+++ lib/grape_logging/util/parameter_filter.rb
@@ -1,5 +1,5 @@
 if defined?(::Rails.application)
-  class ParameterFilter < ActiveSupport::ParameterFilter
+  class ParameterFilter < ActionDispatch::Http::ParameterFilter
     def initialize(_replacement, filter_parameters)
       super(filter_parameters)
     end
