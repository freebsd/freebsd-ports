--- src/mkinclud.mak.orig	2022-12-21 18:37:41 UTC
+++ src/mkinclud.mak
@@ -64,9 +64,6 @@ DOC=../usrshare/doc_user
 # Unicode data tables:
 
 # With Unicode 7.0, there is no UCD.zip anymore, so downloaded separately
-UCD.zip:
-	echo Trying to retrieve Unicode data file via Internet
-	$(WGET) http://www.unicode.org/Public/UNIDATA/UCD.zip
 UnicodeData.txt:	UCD.zip
 	unzip -o UCD $@; touch -r UCD.zip $@
 Scripts.txt:	UCD.zip
@@ -87,15 +84,15 @@ DerivedBidiClass.txt:	UCD.zip
 	unzip -o -j UCD extracted/$@; touch -r UCD.zip $@
 
 %.txt:
-	$(WGET) http://www.unicode.org/Public/UNIDATA/$@
+	#$(WGET) http://www.unicode.org/Public/UNIDATA/$@
 
-Unihan.zip:
+Unihan.zip_without_wget:
 	echo Trying to retrieve Unicode data file via Internet
 	$(WGET) http://www.unicode.org/Public/UNIDATA/Unihan.zip
 
 BIG5.TXT:
-	echo Trying to retrieve Unicode data file via Internet
-	$(WGET) http://www.unicode.org/Public/MAPPINGS/OBSOLETE/EASTASIA/OTHER/BIG5.TXT
+	#echo Trying to retrieve Unicode data file via Internet
+	#$(WGET) http://www.unicode.org/Public/MAPPINGS/OBSOLETE/EASTASIA/OTHER/BIG5.TXT
 
 check_ccc:
 	grep "^ccc; *230;.*; *Above$$" PropertyValueAliases.txt
@@ -116,7 +113,7 @@ uniset:	uniset.tar.gz
 	gzip -dc uniset.tar.gz | tar xvf - uniset
 
 uniset.tar.gz:
-	$(WGET) https://www.cl.cam.ac.uk/~mgk25/download/uniset.tar.gz
+	#$(WGET) https://www.cl.cam.ac.uk/~mgk25/download/uniset.tar.gz
 
 #WIDTH-A:	uniset.tar.gz
 #	tar xvzf uniset.tar.gz WIDTH-A
@@ -726,7 +723,7 @@ install:	mined help man
 	mkdir -p $(DESTDIR)$(mandir)/man1
 	$(INSTALL) ../man/*.1 $(DESTDIR)$(mandir)/man1
 	# zip man if mans are zipped in actual mandir (not DESTDIR)
-	if (ls $(mandir)/man1/*.gz && type gzip) > /dev/null 2>&1; then gzip -f $(DESTDIR)$(mandir)/man1/mined.1; fi
+	#if (ls $(mandir)/man1/*.gz && type gzip) > /dev/null 2>&1; then gzip -f $(DESTDIR)$(mandir)/man1/mined.1; fi
 	# ==== install desktop context menu item ("Open With")
 	( $(rootmenu) && $(rooticon) ) || ( $(usermenu) && $(usericon) ) || echo Could not install desktop menu entry
 	# ==== install system-specific stuff (e.g. wined, README.cygwin)
@@ -748,9 +745,9 @@ localinstall:	mined help man
 	rm -fr $(DESTDIR)$(lrundir)/doc_user/fonts
 	# ==== install manual page
 	mkdir -p $(DESTDIR)$(lmandir)/man1
-	$(INSTALL) ../man/*.1 $(DESTDIR)$(lmandir)/man1
+	$(BSD_INSTALL_MAN) ../man/*.1 $(DESTDIR)$(lmandir)/man1
 	# zip man if mans are zipped in actual mandir (not DESTDIR)
-	if (ls $(lmandir)/man1/*.gz && type gzip) > /dev/null 2>&1; then gzip -f $(DESTDIR)$(lmandir)/man1/mined.1; fi
+	#if (ls $(lmandir)/man1/*.gz && type gzip) > /dev/null 2>&1; then gzip -f $(DESTDIR)$(lmandir)/man1/mined.1; fi
 	# ==== install desktop context menu item ("Open With")
 	( $(localmenu) && $(localicon) ) || ( $(usermenu) && $(usericon) ) || echo Could not install desktop menu entry
 	# ==== install system-specific stuff (e.g. wined, README.cygwin)
