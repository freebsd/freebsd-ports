--- scripts/simple_phaser.py.orig	2021-01-23 17:25:56 UTC
+++ scripts/simple_phaser.py
@@ -108,7 +108,7 @@ class SimplePhaser:
         return informativeHets, informativeCoords, informativeIndexes
     
     def getRefPairedAllele(self, anchorIndex, pairedIndex):
-#         print "\t".join([str(anchorIndex), str(pairedIndex - anchorIndex  - 1), str(len(self.ldMap.dVals)),str(len(self.ldMap.dVals[anchorIndex]))]) # prints intermarker counts
+#         print("\t".join([str(anchorIndex), str(pairedIndex - anchorIndex  - 1), str(len(self.ldMap.dVals)),str(len(self.ldMap.dVals[anchorIndex]))]) # prints intermarker counts)
         if (pairedIndex - anchorIndex - 1) >= len(self.ldMap.dVals[anchorIndex]):
             pRef = random.uniform(0,1)
             if pRef > 0.5:
@@ -166,8 +166,8 @@ class SimplePhaser:
                 altHap = temp 
             
             if pairedAllele not in [ref,alt]:
-                print "pairedAllele not ref or alt " + ref + " " + alt
-                print pairedAllele               
+                print("pairedAllele not ref or alt " + ref + " " + alt)
+                print(pairedAllele)
          
         return phasedAlleles, informativeCoords
             
@@ -182,7 +182,7 @@ class SimplePhaser:
             elif candidateHap[i].upper() == phasedHaps[1][i].upper():
                 currentMatch = 1
             else:
-                print "ERROR: " + candidateHap[i] + " does not match " + phasedHaps[0][i] + " or " + phasedHaps[1][i] + "\t" + self.ldMap.coords[i] + "\t" + self.ldMap.refs[i] + "\t" + self.ldMap.alts[i]
+                print("ERROR: " + candidateHap[i] + " does not match " + phasedHaps[0][i] + " or " + phasedHaps[1][i] + "\t" + self.ldMap.coords[i] + "\t" + self.ldMap.refs[i] + "\t" + self.ldMap.alts[i])
 #                 # randomly assign match
 #                 p0 = random.uniform(0,1)
 #                 if p0 > 0.5:
