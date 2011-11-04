--- layout/LookupProcessor.cpp
+++ layout/LookupProcessor.cpp
@@ -201,7 +201,9 @@
 
     if (requiredFeatureIndex != 0xFFFF) {
         requiredFeatureTable = featureListTable->getFeatureTable(requiredFeatureIndex, &requiredFeatureTag);
-        featureReferences += SWAPW(featureTable->lookupCount);
+	if (requiredFeatureTable) {
+	        featureReferences += SWAPW(requiredFeatureTable->lookupCount);
+	}
     }
 
     lookupOrderArray = LE_NEW_ARRAY(le_uint16, featureReferences);
