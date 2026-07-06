--- src/slic3r/GUI/MsgDialog.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/MsgDialog.cpp
@@ -178,9 +178,11 @@
     bd->button = btn;
     //bd->type   = type;
 
-    mb->id        = wxString::Format("%d", m_buttons.size());
+    // build the key via std::to_string, not Format("%d", ...): size_t is
+    // 64-bit on LP64 (FreeBSD) and mismatches %d, tripping wx's format type-safety assert.
+    mb->id        = wxString(std::to_string(m_buttons.size()));
     mb->buttondata = bd;
-    m_buttons[ wxString::Format("%d", m_buttons.size())] = mb;
+    m_buttons[ wxString(std::to_string(m_buttons.size()))] = mb;
     return btn;
 };
 
