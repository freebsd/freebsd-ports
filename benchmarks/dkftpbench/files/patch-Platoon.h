--- Platoon.h.orig	2002-02-13 05:06:01 UTC
+++ Platoon.h
@@ -1,13 +1,12 @@
 #ifndef Platoon_H
 #define Platoon_H
 #include "robouser.h"
-#include <list.h>
+#include <list>
+#include <cstring>
 
 /* FIXME: 'reasonable' upper bound on number of users CPU can handle */
 #define Platoon_MAXUSERS (1 << 16)
 
-enum robouser_t::state_t;
-
 /**----------------------------------------------------------------------
  Platoon of robousers.
 ----------------------------------------------------------------------*/
@@ -150,7 +149,7 @@ private:
 	robouser_t *m_users[Platoon_MAXUSERS];
 
 	/** List of dead robousers waiting to be reaped */
-	list<robouser_t *> m_deadlist;
+	std::list<robouser_t *> m_deadlist;
 
 	/** Health: count of bytes fetched so far from all files */
 	size_t m_bytesFetched;
