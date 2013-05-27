--- ytnef.c.orig	2004-08-26 19:09:05.000000000 +0200
+++ ytnef.c	2013-05-27 14:30:52.142061290 +0200
@@ -426,6 +426,13 @@ void TNEFFillMapi(TNEFStruct *TNEF, BYTE
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
@@ -455,6 +462,8 @@ void TNEFFillMapi(TNEFStruct *TNEF, BYTE
                 memcpy(vl->data, &temp_ddword, vl->size);
                 d+=8;
                 break;
+           default:
+               fprintf(stderr, "%s: Fatal BUG: unknown MAPI ID type (%u), (%u)\n", __func__, PROP_TYPE(mp->id), mp->id);
         }
         if (count == (mp->count-1)) {
             count = -1;
@@ -565,7 +574,7 @@ void TNEFPrintDate(dtr Date) {
 int TNEFHexBreakdown STD_ARGLIST {
     int i;
     if (TNEF->Debug == 0) 
-        return;
+        return 0;
 
     printf("%s: [%i bytes] \n", TNEFList[id].name, size);
 
@@ -574,13 +583,14 @@ int TNEFHexBreakdown STD_ARGLIST {
         if ((i+1)%16 == 0) printf("\n");
     }
     printf("\n");
+    return 0;
 }
     
 // -----------------------------------------------------------------------------
 int TNEFDetailedPrint STD_ARGLIST {
     int i;
     if (TNEF->Debug == 0) 
-        return;
+        return 0;
 
     printf("%s: [%i bytes] \n", TNEFList[id].name, size);
 
@@ -588,6 +598,7 @@ int TNEFDetailedPrint STD_ARGLIST {
         printf("%c", data[i]);
     }
     printf("\n");
+    return 0;
 }
 
 // -----------------------------------------------------------------------------
