--- src/PYConfig.cc.orig	2012-12-19 15:30:43 UTC
+++ src/PYConfig.cc
@@ -114,6 +114,7 @@ Config::initDefaultValues (void)
     m_init_full_punct = TRUE;
     m_init_simp_chinese = TRUE;
     m_special_phrases = TRUE;
+    m_double_pinyin = FALSE;
     updateContext (PyZy::InputContext::PROPERTY_SPECIAL_PHRASE,
                    PyZy::Variant::fromBool (m_special_phrases));
 }
