From: Milian Wolff <mail@milianw.de>
Date: Fri, 17 Oct 2014 19:01:48 +0000
Subject: Fix compile with clang 3.5
X-Git-Url: http://quickgit.kde.org/?p=kdevelop.git&a=commitdiff&h=4b4dcc3fb32f47ebfb19552e9638f90a2e22b2a0
---
Fix compile with clang 3.5
---


--- languages/cpp/codegen/adaptsignatureassistant.cpp
+++ languages/cpp/codegen/adaptsignatureassistant.cpp
@@ -94,7 +94,7 @@
   m_otherSideId = {};
   m_otherSideTopContext = {};
   m_otherSideContext = {};
-  m_oldSignature = {};
+  m_oldSignature = Signature();
   m_document = {};
   m_view.clear();
 }

