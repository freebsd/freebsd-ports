--- src/lua_sysctl.c.orig	2011-12-05 09:47:49.000000000 +0900
+++ src/lua_sysctl.c	2011-12-05 09:57:48.000000000 +0900
@@ -257,6 +257,7 @@
     long longval;
     unsigned long ulongval;
     quad_t quadval;
+    u_quad_t uquadval;
     size_t s, newsize = 0;
     u_int kind;
     char fmt[BUFSIZ], key[BUFSIZ], nvalbuf[BUFSIZ];
@@ -293,7 +294,8 @@
             (kind & CTLTYPE) == CTLTYPE_UINT ||
             (kind & CTLTYPE) == CTLTYPE_LONG ||
             (kind & CTLTYPE) == CTLTYPE_ULONG ||
-            (kind & CTLTYPE) == CTLTYPE_QUAD) {
+            (kind & CTLTYPE) == CTLTYPE_S64 ||
+            (kind & CTLTYPE) == CTLTYPE_U64) {
         if (strlen(newval) == 0)
             return (luaL_error(L, "empty numeric value"));
     }
@@ -343,7 +345,7 @@
         break;
     case CTLTYPE_STRING:
         break;
-    case CTLTYPE_QUAD:
+    case CTLTYPE_S64:
         quadval = (quad_t)strtonum(newval, LLONG_MIN, LLONG_MAX, &errmsg);
         if (errmsg) {
             return (luaL_error(L, "bad quad_t integer: %s (%s)",
@@ -352,6 +354,15 @@
         newval = &quadval;
         newsize = sizeof(quadval);
         break;
+    case CTLTYPE_U64:
+        uquadval = (u_quad_t)strtonum(newval, 0, ULLONG_MAX, &errmsg);
+        if (errmsg) {
+            return (luaL_error(L, "bad unsigned quad_t integer: %s (%s)",
+                        (char *)newval, errmsg));
+        }
+        newval = &uquadval;
+        newsize = sizeof(uquadval);
+        break;
     case CTLTYPE_OPAQUE:
         if (strcmp(fmt, "T,dev_t") == 0) {
             set_T_dev_t(L, newval, &newval, &newsize);
