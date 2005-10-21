--- src/density.cc.orig	Tue Oct  4 03:02:24 2005
+++ src/density.cc	Tue Oct 18 18:54:34 2005
@@ -198,9 +198,9 @@
 
 if ( blockdens1 == NULL && type->value() == 1 )
 	{
-	blockdens1 = new PovTexDensity( app_ref, NULL, NULL, false );
-	blockdens2 = new PovTexDensity( app_ref, NULL, NULL, false  );
-	blockdens3 = new PovTexDensity( app_ref, NULL, NULL, false  );
+	blockdens1 = new PovTexDensity( app_ref, NULL, NULL, NULL, false );
+	blockdens2 = new PovTexDensity( app_ref, NULL, NULL, NULL, false  );
+	blockdens3 = new PovTexDensity( app_ref, NULL, NULL, NULL, false  );
 	blockdens1->add_to_tree( tree_view, tree_store, tree_selection, &node_iter );
 	blockdens2->add_to_tree( tree_view, tree_store, tree_selection, &node_iter );
 	}
@@ -479,9 +479,9 @@
 
 	if ( !strcmp( tag, "DENSITY" ) )
 		{
-		if ( blockdens1 == NULL ) { blockdens1 = new PovTexDensity( app_ref, NULL, NULL, false ); blockdens1->load( file, tag ); continue; }
-		if ( blockdens2 == NULL ) { blockdens2 = new PovTexDensity( app_ref, NULL, NULL, false ); blockdens2->load( file, tag ); continue; }
-		if ( blockdens3 == NULL ) { blockdens3 = new PovTexDensity( app_ref, NULL, NULL, false ); blockdens3->load( file, tag ); continue; }
+		if ( blockdens1 == NULL ) { blockdens1 = new PovTexDensity( app_ref, NULL, NULL, NULL, false ); blockdens1->load( file, tag ); continue; }
+		if ( blockdens2 == NULL ) { blockdens2 = new PovTexDensity( app_ref, NULL, NULL, NULL, false ); blockdens2->load( file, tag ); continue; }
+		if ( blockdens3 == NULL ) { blockdens3 = new PovTexDensity( app_ref, NULL, NULL, NULL, false ); blockdens3->load( file, tag ); continue; }
 		tvio_skip_section( file );
 		}
 
@@ -556,7 +556,7 @@
 MapItem_density::MapItem_density( float val, guint8 c, app_objs *appref ) : MapItem( _("Density"), val ) 
 {
 color[0]=color[1]=color[2]=c; color[3]=255; 
-density = new PovTexDensity( appref, NULL, NULL, false );
+density = new PovTexDensity( appref, NULL, NULL, NULL, false );
 char text[25];
 sprintf( text, "Map density #%u", obj_count++ );
 density->set_name( text );
