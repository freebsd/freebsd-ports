--- glib/poppler-action.cc.orig	2020-03-01 19:52:52 UTC
+++ glib/poppler-action.cc
@@ -627,39 +627,39 @@ _poppler_action_new (PopplerDocument *document,
 	switch (link->getKind ()) {
 	case actionGoTo:
 		action->type = POPPLER_ACTION_GOTO_DEST;
-		build_goto_dest (document, action, dynamic_cast <const LinkGoTo *> (link));
+		build_goto_dest (document, action, static_cast <const LinkGoTo *> (link));
 		break;
 	case actionGoToR:
 		action->type = POPPLER_ACTION_GOTO_REMOTE;
-		build_goto_remote (action, dynamic_cast <const LinkGoToR *> (link));
+		build_goto_remote (action, static_cast <const LinkGoToR *> (link));
 		break;
 	case actionLaunch:
 		action->type = POPPLER_ACTION_LAUNCH;
-		build_launch (action, dynamic_cast <const LinkLaunch *> (link));
+		build_launch (action, static_cast <const LinkLaunch *> (link));
 		break;
 	case actionURI:
 		action->type = POPPLER_ACTION_URI;
-		build_uri (action, dynamic_cast <const LinkURI *> (link));
+		build_uri (action, static_cast <const LinkURI *> (link));
 		break;
 	case actionNamed:
 		action->type = POPPLER_ACTION_NAMED;
-		build_named (action, dynamic_cast <const LinkNamed *> (link));
+		build_named (action, static_cast <const LinkNamed *> (link));
 		break;
 	case actionMovie:
 		action->type = POPPLER_ACTION_MOVIE;
-		build_movie (document, action, dynamic_cast<const LinkMovie*> (link));
+		build_movie (document, action, static_cast<const LinkMovie*> (link));
 		break;
 	case actionRendition:
 		action->type = POPPLER_ACTION_RENDITION;
-		build_rendition (action, dynamic_cast<const LinkRendition*> (link));
+		build_rendition (action, static_cast<const LinkRendition*> (link));
 		break;
 	case actionOCGState:
 		action->type = POPPLER_ACTION_OCG_STATE;
-		build_ocg_state (document, action, dynamic_cast<const LinkOCGState*> (link));
+		build_ocg_state (document, action, static_cast<const LinkOCGState*> (link));
 		break;
 	case actionJavaScript:
 		action->type = POPPLER_ACTION_JAVASCRIPT;
-		build_javascript (action, dynamic_cast<const LinkJavaScript*> (link));
+		build_javascript (action, static_cast<const LinkJavaScript*> (link));
 		break;
 	case actionUnknown:
 	default:
