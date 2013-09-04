diff --git a/hphp/util/parser/parser.cpp b/hphp/util/parser/parser.cpp
index 72c11bb..0132a4b 100644
--- a/hphp/util/parser/parser.cpp
+++ hphp/util/parser/parser.cpp
@@ -186,6 +186,7 @@ void ParserBase::addLabel(const std::string &label,
   labelInfo.scopeId         = info.scopes.back();
   labelInfo.stmt            = extractStatement(stmt);
   labelInfo.loc             = loc;
+  labelInfo.inTryCatchBlock = false;
   info.labels[label]        = labelInfo;
 }
 
