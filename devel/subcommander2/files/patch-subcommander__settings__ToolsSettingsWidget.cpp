--- subcommander/settings/ToolsSettingsWidget.cpp.orig	2007-08-19 22:04:03.000000000 +0900
+++ subcommander/settings/ToolsSettingsWidget.cpp	2012-05-10 05:29:12.000000000 +0900
@@ -39,7 +39,7 @@
     vl->addStretch(1);
     {
       // diff command
-      QLabel* diffLabel   = new QLabel(_q("(visual) diff comand:"), this);
+      QLabel* diffLabel   = new QLabel(_q("(visual) diff command:"), this);
       QPushButton* diffBi = new QPushButton( _q("reset/builtin"), this );
       _diffEdit           = new QLineEdit( this );
       QPushButton* diffEx = new ExternButton( this );
@@ -59,7 +59,7 @@
       row++;
 
       // merge command
-      QLabel* mergeLabel   = new QLabel(_q("(visual) merge comand:"), this);
+      QLabel* mergeLabel   = new QLabel(_q("(visual) merge command:"), this);
       QPushButton* mergeBi = new QPushButton( _q("reset/builtin"), this );
       _mergeEdit           = new QLineEdit( this );
       QPushButton* mergeEx = new ExternButton( this );
