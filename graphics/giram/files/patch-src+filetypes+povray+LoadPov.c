--- src/filetypes/povray/LoadPov.c.orig	Mon Dec 23 18:06:14 2002
+++ src/filetypes/povray/LoadPov.c	Tue Oct 26 17:04:03 2004
@@ -1152,6 +1152,7 @@
         break;
       default:
        /* panic!!! */
+	;
     }
     get_token();
   }
@@ -3238,6 +3239,7 @@
 
           default:
             /*Error("Mis-matched '#case' or '#range'.");*/
+	    ;
         }
         done = TRUE;
         break;
@@ -3303,6 +3305,7 @@
 
           default:
 /*            Error("Mis-matched '#end'.");*/
+	    ;
         }
         done = TRUE;
         break;
@@ -4965,6 +4968,7 @@
         break;
       default:
         /* panic!!! */
+	;
     }
     get_token();
   }
@@ -5111,6 +5115,7 @@
       PARSE_FLOAT(HoleRadius)
       break;
     default: /* nothing */
+      ;
   }
 
   *pDisc = giram_disc_new(Center, Normal, Radius, HoleRadius);
