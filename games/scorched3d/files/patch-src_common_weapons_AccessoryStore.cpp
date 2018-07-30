../../common/weapons/AccessoryStore.cpp:158:64: error: cannot initialize return object of type 'AccessoryPart *' with an rvalue of type 'bool'
        if (!currentNode->getNamedParameter("type", typeNode)) return false;
                                                                      ^~~~~

--- src/common/weapons/AccessoryStore.cpp.orig	2018-07-30 09:52:29 UTC
+++ src/common/weapons/AccessoryStore.cpp
@@ -155,7 +155,7 @@ AccessoryPart *AccessoryStore::createAccessoryPart(
 	Accessory *parent, XMLNode *currentNode)
 {
 	XMLNode *typeNode = 0;
-	if (!currentNode->getNamedParameter("type", typeNode)) return false;
+	if (!currentNode->getNamedParameter("type", typeNode)) return 0;
 
 	AccessoryPart *accessoryPart = 
 		AccessoryMetaRegistration::getNewAccessory(typeNode->getContent(), this);
