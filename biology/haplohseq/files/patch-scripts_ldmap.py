--- scripts/ldmap.py.orig	2021-01-23 17:32:15 UTC
+++ scripts/ldmap.py
@@ -29,10 +29,10 @@ class MapMaker:
     coordinates of the haplotype marker genomic positions.
     '''
     def __init__(self, markerFilename, haplotypesFilename):
-        print "reading haplotype base coordinates ...."
+        print("reading haplotype base coordinates ....")
         self.coords, self.coordIndexes, self.refs, self.alts = self.readMarkers(markerFilename)
 #         self.haplotypes = self.readHaplotypes(haplotypesFilename)
-        print "reading haplotype panel ...."
+        print("reading haplotype panel ....")
         self.markerCalls = self.readHaplotypes(haplotypesFilename, transpose = True)
     
     # reads from a vcf file of defined positions representing the haplotype data    
@@ -118,7 +118,7 @@ class MapMaker:
         # 1) COLLECT MARGINALS AND IDENTIFY SITES THAT ARE POLYMORPHIC
         # If a site has only one allele in the haplotype panel it is not informative, so it won't be used
         # in LD calculations.  We may want to consider setting some minimum threshold for a minor allele frequency.
-        print "collecting marginal allele counts and identifying polymorphic sites from haplotype panel ...."
+        print("collecting marginal allele counts and identifying polymorphic sites from haplotype panel ....")
         for index in range(0,len(self.markerCalls)):
             ref = self.refs[index]
             alt = self.alts[index]
@@ -152,7 +152,7 @@ class MapMaker:
         log.write("Num non-polymorphic sites: " + str(numNonpolymorphicSites) + "\n")
                
         # 2) CALCULATE D FOR POLYMORPHIC SITES COMPARED WITH N SITES TO THE RIGHT THAT ARE POLYMORPHIC
-        print "calculating D between polymorphic sites and their neighbors ...."
+        print("calculating D between polymorphic sites and their neighbors ....")
         dVals = []
         for i in range(0, len(polymorphicIndexes)):   # the last coordinate won't have any partners
             index_i = polymorphicIndexes[i]
@@ -244,7 +244,7 @@ class LDMap:
         return ldMap
         
     def save(self, filename):
-        print "saving ldmap to " + filename
+        print("saving ldmap to " + filename)
         ldMapFile = open(filename, 'w')
         ldMapFile.write("\t".join(["COORD","REF","ALT","PAIRED_ALLELES"]) + "\n")
         for i in range(0,len(self.coords)):
