--- src/cmd/basecomputer.cpp.orig	2008-04-24 16:12:27.000000000 +0400
+++ src/cmd/basecomputer.cpp	2010-04-03 08:25:45.000000000 +0400
@@ -3099,7 +3099,7 @@
     // Make the title right.
     recalcTitle();
 }
-#if defined (__FreeBSD__) || defined(__APPLE__)
+#if defined(__APPLE__)
 static int	nodirs( struct dirent * entry)
 #else
 static int	nodirs( const struct dirent * entry)
@@ -3128,14 +3128,12 @@
 	return 0;
 }
 
-static int datesort ( const void *v1, const void *v2 ) {
-	const struct dirent *d1=*(const struct dirent**)v1;
-	const struct dirent *d2=*(const struct dirent**)v2;
+static int datesort ( const struct dirent **d1, const struct dirent **d2 ) {
 	struct stat s1, s2;
-	std::string tmp=VSFileSystem::homedir+"/save/"+d1->d_name;
+	std::string tmp=VSFileSystem::homedir+"/save/"+(*d1)->d_name;
 	if (stat(tmp.c_str(), &s1))
 		return 0;
-	tmp=VSFileSystem::homedir+"/save/"+d2->d_name;
+	tmp=VSFileSystem::homedir+"/save/"+(*d2)->d_name;
 	if (stat(tmp.c_str(), &s2))
 		return 0;
 	
@@ -3160,7 +3158,7 @@
 		const int playerNum=UnitUtil::isPlayerStarship(playerUnit);
 		struct dirent ** dirlist;
 		std::string savedir = VSFileSystem::homedir+"/save/";
-		int ret = scandir (savedir.c_str(),&dirlist,nodirs,(scancompare)&datesort);
+		int ret = scandir (savedir.c_str(),&dirlist,nodirs,datesort);
 		while( ret-->0) {
 			picker->addCell(new SimplePickerCell(dirlist[ret]->d_name));
 		}		
