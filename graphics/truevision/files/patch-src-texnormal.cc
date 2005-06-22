--- src/texnormal.cc.orig	Wed Feb 23 22:32:55 2005
+++ src/texnormal.cc	Wed Mar 16 22:27:11 2005
@@ -197,9 +197,9 @@
 
 if ( normal1 == NULL && type->value() == 1  )
 	{
-	normal1 = new PovTexNormal( app_ref, false );
-	normal2 = new PovTexNormal( app_ref, false );
-	normal3 = new PovTexNormal( app_ref, false );
+	normal1 = new PovTexNormal( app_ref, NULL, false );
+	normal2 = new PovTexNormal( app_ref, NULL, false );
+	normal3 = new PovTexNormal( app_ref, NULL, false );
 	normal1->add_to_tree( ctree, ctree_node );
 	normal2->add_to_tree( ctree, ctree_node );
 	}
@@ -524,9 +524,9 @@
 
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
 
@@ -613,7 +613,7 @@
 MapItem_normal::MapItem_normal( float val, guint8 c, app_objs *appref ) : MapItem( _("Normal"), val ) 
 {
 color[0]=color[1]=color[2]=c; color[3]=255; 
-normal = new PovTexNormal( appref, false );
+normal = new PovTexNormal( appref, NULL, false );
 char text[25];
 sprintf( text, "Map normal #%u", obj_count++ );
 normal->set_name( text );
