--- src/texpigment.cc.orig	Tue Oct  4 02:54:41 2005
+++ src/texpigment.cc	Tue Oct 18 18:58:11 2005
@@ -236,9 +236,9 @@
 
 if ( blockpig1 == NULL && type->value() == 2 )
 	{
-	blockpig1 = new PovTexPigment( app_ref, false );
-	blockpig2 = new PovTexPigment( app_ref, false );
-	blockpig3 = new PovTexPigment( app_ref, false );
+	blockpig1 = new PovTexPigment( app_ref, NULL, false );
+	blockpig2 = new PovTexPigment( app_ref, NULL, false );
+	blockpig3 = new PovTexPigment( app_ref, NULL, false );
 	blockpig1->add_to_tree(  tree_view, tree_store, tree_selection, &node_iter  );
 	blockpig2->add_to_tree(  tree_view, tree_store, tree_selection, &node_iter  );
 	}
@@ -555,9 +555,9 @@
 
 	if ( !strcmp( tag, "PIGMENT" ) )
 		{
-		if ( blockpig1 == NULL ) { blockpig1 = new PovTexPigment( app_ref, false ); blockpig1->load( file, tag ); continue; }
-		if ( blockpig2 == NULL ) { blockpig2 = new PovTexPigment( app_ref, false ); blockpig2->load( file, tag ); continue; }
-		if ( blockpig3 == NULL ) { blockpig3 = new PovTexPigment( app_ref, false ); blockpig3->load( file, tag ); continue; }
+		if ( blockpig1 == NULL ) { blockpig1 = new PovTexPigment( app_ref, NULL, false ); blockpig1->load( file, tag ); continue; }
+		if ( blockpig2 == NULL ) { blockpig2 = new PovTexPigment( app_ref, NULL, false ); blockpig2->load( file, tag ); continue; }
+		if ( blockpig3 == NULL ) { blockpig3 = new PovTexPigment( app_ref, NULL, false ); blockpig3->load( file, tag ); continue; }
 		tvio_skip_section( file );
 		}
 
@@ -641,7 +641,7 @@
 MapItem_pigment::MapItem_pigment( float val, guint8 c, app_objs *appref ) : MapItem( _("Pigment"), val )
 {
 color[0]=color[1]=color[2]=c; color[3]=255;
-pigment = new PovTexPigment( appref, false );
+pigment = new PovTexPigment( appref, NULL, false );
 char text[25];
 sprintf( text, "Map pigment #%u", obj_count++ );
 pigment->set_name( text );
