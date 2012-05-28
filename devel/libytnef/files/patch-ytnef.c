--- ./ytnef.c.orig	2004-08-26 13:09:05.000000000 -0400
+++ ./ytnef.c	2012-05-28 14:33:34.000000000 -0400
@@ -426,6 +426,13 @@
                 d += num + ((num % 4) ? (4 - num%4) : 0);
                 break;
 
+            case PT_CLSID:
+               vl->size = 16; /* Size of struct GUID */
+                vl->data = calloc(vl->size, sizeof(WORD));
+                memcpy(vl->data, &d, vl->size);
+               d += 16; /* Size of struct GUID */
+               break;
+
             case PT_I2:
                 // Read in 2 bytes, but proceed by 4 bytes
                 vl->size = 2;
@@ -455,6 +462,8 @@
                 memcpy(vl->data, &temp_ddword, vl->size);
                 d+=8;
                 break;
+           default:
+               fprintf(stderr, "%s: Fatal BUG: unknown MAPI ID type (%u), (%u)\n", __func__, PROP_TYPE(mp->id), mp->id);
         }
         if (count == (mp->count-1)) {
             count = -1;
