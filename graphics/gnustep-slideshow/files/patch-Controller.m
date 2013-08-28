--- Controller.m.orig	2013-08-20 15:46:28.000000000 +0000
+++ Controller.m	2013-08-20 15:46:48.000000000 +0000
@@ -1021,32 +1021,32 @@
 {
   SEL action = [menuItem action];
   
-  if ( sel_eq(action,@selector(removeImages:)) ) 
+  if ( sel_isEqual(action,@selector(removeImages:)) ) 
     {
       if ((  [_backend count] == 0 ) || ( ! [browser selectedCells] ) )
 	return NO;
     }
-  if ( sel_eq(action,@selector(showNextImage:)) )
+  if ( sel_isEqual(action,@selector(showNextImage:)) )
     {
       if (  (  ( _current + 1 ) == [_backend count] ) || ( [_backend count] == 0 )  )
 	return NO;
     }
-  else if ( sel_eq(action,@selector(showPreviousImage:)) )
+  else if ( sel_isEqual(action,@selector(showPreviousImage:)) )
     {
       if ( [_backend count] == 0 ) 
 	return NO;
     }
-  else if ( sel_eq(action,@selector(fullscreenAction:)) )
+  else if ( sel_isEqual(action,@selector(fullscreenAction:)) )
     {
       if ( [_backend count]  == 0 ) 
 	return NO;
     }
-  else if ( sel_eq(action,@selector(addMarkAction:)) ) 
+  else if ( sel_isEqual(action,@selector(addMarkAction:)) ) 
     {
       if ( (  [self showState] == ShowOnlyMarked ) ||  ([_backend count] == 0 ) )
 	return NO;
     }
-  else if ( sel_eq(action,@selector(showMarkAction:)) ) 
+  else if ( sel_isEqual(action,@selector(showMarkAction:)) ) 
     {
       if ( [_backend count] == 0  )
 	return NO;
