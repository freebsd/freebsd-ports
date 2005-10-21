--- src/texnormal.cc.orig	Tue Oct  4 02:54:01 2005
+++ src/texnormal.cc	Tue Oct 18 18:56:50 2005
@@ -199,9 +199,9 @@
 
 if ( normal1 == NULL && type->value() == 1  )
 	{
-	normal1 = new PovTexNormal( app_ref, false );
-	normal2 = new PovTexNormal( app_ref, false );
-	normal3 = new PovTexNormal( app_ref, false );
+	normal1 = new PovTexNormal( app_ref, NULL, false );
+	normal2 = new PovTexNormal( app_ref, NULL, false );
+	normal3 = new PovTexNormal( app_ref, NULL, false );
 	normal1->add_to_tree( tree_view, tree_store, tree_selection, &node_iter );
 	normal2->add_to_tree( tree_view, tree_store, tree_selection, &node_iter );
 	}
@@ -528,9 +528,9 @@
 
 	if ( !strcmp( tag, "NORMAL" ) )
 		{
-		if ( normal1 == NULL ) { normal1 = new PovTexNormal( app_ref, false ); normal1->load( file, tag ); continue; }
-		if ( normal2 == NULL ) { normal2 = new PovTexNormal( app_ref, false ); normal2->load( file, tag ); continue; }
-		if ( normal3 == NULL ) { normal3 = new PovTexNormal( app_ref, false ); normal3->load( file, tag ); continue; }
+		if ( normal1 == NULL ) { normal1 = new PovTexNormal( app_ref, NULL, false ); normal1->load( file, tag ); continue; }
+		if ( normal2 == NULL ) { normal2 = new PovTexNormal( app_ref, NULL, false ); normal2->load( file, tag ); continue; }
+		if ( normal3 == NULL ) { normal3 = new PovTexNormal( app_ref, NULL, false ); normal3->load( file, tag ); continue; }
 		tvio_skip_section( file );
 		}
 
@@ -614,7 +614,7 @@
 MapItem_normal::MapItem_normal( float val, guint8 c, app_objs *appref ) : MapItem( _("Normal"), val ) 
 {
 color[0]=color[1]=color[2]=c; color[3]=255; 
-normal = new PovTexNormal( appref, false );
+normal = new PovTexNormal( appref, NULL, false );
 char text[25];
 sprintf( text, "Map normal #%u", obj_count++ );
 normal->set_name( text );
