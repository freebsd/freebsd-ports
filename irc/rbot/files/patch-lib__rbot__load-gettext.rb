commit 3342d4b9a510655d320590f7333f616355d0201d
Author: Giuseppe Bilotta <giuseppe.bilotta@gmail.com>
Date:   Sat Jul 14 13:24:33 2012 +0200

    Update gettext support
    
    Somewhere along the line between 2.0.0 and 2.2.1 gettext switched from
    locale to lang for the hash key name. Support both.

diff --git lib/rbot/load-gettext.rb lib/rbot/load-gettext.rb
index ba9b09b..252e1e3 100644
--- lib/rbot/load-gettext.rb
+++ lib/rbot/load-gettext.rb
@@ -29,7 +29,11 @@ class ::Array
 
   include GetText
 
-  rbot_locale_path = File.join(Irc::Bot::Config.datadir, "../locale/%{locale}/LC_MESSAGES/%{name}.mo")
+  rbot_locale_path = File.join(Irc::Bot::Config.datadir,
+    gettext_version < [2, 2, 0] ?
+      "../locale/%{locale}/LC_MESSAGES/%{name}.mo" :
+      "../locale/%{lang}/LC_MESSAGES/%{name}.mo")
+
   if gettext_version < [2, 0, 0]
     add_default_locale_path(rbot_locale_path)
   else
