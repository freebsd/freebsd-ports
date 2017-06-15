--- src/luabind/luabind/detail/object_rep.hpp.orig	2010-01-03 23:08:15 UTC
+++ src/luabind/luabind/detail/object_rep.hpp
@@ -29,6 +29,8 @@
 #include <luabind/detail/instance_holder.hpp>
 #include <luabind/detail/ref.hpp>
 
+#include <cstdlib>
+
 namespace luabind { namespace detail
 {
 	class class_rep;
