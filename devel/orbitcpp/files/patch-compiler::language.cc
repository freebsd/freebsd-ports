--- compiler/language.cc.orig	Sun Dec  8 01:58:29 2002
+++ compiler/language.cc	Sun Dec  8 02:01:53 2002
@@ -154,7 +154,7 @@
 
 string 
 IDLElement::getQualifiedIDLIdentifier(IDLScope const *up_to,
-        IDLScope const *assumed_base = NULL) const {
+        IDLScope const *assumed_base) const {
 	if (up_to == this) return "";
 	IDLScope const *run = assumed_base ? assumed_base : getParentScope();
 
@@ -172,7 +172,7 @@
 
 string 
 IDLElement::getQualifiedCIdentifier(IDLScope const *up_to,
-        IDLScope const *assumed_base = NULL) const {
+        IDLScope const *assumed_base) const {
 	if (up_to == this) return "";
 	IDLScope const *run = assumed_base ? assumed_base : getParentScope();
 
@@ -192,7 +192,7 @@
 
 string 
 IDLElement::getQualifiedCPPIdentifier(IDLScope const *up_to,
-        IDLScope const *assumed_base = NULL) const {
+        IDLScope const *assumed_base) const {
 	if (up_to == this) return "";
 	IDLScope const *run = assumed_base ? assumed_base : getParentScope();
 
@@ -390,7 +390,7 @@
 
 // IDLCaseStmt ---------------------------------------------------------------
 IDLCaseStmt::IDLCaseStmt(IDLMember *member, string const &id,
-						 IDL_tree node,IDLScope *parentscope = NULL)
+						 IDL_tree node,IDLScope *parentscope)
 	: IDLElement(id,node,parentscope), m_member(member),m_isDefault(false) {
 
 	// labels
