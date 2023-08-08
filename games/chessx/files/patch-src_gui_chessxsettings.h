--- src/gui/chessxsettings.h.orig	2023-05-08 20:22:12 UTC
+++ src/gui/chessxsettings.h
@@ -13,16 +13,11 @@ class ChessXSettings : public Settings
 public:
     ChessXSettings();
     ChessXSettings(const QString &fileName);
-
     virtual bool layout(QWidget* w);
     virtual void setLayout(const QWidget* w);
-
     static QLocale locale(); // Get the locale based upon current settings
-#ifdef USE_SPEECH
     static QStringList availableVoices(QString lang); // Get the list of voices based upon selected locale
     static void configureSpeech(QTextToSpeech* speech);
-#endif
-
 protected:
     virtual void initWidgetValues(QMap<QString, QVariant>& map) const;
 };
