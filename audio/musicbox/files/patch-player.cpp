--- player.cpp.orig	Thu Oct  1 10:00:23 1998
+++ player.cpp	Wed Jun  9 00:56:30 1999
@@ -72,7 +72,7 @@
 	options = new QPopupMenu;
 	AutoPlayID = options->insertItem( "&Auto Play", this, SLOT(AutoPlay()) );
 	options->setItemChecked( AutoPlayID, isAutoPlay );
-	RepeatID = options->insertItem( "Re&peat", this, SLOT(RepeatPlay()) );
+	RepeatID = options->insertItem( "&Repeat", this, SLOT(RepeatPlay()) );
 	options->setCheckable(TRUE);
 	menubar->insertItem( "&Options",options );
 	menubar->insertSeparator();
@@ -150,7 +150,7 @@
 
 	QLabel *label;
 	label = new QLabel( this );
-	label->setText("歌星:");
+	label->setText("Artist:");
 	label->setGeometry(5,133,125,30);
 
 	edtName = new QLabel( this );
@@ -158,7 +158,7 @@
 	edtName->setGeometry(83,136,100,25);
 
 	label = new QLabel( this );
-	label->setText("專輯名稱:");
+	label->setText("Album:");
 	label->setGeometry(5,173,125,30);
 
 	edtAlbum = new QLabel( this );
@@ -166,7 +166,7 @@
 	edtAlbum->setGeometry(83,176,100,25);
 
 	label = new QLabel( this );
-	label->setText("發行公司:");
+	label->setText("Company:");
 	label->setGeometry(5,213,125,30);
 
 	edtPub = new QLabel( this );
@@ -242,15 +242,13 @@
 		song->setText(SongBox->text(SongBox->currentItem()));
 		dclock->Start(SongBox->currentItem());
 		if ((mp3_pid = fork()) == 0 ){
-			char **argv;
-			int i;
-			argv[0]=MP3_PLAYER;
-			argv[1]="-q";
-			argv[2]=(char *)LocBox->text(SongBox->currentItem());
-			argv[3]=NULL;
-			execvp(MP3_PLAYER,argv);
+			execlp(MP3_PLAYER,
+			       MP3_PLAYER,
+			       "-q",
+			       (char *)LocBox->text(SongBox->currentItem()),
+			       NULL);
 			QMessageBox::warning(this,"error","can't exec mpg123\n");
-			exit(1);
+			_exit(1);
 		}
 	}
 }
