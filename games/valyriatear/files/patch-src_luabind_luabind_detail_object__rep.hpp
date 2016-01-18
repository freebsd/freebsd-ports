--- src/luabind/luabind/detail/object_rep.hpp.orig	2013-09-24 11:33:12 UTC
+++ src/luabind/luabind/detail/object_rep.hpp
@@ -29,6 +29,8 @@
 #include <luabind/detail/instance_holder.hpp>
 #include <luabind/detail/ref.hpp>
 
+#include <cstdlib>
+
 namespace luabind { namespace detail
 {
 	class class_rep;
