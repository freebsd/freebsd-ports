Reference:	https://github.com/nant/nant/issues/91
Obtained from:	https://github.com/nant/nant/commit/69c8ee96493c5d953212397c8ca06c2392372ca4
		https://github.com/nant/nant/commit/4ad065d009b043996d4ce2d25ce5031d81c6ce60

--- src/NAnt.Core/ConsoleDriver.cs.orig	2012-06-09 14:05:53 UTC
+++ src/NAnt.Core/ConsoleDriver.cs
@@ -318,8 +318,9 @@ namespace NAnt.Core {
             xsltDoc.Load(reader);
             xsltDoc.DocumentElement.SetAttribute("xmlns:nant",buildDoc.DocumentElement.NamespaceURI);
 
-            XslTransform transform = new XslTransform();
-            transform.Load(xsltDoc);
+            XslCompiledTransform transform = new XslCompiledTransform();
+            XsltSettings settings = new XsltSettings(false, true);
+            transform.Load(xsltDoc, settings, new XmlUrlResolver());
 
             StringBuilder sb = new StringBuilder();
             StringWriter writer = new StringWriter(sb, CultureInfo.InvariantCulture);
