# 1.4
Index: qemu/hw/usb.c
@@ -183,7 +183,7 @@
 
     q = buf;
     len = strlen(str);
-    *q++ = 2 * len + 1;
+    *q++ = 2 * len + 2;
     *q++ = 3;
     for(i = 0; i < len; i++) {
         *q++ = str[i];
