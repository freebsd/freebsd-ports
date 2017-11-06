--- src/misc/CNestedDataFile/anytype.h.orig	2013-02-10 06:35:02 UTC
+++ src/misc/CNestedDataFile/anytype.h
@@ -159,7 +159,7 @@ template<class Type> STATIC_TPL const st
 	{
 		// leaving type in case it's not able to deduce aruments and chooses the default template implemenation
 		// if I knew how to constrain the original definition of the template, I would make it fully constrained
-		s+=anytype_to_string(any[t]);
+		s+=anytype_to_string<Type>(any[t]);
 		if(t!=(l-1))
 				s+=",";
 	}
