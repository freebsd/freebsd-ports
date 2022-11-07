--- wmgeneral/list.h.orig	2003-04-09 19:48:21 UTC
+++ wmgeneral/list.h
@@ -30,7 +30,7 @@ Boston, MA 02111-1307, USA.  */
 #define __LIST_H_
 
 #if defined(__GNUC__) && !defined(__STRICT_ANSI__)
-# define INLINE inline
+# define INLINE
 #else
 # define INLINE
 #endif
