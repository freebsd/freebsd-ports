--- juk/tageditor.cpp.orig	Sun Feb 16 06:07:29 2003
+++ juk/tageditor.cpp	Mon Mar  3 12:24:34 2003
@@ -315,17 +315,17 @@
     { // just for organization
         artistNameBox = new KComboBox(true, this, "artistNameBox");
 	artistNameBox->setCompletionMode(KGlobalSettings::CompletionAuto);
-	addItem(i18n("Artist Name"), artistNameBox, leftColumnLayout);
+	addItem(i18n("Artist name:"), artistNameBox, leftColumnLayout);
 
         trackNameBox = new KLineEdit(this, "trackNameBox");
-	addItem(i18n("Track Name"), trackNameBox, leftColumnLayout);
+	addItem(i18n("Track name:"), trackNameBox, leftColumnLayout);
 
         albumNameBox = new KComboBox(true, this, "albumNameBox");
 	albumNameBox->setCompletionMode(KGlobalSettings::CompletionAuto);
-	addItem(i18n("Album Name"), albumNameBox, leftColumnLayout);
+	addItem(i18n("Album name:"), albumNameBox, leftColumnLayout);
 
         genreBox = new KComboBox(true, this, "genreBox");
-	addItem(i18n("Genre"), genreBox, leftColumnLayout);
+	addItem(i18n("Genre:"), genreBox, leftColumnLayout);
 
         // this fills the space at the bottem of the left column
         leftColumnLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
@@ -334,7 +334,7 @@
     // put stuff in the right column
     //////////////////////////////////////////////////////////////////////////////
     { // just for organization
-        rightColumnLayout->addWidget(new QLabel(i18n("File Name"), this));
+        rightColumnLayout->addWidget(new QLabel(i18n("File name:"), this));
 
         fileNameBox = new KLineEdit(this, "fileNameBox");
         rightColumnLayout->addWidget(fileNameBox);
@@ -343,16 +343,16 @@
             QHBoxLayout *trackRowLayout = new QHBoxLayout(rightColumnLayout, horizontalSpacing);
 
             trackSpin = new KIntSpinBox(0, 255, 1, 0, 10, this, "trackSpin");
-	    addItem("Track", trackSpin, trackRowLayout);
+	    addItem(i18n("Track:"), trackSpin, trackRowLayout);
 
             trackRowLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
 
             yearSpin = new KIntSpinBox(0, 9999, 1, 0, 10, this, "yearSpin");
-	    addItem(i18n("Year"), yearSpin, trackRowLayout);
+	    addItem(i18n("Year:"), yearSpin, trackRowLayout);
 
             trackRowLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
 
-            trackRowLayout->addWidget(new QLabel(i18n("Length"), this));
+            trackRowLayout->addWidget(new QLabel(i18n("Length:"), this));
             lengthBox = new KLineEdit(this, "lengthBox");
             lengthBox->setMaximumWidth(50);
             lengthBox->setReadOnly(true);
@@ -360,7 +360,7 @@
 
             trackRowLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
 
-            trackRowLayout->addWidget(new QLabel(i18n("Bitrate"), this));
+            trackRowLayout->addWidget(new QLabel(i18n("Bitrate:"), this));
             bitrateBox = new KLineEdit(this, "bitrateBox");
             bitrateBox->setMaximumWidth(50);
             bitrateBox->setReadOnly(true);
@@ -369,7 +369,7 @@
 
         commentBox = new KEdit(this, "commentBox");
 	commentBox->setTextFormat(Qt::PlainText);
-	addItem(i18n("Comment"), commentBox, rightColumnLayout);
+	addItem(i18n("Comment:"), commentBox, rightColumnLayout);
     }
 
     connect(artistNameBox, SIGNAL(textChanged(const QString&)), this, SIGNAL(changed()));
@@ -463,7 +463,7 @@
 	if(!errorFiles.isEmpty())
 	    KMessageBox::detailedSorry(this,
 				       i18n("Could not save to specified file(s)."), 
-				       i18n("Could not write to:\n") + errorFiles.join("\n"));
+				       i18n("Could Not Write to:\n") + errorFiles.join("\n"));
 	dataChanged = false;
 
 	KApplication::restoreOverrideCursor();
