--- src/WEDMap/WED_HandleToolBase.cpp.orig	2018-07-05 13:11:22 UTC
+++ src/WEDMap/WED_HandleToolBase.cpp
@@ -513,6 +513,8 @@ int		WED_HandleToolBase::ProcessSelectio
 		if (pt_sel && entity->PtOnFrame(gis_Geo,psel, frame_dist))  { result.insert(entity); return 1; }
 
 		break;
+	default:
+		break;
 	}
 	return 0;
 }
@@ -535,6 +537,8 @@ void		WED_HandleToolBase::HandleClickDra
 			case drag_Handles:				mHandles->ControlsHandlesBy(mHandleEntity,	mHandleIndex,	delta, mTrackPoint);	break;
 			case drag_Links:				mHandles->ControlsLinksBy(mHandleEntity,	mHandleIndex,	delta, mTrackPoint);	break;
 			case drag_Ent:					mHandles->ControlsMoveBy(mHandleEntity,						delta, mTrackPoint);	break;
+		default:
+			break;
 			}
 		}
 		break;
@@ -592,6 +596,8 @@ void		WED_HandleToolBase::HandleClickDra
 			}
 		}
 		break;
+		default:
+			break;
 	}
 }
 
@@ -684,6 +690,8 @@ void		WED_HandleToolBase::DrawStructure	
 					case link_Ghost:		glColor4fv(WED_Color_RGBA(wed_GhostLink));		break;
 					case link_BezierCtrl:	glColor4fv(WED_Color_RGBA(wed_ControlLink));	break;
 					case link_Marquee:		glColor4fv(WED_Color_RGBA(wed_Marquee));		break;
+					default:
+						break;
 					}
 					if (ControlLinkToCurve(mHandles,eid,l,b,s,GetZoomer()))
 					{
@@ -752,6 +760,8 @@ void		WED_HandleToolBase::DrawStructure	
 				case handle_Arrow:			GUI_PlotIcon(g,"handle_arrowhead.png", scrpt.x(),scrpt.y(),atan2(orient.dx,orient.dy) * RAD_TO_DEG,1.0);	break;
 				case handle_RotateHead:
 				case handle_Rotate:			GUI_PlotIcon(g,"handle_rotatehead.png", scrpt.x(),scrpt.y(),atan2(orient.dx,orient.dy) * RAD_TO_DEG,1.0);	break;
+			default:
+				break;
 				}
 			}
 		}
