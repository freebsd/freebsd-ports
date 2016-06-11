--- src/kernel/cdict.h.orig	2016-06-11 05:41:31.261535000 +0900
+++ src/kernel/cdict.h	2016-06-11 05:44:42.503741000 +0900
@@ -799,7 +799,7 @@
 	}
 
 	// Cast it to dict
-	CDict* dict = dynamic_cast<const CDict*> (&ip);
+	const CDict* dict = dynamic_cast<const CDict*> (&ip);
 	setSimpleValueInDict<Value, ItemType, ItemPType> (*dict, name, val);
 }
 
@@ -812,7 +812,7 @@
 		throw ElementBadTypeException ("");
 
 	// Cast it to dict
-	CDict* dict = dynamic_cast<const CDict*> (&ip);
+	const CDict* dict = dynamic_cast<const CDict*> (&ip);
 
 	setSimpleValueInDict<ItemType> (*dict, name, val);
 }
