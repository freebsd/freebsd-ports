
$FreeBSD$

--- source/ai/valuation.cpp	2002/10/18 11:44:39	1.1
+++ source/ai/valuation.cpp	2002/10/18 11:46:45
@@ -78,7 +78,7 @@
                   for ( int e = (fzt->weapons.weapon[i].mindistance + maxmalq - 1)/ maxmalq; e <= fzt->weapons.weapon[i].maxdistance / maxmalq; e++ ) {    // the distance between two fields is maxmalq
                      d++;
                      int n = int( weapDist.getWeapStrength( &fzt->weapons.weapon[i], e*maxmalq ) * fzt->weapons.weapon[i].maxstrength * af.strength_damage(getdamage()) * ( 1 + af.strength_experience(getexpirience())) );
-                     m += int( n / log10(10*d));
+                     m += int( n / log10((double)10*d));
                   }
                   if (getammunition(i) == 0)
                      m /= 2;
@@ -694,7 +694,7 @@
 
                 int dist = beeline ( veh->xpos, veh->ypos, sec.centerx, sec.centery ) + 3 * veh->maxMovement();
                 if ( dist )
-                   f /= log(dist);
+                   f /= log((double)dist);
 
                 if ( f > d ) {
                    int ac  = 0;
