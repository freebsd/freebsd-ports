--- rs232.c.orig	2014-12-08 14:19:24.000000000 +0800
+++ rs232.c	2014-12-08 14:19:38.000000000 +0800
@@ -107,28 +107,6 @@
                    break;
     case  460800 : baudr = B460800;
                    break;
-    case  500000 : baudr = B500000;
-                   break;
-    case  576000 : baudr = B576000;
-                   break;
-    case  921600 : baudr = B921600;
-                   break;
-    case 1000000 : baudr = B1000000;
-                   break;
-    case 1152000 : baudr = B1152000;
-                   break;
-    case 1500000 : baudr = B1500000;
-                   break;
-    case 2000000 : baudr = B2000000;
-                   break;
-    case 2500000 : baudr = B2500000;
-                   break;
-    case 3000000 : baudr = B3000000;
-                   break;
-    case 3500000 : baudr = B3500000;
-                   break;
-    case 4000000 : baudr = B4000000;
-                   break;
     default      : printf("invalid baudrate\n");
                    return(1);
                    break;
