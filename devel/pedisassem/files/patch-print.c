--- print.c.bak	Fri Oct 13 09:27:24 2000
+++ print.c	Sat Jun 12 23:42:27 2004
@@ -225,7 +225,7 @@
         case 16: pr1ntf("word");  printCol+=4; break;
         case 32: pr1ntf("dword"); printCol+=5; break;
         case 64: pr1ntf("qword"); printCol+=5; break;
-        default:
+        default: break;
     }
     prefix();
 }
@@ -430,7 +430,7 @@
                      break;
             case 16: print16case();
                      break;
-            default:
+            default: break;
         }
     }
     else 
@@ -449,7 +449,7 @@
                      break;
             case  5: print25case();
                      break;
-            default:
+            default: break;
         }
     }    
 } /* end of nmonicprint() */
