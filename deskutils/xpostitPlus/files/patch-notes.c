*** note.c.orig	Wed Dec 20 17:15:34 2000
--- note.c	Wed Dec 20 17:20:15 2000
***************
*** 359,364 ****
--- 359,373 ----
  			}
  		}
  
+                 /*
+                  * The problem is that texth == 0 or textw == 0 causes an ungraceful exit.
+                  * In this case, we set them all to a standard size.
+                  */
+                 if(texth == 0 || textw == 0)
+                 {
+                     texth = 169;
+                     textw = 227;
+                 }
  
  		/*
  		 * Get the index number of this note.
