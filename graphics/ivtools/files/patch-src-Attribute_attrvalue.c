--- src/Attribute/attrvalue.c.orig	2010-03-21 07:23:29.000000000 -0300
+++ src/Attribute/attrvalue.c	2010-03-21 07:40:19.000000000 -0300
@@ -393,7 +393,7 @@
     case AttributeValue::StringType:
 	return (boolean) int_val()!=-1;
     case AttributeValue::ObjectType:
-	return (boolean) obj_val();
+	return (intptr_t) obj_val();
     case AttributeValue::StreamType:
 	return stream_mode() != 0;
     default:
@@ -552,7 +552,7 @@
     case AttributeValue::SymbolType:
 	return (unsigned int) int_val();
     case AttributeValue::ObjectType:
-        return (unsigned int)obj_val();
+        return (uintptr_t) obj_val();
     default:
 	return 0;
     }
@@ -585,7 +585,7 @@
     case AttributeValue::SymbolType:
 	return int_ref();
     case AttributeValue::ObjectType:
-        return (int)obj_val();
+        return (intptr_t) obj_val();
     default:
 	return 0;
     }
