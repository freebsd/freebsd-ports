- Remove debugging fprintf in MachineImpl.cpp to fix build with GCC 4.6

Submitted by:	Andriy Gapon <avg at FreeBSD.org>
--- src/VBox/Main/src-server/MachineImpl.cpp.orig	2012-04-03 14:12:01.000000000 +0200
+++ src/VBox/Main/src-server/MachineImpl.cpp	2012-04-13 10:49:25.000000000 +0200
@@ -6643,7 +6643,6 @@
 
         Utf8Str idStr = mData->mUuid.toString();
         const char * args[] = {szPath, "--comment", mUserData->s.strName.c_str(), "--startvm", idStr.c_str(), 0 };
-        fprintf(stderr, "SDL=%s\n",  szPath);
         vrc = RTProcCreate(szPath, args, env, 0, &pid);
     }
 #else /* !VBOX_WITH_VBOXSDL */
