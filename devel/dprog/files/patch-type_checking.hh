--- type_checking.hh.orig	Mon Apr 21 20:13:54 2003
+++ type_checking.hh	Mon Apr 12 11:11:30 2004
@@ -7,6 +7,7 @@
 #include <set>
 #include <iostream>
 #include <typeinfo>
+#include <cassert>
 
 namespace type_checking {
 
@@ -31,8 +32,8 @@
 	bool operator==(const TypeInfo &other) const
 	{
 	    return (typeid(*this) == typeid(other)
-		  and (strcmp(name(),other.name()) == 0)
-		  and (arity() == other.arity()));
+		  && (strcmp(name(),other.name()) == 0)
+		  && (arity() == other.arity()));
 	}
 	bool operator!=(const TypeInfo &other) const
 	{ return !((*this)==other); }
