--- ./Seat.cpp.orig	2013-10-29 15:12:13.000000000 -0200
+++ ./Seat.cpp	2013-10-29 15:12:13.000000000 -0200
@@ -151,10 +151,10 @@
 	   gcv.font = XLoadFont(_dpy, "10x20"); 
 		gcflags = GCForeground | GCBackground | GCGraphicsExposures;
 		_redgc = XCreateGC(_dpy, RootWindow(_dpy, _screen), gcflags, &gcv);
+		// allocate drawing area background color, set areas 
+		XAllocNamedColor(_dpy, cmap, "Forest Green", &color, &color);
 	 
 	}
-	// allocate drawing area background color, set areas 
-	XAllocNamedColor(_dpy, cmap, "Forest Green", &color, &color);
 	i = 0;
 	XtSetArg(args[i], XmNbackground, color.pixel);   i++;
 	XtSetArg(args[i], XmNforeground, whitepixel);   i++;
@@ -342,7 +342,8 @@
    Card ** cards = hands->Cards();
    if( hands->NumOfCards() )
    {
-      for(int i=0; i< hands->NumOfCards() -1; i++)
+      int i;
+      for(i=0; i< hands->NumOfCards() -1; i++)
         DrawCardBack(GetWindow(), cards[i], PositionCardX(cards[i],i),
                                           PositionCardY(cards[i],i));
       DrawCard(GetWindow(), cards[i], PositionCardX(cards[i],i),
