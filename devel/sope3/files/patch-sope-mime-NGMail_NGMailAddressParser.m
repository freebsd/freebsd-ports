--- sope-mime/NGMail/NGMailAddressParser.m	2019-03-07 19:04:29.174101000 +0000
+++ sope-mime/NGMail/NGMailAddressParser.m	2019-03-07 19:05:10.004206000 +0000
@@ -382,6 +382,9 @@
 
   NSUInteger addrStart, addrEnd, commaPos;
 
+  if (!originalAddress)
+    return nil;
+
   whitespace = [NSCharacterSet whitespaceAndNewlineCharacterSet];
   addressList = [NSMutableArray arrayWithCapacity: 1];
   remainder = [NSMutableString stringWithString: originalAddress];
