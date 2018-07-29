--- src/WEDMap/WED_VertexTool.cpp.orig	2018-07-07 01:19:06 UTC
+++ src/WEDMap/WED_VertexTool.cpp
@@ -182,6 +182,8 @@ int		WED_VertexTool::CountControlHandles
 		e = dynamic_cast<IGISEdge *>(en);
 		DebugAssert(e);
 		return e ? 4 : 0;
+	default:
+		break;
 	}
 	return 0;
 }
@@ -460,6 +462,8 @@ void	WED_VertexTool::GetNthControlHandle
 			return;
 		}
 		break;
+	default:
+		break;
 	}	
 	DebugAssert(!"Cast failed!");
 	return;
@@ -497,6 +501,8 @@ int		WED_VertexTool::GetLinks		    (intp
 	case gis_Edge:
 		e = dynamic_cast<IGISEdge*>(en);
 		return e ? 3 : 0;
+	default:
+		break;
 	}
 	return 0;
 }
@@ -533,6 +539,8 @@ void	WED_VertexTool::GetNthLinkInfo		(in
 			if(ltype) *ltype = link_BezierCtrl;
 			if(active) *active = 0;
 		}
+	default:
+		break;
 	}
 }
 
@@ -558,6 +566,8 @@ int		WED_VertexTool::GetNthLinkSource   
 		case 1: return 0;
 		case 2: return 3;
 		}
+	default:
+		break;
 	}
 	return 0;
 }
@@ -575,6 +585,8 @@ int		WED_VertexTool::GetNthLinkSourceCtl
 		case 1: return 0;
 		case 2: return 3;
 		}
+	default:
+		break;
 	}
 	return -1;
 }
@@ -599,6 +611,8 @@ int		WED_VertexTool::GetNthLinkTarget   
 		case 1: return 1;
 		case 2: return 2;
 		}
+	default:
+		break;
 	}
 	return 0;
 }
@@ -616,6 +630,8 @@ int		WED_VertexTool::GetNthLinkTargetCtl
 		case 1: return 1;
 		case 2: return 2;
 		}
+	default:
+		break;
 	}
 	return -1;
 }
@@ -696,6 +712,8 @@ void	WED_VertexTool::ControlsHandlesBy(i
 		case 10:	rwy->SetDisp1(rwy->GetDisp1() + axis.dot(delta_m));	break;
 		case 11:	rwy->SetDisp2(rwy->GetDisp2() + axis.dot(delta_m));	break;
 		case 12:	rwy->SetBlas2(rwy->GetBlas2() + axis.dot(delta_m));	break;
+		default:
+			break;
 		}
 
 		io_pt += delta;
@@ -870,6 +888,8 @@ void	WED_VertexTool::ControlsHandlesBy(i
 			}
 			return;
 		}
+	default:
+		break;
 	}
 	DebugAssert(!"Cast failed!");
 	return;
@@ -1058,6 +1078,8 @@ void		WED_VertexTool::AddEntityRecursive
 				AddEntityRecursive(cmp->GetNthEntity(n),vis_area);
 		}
 		break;
+	default:
+		break;
 	}
 }
 
@@ -1147,6 +1169,8 @@ void		WED_VertexTool::AddSnapPointRecurs
 				AddSnapPointRecursive(cmp->GetNthEntity(n),vis_area, sel);
 		}
 		break;
+	default:
+		break;
 	}
 }
 
