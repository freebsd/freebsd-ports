--- main.c.orig	Wed Sep 12 13:00:18 2001
+++ main.c	Sat Jun 12 23:39:59 2004
@@ -2146,7 +2146,7 @@
                 if (getMap(pos)&0x05) orMap(pos, 0x10);
                 /*----------*/popTrace();
             }
-        default:
+        default: break;
     }
     return 1;
 }
@@ -2246,7 +2246,7 @@
             orMap(r, 0xE0);  
             /*-----------*/popTrace();
             break;
-        default:
+        default: break;
     }
 }
 
@@ -2306,7 +2306,7 @@
         switch(i)
         {
             case  8: changeTo80Real(r,rmax);  break;
-            default: 
+            default: break; 
         }
     }
 }
@@ -2970,7 +2970,7 @@
             // the following code is move to above position....^^^^^.....
             //if (ref<pos+4) { eraseUncertain(ref); break; }
 
-            default:
+            default: break;
         }
     }
  //
@@ -3042,7 +3042,7 @@
                           /*-----------*/popTrace();
                      }
                  }
-            default:
+            default: break;
         }
     }
 }
@@ -3217,7 +3217,7 @@
                  }
              }
              break;
-        default:
+        default: break;
     }
     /*-----------*/popTrace();
 }
