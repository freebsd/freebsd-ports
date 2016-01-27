--- apps/essimporter/convertinventory.cpp.orig	2016-01-12 16:11:28 UTC
+++ apps/essimporter/convertinventory.cpp
@@ -1,6 +1,7 @@
 #include "convertinventory.hpp"
 
 #include <components/misc/stringops.hpp>
+#include <cstdlib>
 
 namespace ESSImport
 {
@@ -15,8 +16,8 @@ namespace ESSImport
             objstate.blank();
             objstate.mRef = *it;
             objstate.mRef.mRefID = Misc::StringUtils::lowerCase(it->mId);
-            objstate.mCount = std::abs(it->mCount); // restocking items have negative count in the savefile
-                                                    // openmw handles them differently, so no need to set any flags
+            objstate.mCount = abs(it->mCount); // restocking items have negative count in the savefile
+                                               // openmw handles them differently, so no need to set any flags
             state.mItems.push_back(objstate);
             if (it->mRelativeEquipmentSlot != -1)
                 // Note we should really write the absolute slot here, which we do not know about
