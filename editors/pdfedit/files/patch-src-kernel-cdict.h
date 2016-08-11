--- src/kernel/cdict.h.orig	2010-04-27 18:42:09 UTC
+++ src/kernel/cdict.h
@@ -799,7 +799,7 @@ setSimpleValueInDict (const IProperty& i
 	}
 
 	// Cast it to dict
-	CDict* dict = dynamic_cast<const CDict*> (&ip);
+	const CDict* dict = dynamic_cast<const CDict*> (&ip);
 	setSimpleValueInDict<Value, ItemType, ItemPType> (*dict, name, val);
 }
 
@@ -812,7 +812,7 @@ setSimpleValueInDict (const IProperty& i
 		throw ElementBadTypeException ("");
 
 	// Cast it to dict
-	CDict* dict = dynamic_cast<const CDict*> (&ip);
+	const CDict* dict = dynamic_cast<const CDict*> (&ip);
 
 	setSimpleValueInDict<ItemType> (*dict, name, val);
 }
