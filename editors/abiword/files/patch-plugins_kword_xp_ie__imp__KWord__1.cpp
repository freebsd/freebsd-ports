--- plugins/kword/xp/ie_imp_KWord_1.cpp.orig	2021-07-03 15:46:07 UTC
+++ plugins/kword/xp/ie_imp_KWord_1.cpp
@@ -180,7 +180,7 @@ void IE_Imp_KWord_1::charData(const gchar *s, int len)
 	  m_charDataSeen[m_lenCharDataSeen++] = currentChar;
 	  if (m_lenCharDataSeen == m_lenCharDataExpected)
 	    {
-	      buf += g_utf8_get_char(m_charDataSeen);
+	      buf += static_cast<UT_UCS4Char>(g_utf8_get_char(m_charDataSeen));
 	      m_lenCharDataSeen = 0;
 	    }
 	}
