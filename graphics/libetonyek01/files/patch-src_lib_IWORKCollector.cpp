From: Caolán McNamara <caolanm@redhat.com>
Date: Mon, 23 Apr 2018 16:20:16 +0000 (+0100)
Subject: intial-creator->initial-creator
X-Git-Url: https://gerrit.libreoffice.org/gitweb?p=libetonyek.git;a=commitdiff_plain;h=9b78187ac2ccca0158cc9cc0bcc0576b457a78d7

intial-creator->initial-creator

Change-Id: I6fe5d0732edb97ac7ff6d527f48543cab1bb3f7b
Reviewed-on: https://gerrit.libreoffice.org/53337
Reviewed-by: David Tardon <dtardon@redhat.com>
Tested-by: David Tardon <dtardon@redhat.com>
--- src/lib/IWORKCollector.cpp.orig	2018-04-21 10:40:43 UTC
+++ src/lib/IWORKCollector.cpp
@@ -771,7 +771,7 @@ void IWORKCollector::fillMetadata(librevenge::RVNGProp
   if (!m_metadata.m_title.empty())
     props.insert("dc:subject", m_metadata.m_title.c_str());
   if (!m_metadata.m_author.empty())
-    props.insert("meta:intial-creator", m_metadata.m_author.c_str());
+    props.insert("meta:initial-creator", m_metadata.m_author.c_str());
   if (!m_metadata.m_keywords.empty())
     props.insert("meta:keyword", m_metadata.m_keywords.c_str());
   if (!m_metadata.m_comment.empty())
