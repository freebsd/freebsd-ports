--- lib/mkmf.rb.orig	2014-01-02 19:26:11.544779781 +0000
+++ lib/mkmf.rb	2014-01-02 19:27:02.558776514 +0000
@@ -189,21 +189,21 @@
       ]
     elsif $configure_args.has_key?('--vendor')
       dirs = [
-        ['BINDIR',        '$(DESTDIR)$(bindir)'],
-        ['RUBYCOMMONDIR', '$(DESTDIR)$(vendordir)$(target_prefix)'],
-        ['RUBYLIBDIR',    '$(DESTDIR)$(vendorlibdir)$(target_prefix)'],
-        ['RUBYARCHDIR',   '$(DESTDIR)$(vendorarchdir)$(target_prefix)'],
-        ['HDRDIR',        '$(DESTDIR)$(rubyhdrdir)/ruby$(target_prefix)'],
-        ['ARCHHDRDIR',    '$(DESTDIR)$(rubyhdrdir)/$(arch)/ruby$(target_prefix)'],
+        ['BINDIR',        '$(bindir)'],
+        ['RUBYCOMMONDIR', '$(vendordir)$(target_prefix)'],
+        ['RUBYLIBDIR',    '$(vendorlibdir)$(target_prefix)'],
+        ['RUBYARCHDIR',   '$(vendorarchdir)$(target_prefix)'],
+        ['HDRDIR',        '$(rubyhdrdir)/ruby$(target_prefix)'],
+        ['ARCHHDRDIR',    '$(rubyhdrdir)/$(arch)/ruby$(target_prefix)'],
       ]
     else
       dirs = [
-        ['BINDIR',        '$(DESTDIR)$(bindir)'],
-        ['RUBYCOMMONDIR', '$(DESTDIR)$(sitedir)$(target_prefix)'],
-        ['RUBYLIBDIR',    '$(DESTDIR)$(sitelibdir)$(target_prefix)'],
-        ['RUBYARCHDIR',   '$(DESTDIR)$(sitearchdir)$(target_prefix)'],
-        ['HDRDIR',        '$(DESTDIR)$(rubyhdrdir)/ruby$(target_prefix)'],
-        ['ARCHHDRDIR',    '$(DESTDIR)$(rubyhdrdir)/$(arch)/ruby$(target_prefix)'],
+        ['BINDIR',        '$(bindir)'],
+        ['RUBYCOMMONDIR', '$(sitedir)$(target_prefix)'],
+        ['RUBYLIBDIR',    '$(sitelibdir)$(target_prefix)'],
+        ['RUBYARCHDIR',   '$(sitearchdir)$(target_prefix)'],
+        ['HDRDIR',        '$(rubyhdrdir)/ruby$(target_prefix)'],
+        ['ARCHHDRDIR',    '$(rubyhdrdir)/$(arch)/ruby$(target_prefix)'],
       ]
     end
     dirs << ['target_prefix', (target_prefix ? "/#{target_prefix}" : "")]
@@ -1740,7 +1740,6 @@
   end
 
   def with_destdir(dir)
-    return dir unless $extmk
     dir = dir.sub($dest_prefix_pattern, '')
     /\A\$[\(\{]/ =~ dir ? dir : "$(DESTDIR)"+dir
   end
