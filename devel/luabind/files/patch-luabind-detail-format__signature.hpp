commit 3044a9053ac50977684a75c4af42b2bddb853fad
Author: Daniel Wallin <daniel@boostpro.com>
Date:   Mon Oct 11 14:33:23 2010 +0200

    Proper forward declarations for object wrappers. Now builds on clang!

diff --git luabind/detail/format_signature.hpp luabind/detail/format_signature.hpp
index 56e7963..b447bc9 100644
--- luabind/detail/format_signature.hpp
+++ luabind/detail/format_signature.hpp
@@ -13,12 +13,19 @@
 # include <boost/mpl/next.hpp>
 # include <boost/mpl/size.hpp>
 
-namespace luabind {
+namespace luabind { namespace adl
+{
 
-class object;
-class argument;
-template <class Base>
-struct table;
+  class object;
+  class argument;
+  template <class Base>
+  struct table;
+
+} // namespace adl
+
+using adl::object;
+using adl::argument;
+using adl::table;
 
 } // namespace luabind
 
