engine.cc:539:46: error: non-constant-expression cannot be narrowed from type
      'std::__1::basic_string<char, std::__1::char_traits<char>,
      std::__1::allocator<char> >::size_type' (aka 'unsigned long') to 'int' in
      initializer list [-Wc++11-narrowing]
  datum key   = {(char *)config.key.c_str(), config.key.length()};
                                             ^~~~~~~~~~~~~~~~~~~
engine.cc:539:46: note: insert an explicit cast to silence this issue
  datum key   = {(char *)config.key.c_str(), config.key.length()};
                                             ^~~~~~~~~~~~~~~~~~~
                                             static_cast<int>(  )

--- engine.cc.orig	2018-06-17 15:07:26 UTC
+++ engine.cc
@@ -324,8 +324,8 @@ void Engine::from_input() {
       Dbt d_key((char *)key.c_str(), key.length());
       Dbt d_value((char *)value.c_str(), value.length());
 #else
-      datum d_key = {(char *)key.c_str(), key.length()};
-      datum d_value = {(char *)value.c_str(), value.length()};
+      datum d_key = {(char *)key.c_str(), static_cast<int>(key.length())};
+      datum d_value = {(char *)value.c_str(), static_cast<int>(value.length())};
 #endif
       if(config.force == 1) {
 #ifdef HAVE_BERKELEY
@@ -405,8 +405,8 @@ void Engine::insert() {
   Dbt value(v, strlen(v));
 #else
   int ret;
-  datum key   = {(char *)config.key.c_str(), config.key.length()};
-  datum value = {(char *)__value.c_str(), __value.length()};
+  datum key   = {(char *)config.key.c_str(), static_cast<int>(config.key.length())};
+  datum value = {(char *)__value.c_str(), static_cast<int>(__value.length())};
 #endif
 
   if(config.force == 1) {
@@ -465,8 +465,8 @@ void Engine::update() {
   Dbt value(v, strlen(v));
 #else
   int ret;
-  datum key   = {(char *)config.key.c_str(), config.key.length()};
-  datum value = {(char *)__value.c_str(), __value.length()};
+  datum key   = {(char *)config.key.c_str(), static_cast<int>(config.key.length())};
+  datum value = {(char *)__value.c_str(), static_cast<int>(__value.length())};
 #endif
 
   if(config.force == 1) {
@@ -536,7 +536,7 @@ void Engine::remove() {
   }
   db->close(0);
 #else
-  datum key   = {(char *)config.key.c_str(), config.key.length()};
+  datum key   = {(char *)config.key.c_str(), static_cast<int>(config.key.length())};
   ret = gdbm_delete(db, key);
   gdbm_close(db);
 #endif
@@ -579,7 +579,7 @@ void Engine::select() {
   db->close(0);
 #else
   datum content;
-  datum key   = {(char *)config.key.c_str(), config.key.length()};
+  datum key   = {(char *)config.key.c_str(), static_cast<int>(config.key.length())};
   content = gdbm_fetch(db, key);
   string V(content.dptr, content.dsize);
   if(config.with == 1)
