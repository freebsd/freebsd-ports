
$FreeBSD$

--- source/ai/misc.cpp	2002/10/18 11:37:58	1.1
+++ source/ai/misc.cpp	2002/10/18 11:41:35
@@ -86,7 +86,7 @@
 
          float value = veh->aiparam[getPlayerNum()]->getValue();
          if ( veh->typ->movement[j] )
-            value *=  log( veh->typ->movement[j] );
+            value *=  log( (double)veh->typ->movement[j] );
 
          float threat = sec.avgFieldThreat.threat[ veh->aiparam[getPlayerNum()]->valueType ];
          if ( minAvgFieldThreat > 0 ) {
@@ -834,7 +834,7 @@
                   danger = enemyThreat.threat[ typ->aiparam[getPlayerNum()]->valueType] / typ->aiparam[getPlayerNum()]->getValue();
             }
 
-            rating /= 1 + log ( danger );
+            rating /= 1 + log ( (double)danger );
 
             int cost = 0;
             for ( int j = 0; j < resourceTypeNum; j++ )
