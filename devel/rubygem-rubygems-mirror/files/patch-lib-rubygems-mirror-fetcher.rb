Obtained from:	https://github.com/rubygems/rubygems-mirror/commit/292a6b283b5ea96c20ed30b27526def4b142a866

--- lib/rubygems/mirror/fetcher.rb.orig	2018-06-02 12:50:03 UTC
+++ lib/rubygems/mirror/fetcher.rb
@@ -6,7 +6,14 @@ class Gem::Mirror::Fetcher
   class Error < StandardError; end
 
   def initialize(opts = {})
-    @http = Net::HTTP::Persistent.new(self.class.name, :ENV)
+    @http = 
+      if defined?(Net::HTTP::Persistent::DEFAULT_POOL_SIZE)
+        Net::HTTP::Persistent.new(name: self.class.name, proxy: :ENV)
+      else
+        # net-http-persistent < 3.0
+        Net::HTTP::Persistent.new(self.class.name, :ENV)
+      end
+
     @opts = opts
 
     # default opts
