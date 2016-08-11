--- src/World.C.orig	1999-05-12 01:45:46 UTC
+++ src/World.C
@@ -145,8 +145,8 @@ _Object& World::lookup_object(int obj_id
 
   if (!p) { // here it's really bad. Have to raise an exception !
     if (debug)
-      cerr << "World::lookup_object(): invalid object id=" << obj_id \
-	   << " !!!" << endl;
+      std::cerr << "World::lookup_object(): invalid object id=" << obj_id \
+	   << " !!!" << std::endl;
     return * objects.front(); /// @@ NNNNOOOOOONNNNNNNNNNNNNNNNNNNNNNNN!
   }
 
@@ -182,7 +182,7 @@ _Object * World::read_new_object(Trame &
     break;
   default:
     if (debug)
-      cerr << "World::read_new_object(): unknown object!\n";
+      std::cerr << "World::read_new_object(): unknown object!\n";
     break;
   }
 
@@ -201,7 +201,7 @@ void World::remove_object(int obj_id)
     remove_object0(p);
   else {
     if (debug)
-      cerr << "remove_object(): invalid object_id! id=" << obj_id << endl;
+      std::cerr << "remove_object(): invalid object_id! id=" << obj_id << std::endl;
   }
 }
 
@@ -243,8 +243,8 @@ Player& World::lookup_player(int player_
 
   if (!p) { // la, c'est tres grave. Faut faire une exception!
     if (debug)
-      cerr << "World::lookup_player(): invalid player id=" << player_id \
-	   << " !!!" << endl;
+      std::cerr << "World::lookup_player(): invalid player id=" << player_id \
+	   << " !!!" << std::endl;
     return * new Player(*this);  // <- en attendant mieux.
   }
 
@@ -269,7 +269,7 @@ void World::server_add_player(int socknu
 /* unlimited number of players!
   if (nbplayers >= maxplayers) {
     close(socknum);
-    cerr << "Too many players ! \n";
+    std::cerr << "Too many players ! \n";
     return;
   }
 */
@@ -278,16 +278,16 @@ void World::server_add_player(int socknu
   trame.set_timeout(5000);
   if (-1 == trame.receive_from(socknum)) {
     if (debug)
-      cerr << "World::server_add_player(): cannot read welcome packet " \
-	"from client" << endl;
+      std::cerr << "World::server_add_player(): cannot read welcome packet " \
+	"from client" << std::endl;
     close(socknum);
     return;
   }
   
   if (trame.peek_char() != JOIN_GAME) {
     if (debug)
-      cerr << "World::server_add_player(): Should have got JOIN_GAME ( " 
-	   << (int) JOIN_GAME << "), got " << (int) trame.peek_char() << endl;
+      std::cerr << "World::server_add_player(): Should have got JOIN_GAME ( " 
+	   << (int) JOIN_GAME << "), got " << (int) trame.peek_char() << std::endl;
     return;
   }
   trame.get_char();
@@ -321,7 +321,7 @@ void World::server_add_player_other(int 
   trameZ.set_timeout(1);
 
   if (debug)
-    cout << "World::server_add_player_other(): adding a subplayer" << endl;
+    std::cout << "World::server_add_player_other(): adding a subplayer" << std::endl;
 
   Player& p = * new Player(*this, socknum);
 
@@ -357,8 +357,8 @@ void World::remove_player(int player_id)
 
   if (!p) { // la, c'est tres grave. Faut faire une exception!
     if (debug)
-      cerr << "World::remove_player(): invalid player id=" << player_id \
-	   << " !!!" << endl;
+      std::cerr << "World::remove_player(): invalid player id=" << player_id \
+	   << " !!!" << std::endl;
     return;
   }
 
@@ -513,11 +513,11 @@ void World::own_cycle()
 	  && ((Movable *) objects(p))->player_id == 0)
 	nbworm++;
     
-    //    cout << "actually I have " << nbworm << " own worms..." << endl;
+    //    std::cout << "actually I have " << nbworm << " own worms..." << std::endl;
 
     // @@ 2: a mettre en parametre
     if (nbworm < 2) {
-      //      cout << "adding one.. heehe" << endl;
+      //      std::cout << "adding one.. heehe" << std::endl;
       Movable& worm = * new Movable(*this);
       worm.auto_position(map);
       worm.add_type(map);
@@ -569,7 +569,7 @@ void World::read_description(Trame& t)  
 {
   if (t.get_char() != WORLD_DESC) {
     if (debug)
-      cerr << " petard le bordel geant! \n";
+      std::cerr << " petard le bordel geant! \n";
     exit(1);
   }
 
@@ -708,11 +708,11 @@ void World::read_changes(Trame &t)
     
     default:
       if (debug)
-	cerr<< "read_changes(): unexpected trame Id == " \
-	    << (int) t.peek_char() << endl;
+	std::cerr<< "read_changes(): unexpected trame Id == " \
+	    << (int) t.peek_char() << std::endl;
       t.get_char();
       if (debug)
-	cerr<< "read_changes(): left in trame = ";
+	std::cerr<< "read_changes(): left in trame = ";
       t.dump_left();
       break;
     }
@@ -743,16 +743,16 @@ void World::build_maptype() 
 // for debug purposes
 void World::display()
 {
-  cout << "ID: " << id << "  WORLD";
-  cout << "  dims=" << x_dim << "x" << y_dim;
-  cout << " cycle=" << playcycle << endl;
-  cout << "  " << nbplayers << " players " << endl;
+  std::cout << "ID: " << id << "  WORLD";
+  std::cout << "  dims=" << x_dim << "x" << y_dim;
+  std::cout << " cycle=" << playcycle << std::endl;
+  std::cout << "  " << nbplayers << " players " << std::endl;
 
   // here we add if(1) to avoid bogus compilers problems
   if (1) for (Pix p = players.first(); p; players.next(p))
     players(p)->display();
 
-  cout << "  " << nbobjects << " objects " << endl;
+  std::cout << "  " << nbobjects << " objects " << std::endl;
 
   for (Pix p = objects.first(); p; objects.next(p))
      objects(p)->display();
@@ -826,7 +826,7 @@ void World::get_client_responses()
 
     if (retval < 0) {
       if (debug)
-	cerr << "World::get_client_responses(): bug quelque part!" << endl;
+	std::cerr << "World::get_client_responses(): bug quelque part!" << std::endl;
       return; // bah violent comme d'hab.
     }
 
@@ -915,7 +915,7 @@ void World::read_player_response(Player&
 	int newdir = t.get_char();
 	
 	if (debug)
-	  cout << "subplayer dir: ( " << worm_id << ") to " << newdir << endl;
+	  std::cout << "subplayer dir: ( " << worm_id << ") to " << newdir << std::endl;
 	
 	Movable & mv = (Movable &) lookup_object(worm_id);
 	Player * other_player = NULL;
@@ -928,8 +928,8 @@ void World::read_player_response(Player&
 	    || other_player->socket_number != p.socket_number) {
 	  
 	  if (debug)
-	    cerr << "World::PLAYER_CHANGEDIR_OTHER: bad id: " << worm_id \
-		 << endl;
+	    std::cerr << "World::PLAYER_CHANGEDIR_OTHER: bad id: " << worm_id \
+		 << std::endl;
 	}
 	else {
 	  if (!paused) {
@@ -954,12 +954,12 @@ void World::read_player_response(Player&
 
     case TEXT_MESSAGE: 
       {
-	//	cout << "got TEXT_MESSAGE == '";
+	//	std::cout << "got TEXT_MESSAGE == '";
 	t.get_char(); // skip msg id
 	int dest_id = t.get_int();
 	char *msg   = t.get_string();  // warning: use it fast!
 	
-	//	cout << msg << "'" << endl;
+	//	std::cout << msg << "'" << std::endl;
 
 	if (!dest_id) { // broadcast message
 	  cycle_trame.put_char(TEXT_MESSAGE);
@@ -1039,16 +1039,16 @@ void World::read_player_response(Player&
       
     case TRAME_ERROR:
       if (debug)
-	cerr << "World::read_player_response(): id=" << p.id \
-	     << " sent an error trame:! " << (int) t.peek_char() << endl;
+	std::cerr << "World::read_player_response(): id=" << p.id \
+	     << " sent an error trame:! " << (int) t.peek_char() << std::endl;
       done = 1;
       break;
       
     default: 
       if (debug) {
-	cerr << "World::read_player_response(): id=" << p.id \
-	     << " sent an unknown message: " << (int) t.peek_char() << endl;
-	cerr << "  ignoring rest of frame=";
+	std::cerr << "World::read_player_response(): id=" << p.id \
+	     << " sent an unknown message: " << (int) t.peek_char() << std::endl;
+	std::cerr << "  ignoring rest of frame=";
 	t.dump_left();
       }
       break;
@@ -1117,7 +1117,7 @@ Pix World::lookup_object0(int obj_id)
 
 void World::remove_object0(Pix& p)
 {
-  //FAST  cout << "? killing id=" << objects(p)->id << endl;
+  //FAST  std::cout << "? killing id=" << objects(p)->id << std::endl;
   delete objects(p);
   objects.del(p, -1);
   nbobjects--;
