commit b196bb68f7ac03b3bf9fcbcb4af3ae81e0ca0d7e
Author: Christian Kandeler <christian.kandeler@digia.com>
Date:   Fri Aug 9 11:32:05 2013 +0200

    Fix typo in QmlJsParser.
    
    Change-Id: Iade7c0ad78576e1b5bc8110bef8dfb51db7eff8a
    Reviewed-by: Tobias Hunger <tobias.hunger@digia.com>

--- src/shared/qbs/src/lib/parser/qmljs.g
+++ src/shared/qbs/src/lib/parser/qmljs.g
@@ -291,7 +291,7 @@ public:
     inline DiagnosticMessage diagnosticMessage() const
     {
         foreach (const DiagnosticMessage &d, diagnostic_messages) {
-            if (! d.kind == DiagnosticMessage::Warning)
+            if (d.kind != DiagnosticMessage::Warning)
                 return d;
         }
 
