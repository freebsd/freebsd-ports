
$FreeBSD$

--- source/controls.cpp	2001/02/17 15:52:35	1.1
+++ source/controls.cpp	2001/02/17 15:54:41
@@ -3039,7 +3039,7 @@
         displaymessage("no human players found !", 1 );
         delete actmap;
         actmap = NULL;
-        throw NoMapLoaded();
+        goto except1;
      }
 
    } while ( actmap->player[actmap->actplayer].stat != ps_human ); /* enddo */
@@ -3048,6 +3048,9 @@
 
    if (bb)
      cursor.display();
+
+except1:
+   throw NoMapLoaded();
 }
 
 void initNetworkGame ( void )
