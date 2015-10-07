--- cont.c.orig	2013-10-09 15:37:54 UTC
+++ cont.c
@@ -44,6 +44,8 @@
 /* At least, Linux/ia64's getcontext(3) doesn't save register window.
  */
 #     define FIBER_USE_NATIVE 0
+#   elif defined(__FreeBSD__)
+#     define FIBER_USE_NATIVE 0
 #   elif defined(__GNU__)
 /* GNU/Hurd doesn't fully support getcontext, setcontext, makecontext
  * and swapcontext functions. Disabling their usage till support is
