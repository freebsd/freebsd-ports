Fix build with Qt >= 6.9.0

/wrkdirs/usr/ports/audio/musescore/work/MuseScore-4.5/src/palette/view/widgets/specialcharactersdialog.cpp:715:55:
error: no matching member function for call to 'arg'
  715 |         m_pUnicode->appendElement(fs, QString("0x%1").arg(code, 5, 16, QChar('0')));
      |                                       ~~~~~~~~~~~~~~~~^~~

--- src/palette/view/widgets/specialcharactersdialog.cpp.orig	2025-03-13 18:44:57 UTC
+++ src/palette/view/widgets/specialcharactersdialog.cpp
@@ -712,7 +712,7 @@ void SpecialCharactersDialog::populateUnicode()
         std::shared_ptr<FSymbol> fs = std::make_shared<FSymbol>(gpaletteScore->dummy());
         fs->setCode(code);
         fs->setFont(m_font);
-        m_pUnicode->appendElement(fs, QString("0x%1").arg(code, 5, 16, QLatin1Char('0')));
+        m_pUnicode->appendElement(fs, QString("0x%1").arg(static_cast<quint32>(code), 5, 16, QLatin1Char('0')));
     }
 }
 
