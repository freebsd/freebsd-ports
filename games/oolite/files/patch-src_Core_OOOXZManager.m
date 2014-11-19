--- src/Core/OOOXZManager.m.orig	2014-06-30 12:50:36.000000000 +0400
+++ src/Core/OOOXZManager.m	2014-09-25 08:46:25.000000000 +0400
@@ -215,13 +215,45 @@
 	}
 	if (!exists)
 	{
+#if OOLITE_MAC_OS_X
 		if (![fmgr oo_createDirectoryAtPath:path attributes:nil])
 		{
 			OOLog(kOOOXZErrorLog, @"Could not create folder %@.", path);
 			return NO;
 		}
+#else
+		NSArray *paths = NSSearchPathForDirectoriesInDomains(NSApplicationSupportDirectory,NSUserDomainMask,YES);
+		NSString *appPath = [paths objectAtIndex:0];
+		if (appPath == nil)
+		{
+			OOLog(kOOOXZErrorLog, @"Could not create folder %@.", path);
+			return NO;
+		}
+		else
+		{
+			if (![fmgr fileExistsAtPath:appPath] && ![fmgr oo_createDirectoryAtPath:appPath attributes:nil])
+			{
+				OOLog(kOOOXZErrorLog, @"Could not create folder %@.", path);
+				return NO;
+			}
+			appPath = [appPath stringByAppendingPathComponent:@"Oolite"];
+			if (![fmgr fileExistsAtPath:appPath] && ![fmgr oo_createDirectoryAtPath:appPath attributes:nil])
+			{
+				OOLog(kOOOXZErrorLog, @"Could not create folder %@.", path);
+				return NO;
+			}
+			/* GNUStep uses "ApplicationSupport" rather than "Application
+			 * Support" so match convention by not putting a space in the
+			 * path either */
+			appPath = [appPath stringByAppendingPathComponent:@"ManagedAddOns"];
+			if (![fmgr fileExistsAtPath:appPath] && ![fmgr oo_createDirectoryAtPath:appPath attributes:nil])
+			{
+				OOLog(kOOOXZErrorLog, @"Could not create folder %@.", path);
+				return NO;
+			}
+		}
+#endif
 	}
-	
 	return YES;
 }
 
