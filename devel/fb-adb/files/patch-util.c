--- util.c.orig	2015-10-09 22:02:18 UTC
+++ util.c
@@ -1563,3 +1563,9 @@ xregerror(int errcode, const regex_t* pr
     reslist_xfer(rl->parent, rl);
     return (char*) gb.buf;
 }
+
+#ifndef __linux__
+// XXX For GCC 4.4 or older
+__weak_reference(my_unreachable, __builtin_unreachable);
+void my_unreachable() { abort(); }
+#endif
