--- src/prelude.h.bak	Wed Mar  5 19:21:27 2003
+++ src/prelude.h	Wed Mar  5 19:21:50 2003
@@ -103,8 +103,8 @@
 #define HAS_FLOATS	(REGULAR_HUGS | LARGE_HUGS | BREAK_FLOATS)
 
 #define OBJ		1 /* Object-oriented extensions                    */
-#define O_TK            1 /* Tcl/Tk extension (needs OBJ)                  */
-#define O_TIX           1 /* Tix extension (needs O_TK)                    */
+#define O_TK            0 /* Tcl/Tk extension (needs OBJ)                  */
+#define O_TIX           0 /* Tix extension (needs O_TK)                    */
 #define O_IP		1 /* TCP/UDP/IP support (needs OBJ)		   */
 #define HASKELL_ARRAYS	1
 #define FLAT_ARRAYS	0 /* Warning: Setting 1 is not currently supported */
