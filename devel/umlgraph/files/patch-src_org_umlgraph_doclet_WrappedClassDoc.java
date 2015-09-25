--- src/org/umlgraph/doclet/WrappedClassDoc.java.orig	2012-04-25 08:57:52 UTC
+++ src/org/umlgraph/doclet/WrappedClassDoc.java
@@ -20,6 +20,7 @@
 
 package org.umlgraph.doclet;
 
+import com.sun.javadoc.AnnotatedType;
 import com.sun.javadoc.AnnotationDesc;
 import com.sun.javadoc.AnnotationTypeDoc;
 import com.sun.javadoc.ClassDoc;
@@ -359,4 +360,11 @@ public class WrappedClassDoc implements 
 	return wrapped.typeParamTags();
     }
 
+    public AnnotatedType asAnnotatedType() {
+	return wrapped.asAnnotatedType();
+    }
+
+    public Type getElementType() {
+	return wrapped.getElementType();
+    }
 }
