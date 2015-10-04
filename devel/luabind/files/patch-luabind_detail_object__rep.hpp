In file included from luabind/detail/policy.hpp:51:0,
                 from luabind/detail/convert_to_lua.hpp:28,
                 from luabind/detail/call_member.hpp:30,
                 from luabind/wrapper_base.hpp:31,
                 from luabind/back_reference.hpp:27,
                 from luabind/class.hpp:93,
                 from luabind/luabind.hpp:28,
luabind/detail/object_rep.hpp: In member function 'void* luabind::detail::object_rep::allocate(size_t)':
luabind/detail/object_rep.hpp:77:11: error: 'malloc' is not a member of 'std'
    return std::malloc(size);
           ^
--- luabind/detail/object_rep.hpp.orig	2010-08-31 13:24:52 UTC
+++ luabind/detail/object_rep.hpp
@@ -24,6 +24,7 @@
 #ifndef LUABIND_OBJECT_REP_HPP_INCLUDED
 #define LUABIND_OBJECT_REP_HPP_INCLUDED
 
+#include <cstdlib> // for -DNDEBUG with libc++
 #include <boost/aligned_storage.hpp>
 #include <luabind/config.hpp>
 #include <luabind/detail/instance_holder.hpp>
