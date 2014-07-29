--- src/Movable.C	Tue May 11 12:15:20 1999
+++ src/Movable.C	Sat Oct 26 00:40:14 2002
@@ -51,7 +51,7 @@
 void Movable::read_description(Trame& t)
 {
   if (t.get_char() != NEW_MOVABLE) {
-    cerr << "Movable::read_description(): ohhh le bordel!\n";
+    std::cerr << "Movable::read_description(): ohhh le bordel!\n";
     exit(1);
   }
   
@@ -91,19 +91,19 @@
 // for debug purposes
 void Movable::display()
 {
-  cout << "   ID:"<< id;
+  std::cout << "   ID:"<< id;
   printf(" %04x", classtype);
-  cout <<" Movable " << pos.x << "x" << pos.y << " sp=" << speed 
+  std::cout <<" Movable " << pos.x << "x" << pos.y << " sp=" << speed 
        << " dir=" << direction << " len=" << length 
        << " full=" << full_length << " pid=" << player_id 
        << " paused=" << paused << " q=[ " ;
   
   Pix pix = queue.first();
   for (int i = length - 1; i > 0; i--) {
-    cout << queue(pix) << " ";
+    std::cout << queue(pix) << " ";
     queue.next(pix);
   }
-  cout << "]" <<  endl;
+  std::cout << "]" <<  std::endl;
 }
 
 
@@ -282,7 +282,7 @@
 	       && !update_pos(p = pos, D_RIGHT))
 	newdir = D_RIGHT;
 //       else
-// 	cout << "Movable::auto_dir(): couldn't find a way to go!" << endl;
+// 	std::cout << "Movable::auto_dir(): couldn't find a way to go!" << std::endl;
 
     if (direction != newdir) {
       direction = newdir;
@@ -401,7 +401,7 @@
   _Position pos2 = pos;
   
   if (length == 1) {
-    cerr << "getcut too short" << endl;
+    std::cerr << "getcut too short" << std::endl;
     return;
   }
   
@@ -415,7 +415,7 @@
 
   // should never happen. (should be an assertion)
   if (!p) {
-    cerr << "Movable::cut(): reached end of queue!" << endl;
+    std::cerr << "Movable::cut(): reached end of queue!" << std::endl;
     return;
   }
     
@@ -447,7 +447,7 @@
     //evidemment ca bug!    world.add_object(worm);
   }
   //else
-  //    cerr << "petard de pas de p" << endl;
+  //    std::cerr << "petard de pas de p" << std::endl;
 }
 
 
