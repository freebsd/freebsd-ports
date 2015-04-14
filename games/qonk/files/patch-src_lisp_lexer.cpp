--- src/lisp/lexer.cpp.orig	2007-09-14 09:43:03.000000000 +0400
+++ src/lisp/lexer.cpp	2015-03-27 02:52:52.633169000 +0300
@@ -19,6 +19,8 @@
 //  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 #include <sstream>
 #include <stdexcept>
+#include <cstring>
+#include <cstdio>
 
 #include "lexer.hpp"
 #include "translation.hpp"
