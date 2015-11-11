--- sope-mime/NGImap4/NGSieveClient.m.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGImap4/NGSieveClient.m
@@ -444,14 +444,14 @@ static BOOL     debugImap4         = NO;
     NSString *s;
     
     s = [NSString stringWithFormat:@"AUTHENTICATE \"PLAIN\" {%d+}\r\n%s",
-                  [auth length], [auth bytes]];
+                  (int)[auth length], [auth bytes]];
     map = [self processCommand:s];
   }
   else {
     NSString *s;
     
     s = [NSString stringWithFormat:@"AUTHENTICATE \"PLAIN\" {%d+}\r\n%s",
-                  [auth length], [auth bytes]];
+                  (int)[auth length], [auth bytes]];
     map = [self processCommand:s
                 logText:@"AUTHENTICATE \"PLAIN\" {%d+}\r\nLOGIN:PASSWORD\r\n"];
   }
@@ -548,7 +548,7 @@ static BOOL     debugImap4         = NO;
   s = [s stringByAppendingString:_name];
   s = [s stringByAppendingString:@"\" "];
   s = [s stringByAppendingFormat:@"{%d+}\r\n%@",
-         [_script lengthOfBytesUsingEncoding: NSUTF8StringEncoding],
+         (int)[_script lengthOfBytesUsingEncoding: NSUTF8StringEncoding],
          _script];
   map = [self processCommand:s];
   return [self normalizeResponse:map];
