--- cont.c.orig	2013-10-09 15:37:54.000000000 +0000
+++ cont.c	2013-11-22 15:05:19.138396780 +0000
@@ -44,6 +44,8 @@
 /* At least, Linux/ia64's getcontext(3) doesn't save register window.
  */
 #     define FIBER_USE_NATIVE 0
+#   elif defined(__FreeBSD__)
+#     define FIBER_USE_NATIVE 0
 #   elif defined(__GNU__)
 /* GNU/Hurd doesn't fully support getcontext, setcontext, makecontext
  * and swapcontext functions. Disabling their usage till support is
