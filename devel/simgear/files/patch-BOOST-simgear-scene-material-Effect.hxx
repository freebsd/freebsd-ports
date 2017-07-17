--- simgear/scene/material/Effect.hxx.orig	2017-04-04 09:24:44.000000000 +0200
+++ simgear/scene/material/Effect.hxx	2017-07-16 21:55:33.247324000 +0200
@@ -19,7 +19,7 @@
 
 #include <vector>
 #include <string>
-#include <boost/tr1/unordered_map.hpp>
+#include <unordered_map>
 
 #include <boost/functional/hash.hpp>
 
@@ -127,7 +127,7 @@
             bool operator()(const Key& lhs, const Key& rhs) const;
         };
     };
-    typedef std::tr1::unordered_map<Key, osg::observer_ptr<Effect>,
+    typedef std::unordered_map<Key, osg::observer_ptr<Effect>,
                                     boost::hash<Key>, Key::EqualTo> Cache;
     Cache* getCache()
     {
