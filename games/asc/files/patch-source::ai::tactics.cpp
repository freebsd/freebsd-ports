
$FreeBSD$

--- source/ai/tactics.cpp	2002/10/18 11:52:01	1.1
+++ source/ai/tactics.cpp	2002/10/18 11:52:50
@@ -330,7 +330,7 @@
          int _dist = beeline ( x, y, veh->xpos, veh->ypos);
 
             // make fields far away a bit unattractive; we don't want to move the whole distance back again next turn
-         int t = int( ait.threat[ veh->aiparam[ getPlayerNum()]->valueType ] * log ( _dist )/log(10) );
+         int t = int( ait.threat[ veh->aiparam[ getPlayerNum()]->valueType ] * log ( (double)_dist )/log((double)10) );
 
          if ( t < threat || ( t == threat && _dist < dist )) {
             threat = t;
