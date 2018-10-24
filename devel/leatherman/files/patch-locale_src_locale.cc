--- locale/src/locale.cc.orig	2018-09-29 16:21:31 UTC
+++ locale/src/locale.cc
@@ -44,6 +44,9 @@ namespace leatherman { namespace locale 
             gen.add_messages_domain(domain);
         }
 
+        if (id.empty())
+            return g_locales.insert(make_pair(domain, std::locale())).first->second;
+
         // Ensure creating and adding a new locale is thread-safe.
         try {
             return g_locales.insert(make_pair(domain, gen(id))).first->second;
