--- ListView.cpp.orig	Wed Feb 17 09:17:11 1999
+++ ListView.cpp	Wed Feb 17 09:21:00 1999
@@ -383,11 +383,11 @@
 	if (item != NULL)
 		temp = item;
 
-	lbl = new QLabel("歌星:",this);
+	lbl = new QLabel("Artist:",this);
 	topLayout->addWidget(lbl,0,0);
-	lbl = new QLabel("專輯名稱:",this);
+	lbl = new QLabel("Album:",this);
 	topLayout->addWidget(lbl,1,0);
-	lbl = new QLabel("發行公司:",this);
+	lbl = new QLabel("Company:",this);
 	topLayout->addWidget(lbl,2,0);
 
 	Title = new QLabel(this);
@@ -412,7 +412,7 @@
 	connect(btn,SIGNAL(clicked()),this,SLOT(RemoveSong()));
 	topLayout->addWidget(btn,4,1);
 
-	lbl = new QLabel("歌曲名稱:",this);
+	lbl = new QLabel("Title:",this);
 	topLayout->addWidget(lbl,4,2);
 
 	edtSinger = new QLineEdit(this);
