--- src/GUI/GUI_Packer.cpp.orig	2018-07-05 04:58:16 UTC
+++ src/GUI/GUI_Packer.cpp
@@ -85,6 +85,8 @@ void		GUI_Packer::PackPane(GUI_Pane * ch
 		subsize[2] = mPackArea[2];
 		subsize[3] = mPackArea[3];
 		break;
+	default:
+		break;
 	}
 	child->SetBounds(subsize);
 }
@@ -113,6 +115,8 @@ void		GUI_Packer::PackPaneToRight(GUI_Pa
 		subsize[1] = targetsize[3] - subsize[5];
 		mPackArea[3] = min(targetsize[1], subsize[1]);
 		break;
+	default:
+		break;
 	}
 	child->SetBounds(subsize);
 }
