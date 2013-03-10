--- IndexSearch/SherlockParser.cpp.orig	2012-04-08 10:39:34.000000000 +0200
+++ IndexSearch/SherlockParser.cpp	2013-03-10 17:03:22.000000000 +0100
@@ -21,10 +21,17 @@
 #include <set>
 #include <iostream>
 #include <cstring>
-#include <boost/spirit/core.hpp>
-#include <boost/spirit/actor/push_back_actor.hpp>
-#include <boost/spirit/actor/insert_at_actor.hpp>
-#include <boost/spirit/utility/confix.hpp>
+#ifdef HAVE_BOOST_SPIRIT_CORE_HPP
+#  include <boost/spirit/core.hpp>
+#  include <boost/spirit/actor/push_back_actor.hpp>
+#  include <boost/spirit/actor/insert_at_actor.hpp>
+#  include <boost/spirit/utility/confix.hpp>
+#else
+#  include <boost/spirit.hpp>
+#  include <boost/spirit/home/classic/actor/push_back_actor.hpp>
+#  include <boost/spirit/home/classic/actor/insert_at_actor.hpp>
+#  include <boost/spirit/home/classic/utility/confix.hpp>
+#endif
 
 #include "StringManip.h"
 #include "Url.h"
