--- mkconfig.rb.orig	2010-09-06 00:14:02.000000000 +0200
+++ mkconfig.rb	2010-09-06 00:13:56.000000000 +0200
@@ -88,7 +88,7 @@
     if /^prefix$/ =~ name
       val = "(TOPDIR || DESTDIR + #{val})"
     end
-    v = "  CONFIG[\"#{name}\"] #{vars[name] ? '<< "\n"' : '='} #{val}\n"
+    v = "  CONFIG[\"#{name}\"] = #{val}\n"
     vars[name] = true
     if fast[name]
       v_fast << v
