--- src/linux/LinuxMouse.cpp	(revision 1090)
+++ src/linux/LinuxMouse.cpp	(working copy)
@@ -156,29 +156,28 @@
 	char mask[4] = {0,1,4,2};
 	XEvent event;
 
-	//Poll x11 for events mouse events
-	while( XPending(display) > 0 ) 
+	Window u1; int u2;
+	Window current_win;
+	int x, y;
+	unsigned int mmask;
+
+	if (XQueryPointer(display, window, &u1, &current_win, &u2, &u2, &x, &y, &mmask))
 	{
-		XNextEvent(display, &event);
-
-		if( event.type == MotionNotify )
-		{	//Mouse moved
-			//Ignore out of bounds mouse if we just warped
-			if( mWarped )
-			{
-				if(event.xmotion.x < 5 || event.xmotion.x > mState.width - 5 ||
-				   event.xmotion.y < 5 || event.xmotion.y > mState.height - 5)
-					continue;
-			}
-
+		//Ignore out of bounds mouse if we just warped
+		if(mWarped && (x < 5 || x > mState.width - 5 || y < 5 || y > mState.height - 5))
+		{
+			// ignored
+ 		}
+		else if (!(oldXMouseX == x && oldXMouseY == y))
+		{
 			//Compute this frames Relative X & Y motion
-			mState.X.rel = event.xmotion.x - oldXMouseX;
-			mState.Y.rel = event.xmotion.y - oldXMouseY;
-		
+			mState.X.rel = x - oldXMouseX;
+			mState.Y.rel = y - oldXMouseY;
+			
 			//Store old values for next time to compute relative motion
-			oldXMouseX = event.xmotion.x;
-			oldXMouseY = event.xmotion.y;
-
+			oldXMouseX = x;
+			oldXMouseY = y;
+			
 			mState.X.abs += mState.X.rel;
 			mState.Y.abs += mState.Y.rel;
 
@@ -198,8 +197,8 @@
 				if( mouseFocusLost == false )
 				{
 					//Keep mouse in window (fudge factor)
-					if(event.xmotion.x < 5 || event.xmotion.x > mState.width - 5 ||
-					   event.xmotion.y < 5 || event.xmotion.y > mState.height - 5 )
+					if(x < 5 || x > mState.width - 5 ||
+					   y < 5 || y > mState.height - 5 )
 					{
 						oldXMouseX = mState.width >> 1;  //center x
 						oldXMouseY = mState.height >> 1; //center y
@@ -210,8 +209,16 @@
 			}
 			mMoved = true;
 		}
-		else if( event.type == ButtonPress )
-		{	//Button down
+	}
+
+
+	//Poll x11 for events mouse events
+	while( XPending(display) > 0 )
+	{
+		XNextEvent(display, &event);
+
+		if( event.type == ButtonPress )
+		{   //Button down
 			static_cast<LinuxInputManager*>(mCreator)->_setGrabState(true);
 
 			if( event.xbutton.button < 4 )
 	  	 
