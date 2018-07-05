--- source/tools/atlas/AtlasObject/AtlasObjectImpl.cpp.orig	2016-11-23 14:09:58 UTC
+++ source/tools/atlas/AtlasObject/AtlasObjectImpl.cpp
@@ -164,7 +164,12 @@ void AtObj::add(const char* key, AtObj& data)
 
 void AtObj::add(const char* key, const wxString& value)
 {
-	add(key, value.wc_str());
+	const AtNode* o = new AtNode(value.wc_str());
+
+	if (!p)
+		p = new AtNode();
+
+	p = p->addChild(key, AtNode::Ptr(o));
 }
 
 void AtObj::add(const char* key, const wchar_t* value)
@@ -187,7 +192,12 @@ void AtObj::set(const char* key, AtObj& data)
 
 void AtObj::set(const char* key, const wxString& value)
 {
-	set(key, value.wc_str());
+	const AtNode* o = new AtNode(value.wc_str());
+
+	if (!p)
+		p = new AtNode();
+
+	p = p->setChild(key, AtNode::Ptr(o));
 }
 
 void AtObj::set(const char* key, const wchar_t* value)
