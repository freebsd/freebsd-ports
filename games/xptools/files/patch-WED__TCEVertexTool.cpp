--- src/WEDTCE/WED_TCEVertexTool.cpp.orig	2018-07-07 14:23:29 UTC
+++ src/WEDTCE/WED_TCEVertexTool.cpp
@@ -156,6 +156,8 @@ void		WED_TCEVertexTool::GetNthControlHa
 			}
 		}
 		break;
+		default:
+			break;
 	}
 }
 
@@ -329,6 +331,8 @@ void		WED_TCEVertexTool::ControlsHandles
 			}
 		}
 		break;
+		default:
+			break;
 	}
 
 	// now that we used TCE to modify the UVmaping, update UVbounds
@@ -355,6 +359,8 @@ void		WED_TCEVertexTool::ControlsLinksBy
 			p2->GetLocation(gis_UV,p);			p += delta;			p2->SetLocation(gis_UV,p);
 		}
 		break;
+		default:
+			break;
 	}
 	// now that we used TCE to modify the UVmaping, update UVbounds
 	updateUVbounds(who);
@@ -413,6 +419,8 @@ void	WED_TCEVertexTool::SyncRecurse(IGIS
 		if((c = dynamic_cast<IGISComposite *>(who)) != NULL)
 		for(int n = 0; n < c->GetNumEntities(); ++n)
 			SyncRecurse(c->GetNthEntity(n),sel);
+	default:
+		break;
 	}
 }
 
