
$FreeBSD$

--- source/gamedlg.cpp	2001/02/17 16:01:39	1.1
+++ source/gamedlg.cpp	2001/02/17 16:06:51
@@ -1233,7 +1233,7 @@
               displaymessage("no human players found !", 1 );
               delete actmap;
               actmap = NULL;
-              throw NoMapLoaded();
+              goto except1;
            }
          } while ( actmap->player[actmap->actplayer].stat != ps_human ); /* enddo */
 
@@ -1242,26 +1242,29 @@
    catch ( InvalidID err ) {
       displaymessage( err.getMessage().c_str(), 1 );
       if ( !actmap || actmap->xsize <= 0)
-         throw NoMapLoaded();
+         goto except1;
    } /* endcatch */
    catch ( tinvalidversion err ) {
       displaymessage( "File %s has invalid version.\nExpected version %d\nFound version %d\n", 1, err.filename, err.expected, err.found );
       if ( !actmap || actmap->xsize <= 0)
-         throw NoMapLoaded();
+         goto except1;
    } /* endcatch */
    catch ( tfileerror err) {
       displaymessage( "error reading map filename %s ", 1, err.filename );
       if ( !actmap || actmap->xsize <= 0)
-         throw NoMapLoaded();
+         goto except1;
    } /* endcatch */
    catch ( ASCexception ) {
       displaymessage( "error loading map", 1 );
       if ( !actmap || actmap->xsize <= 0)
-         throw NoMapLoaded();
+         goto except1;
    } /* endcatch */
 
    removemessage();
+   return;
 
+except1:
+   throw NoMapLoaded();
 }
 
 
@@ -1722,7 +1725,7 @@
             displaymessage ( "no human players found !", 1 );
             delete actmap;
             actmap = NULL;
-            throw NoMapLoaded();
+            goto except1;
          }
 
          if ( human > 1 )
@@ -1743,7 +1746,7 @@
               displaymessage("no human players found !", 1 );
               delete actmap;
               actmap = NULL;
-              throw NoMapLoaded();
+              goto except1;
            }
          } while ( actmap->player[actmap->actplayer].stat != ps_human ); /* enddo */
 
@@ -1752,25 +1755,29 @@
       catch ( InvalidID err ) {
          displaymessage( err.getMessage().c_str(), 1 );
          if ( !actmap || actmap->xsize <= 0)
-            throw NoMapLoaded();
+            goto except1;
       } /* endcatch */
       catch ( tinvalidversion err ) {
          displaymessage( "File %s has invalid version.\nExpected version %d\nFound version %d\n", 1, err.filename, err.expected, err.found );
          if ( !actmap || actmap->xsize <= 0)
-            throw NoMapLoaded();
+            goto except1;
       } /* endcatch */
       catch ( tfileerror err) {
          displaymessage( "error reading map filename %s ", 1, err.filename );
          if ( !actmap || actmap->xsize <= 0)
-            throw NoMapLoaded();
+            goto except1;
       } /* endcatch */
       catch ( ASCexception ) {
          displaymessage( "error loading map", 1 );
          if ( !actmap || actmap->xsize <= 0)
-            throw NoMapLoaded();
+            goto except1;
       } /* endcatch */
 
    } 
+   return;
+
+except1:
+   throw NoMapLoaded();
 } 
 
 
