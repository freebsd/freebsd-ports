creature/Uniquem.cpp:628:11: error: cannot initialize return object of type 'int' with an rvalue of
      type 'nullptr_t'
                        return NULL;
                               ^~~~
/usr/include/sys/_null.h:37:14: note: expanded from macro 'NULL'
#define NULL    nullptr
                ^~~~~~~

--- creature/Uniquem.cpp.orig	2003-12-10 07:03:57 UTC
+++ creature/Uniquem.cpp
@@ -625,7 +625,7 @@ int XYohjishiro::onGiveItem(XCreature * giver, XItem *
 					(*it)->Item()->Identify(1);
 					
 			}
-			return NULL;
+			return 0;
 		} else
 		{
 			char tbuf[256];
