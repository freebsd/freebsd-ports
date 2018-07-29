--- src/GUI/GUI_TextTable.cpp.orig	2018-07-05 05:31:25 UTC
+++ src/GUI/GUI_TextTable.cpp
@@ -295,6 +295,8 @@ void		GUI_TextTable::CellDraw	 (int cell
 	case gui_Cell_CheckBox:
 		c.text_val = "";
 		break;
+	default:
+		break;
 	}
 	
 	if(c.can_delete)
@@ -472,6 +474,8 @@ void		GUI_TextTable::CellDraw	 (int cell
 		glEnd();
 		glLineWidth(1);
 		break;
+	default:
+		break;
 	}
 	glColor4fv(mColorGridlines);
 	//-----------------------------------------------------------------
@@ -765,6 +769,8 @@ int			GUI_TextTable::CellMouseDown(int c
 			mEditInfo.content_type = gui_Cell_None;
 		}
 		break;
+	default:
+		break;
 	}
 	return 1;
 }
@@ -822,6 +828,8 @@ void		GUI_TextTable::CellMouseDrag(int c
 			BroadcastMessage(GUI_TABLE_CONTENT_CHANGED, 0);
 		}
 		break;
+	default:
+		break;
 	}
 }
 
@@ -881,6 +889,8 @@ void		GUI_TextTable::CellMouseUp  (int c
 			BroadcastMessage(GUI_TABLE_CONTENT_CHANGED, 0);
 		}
 		break;
+	default:
+		break;
 	}
 	if (!HasEdit())
 	{
@@ -977,6 +987,8 @@ GUI_DragOperation	GUI_TextTable::CellDra
 				if (mLastOp == gui_Drag_None)	if ((mLastOp = mContent->CanDropBetweenRows(cell_y + (mDragPart == drag_IntoOrHigher ? 1 : 0), drag, allowed, recommended)) != gui_Drag_None)
 													mDragDest = mDragPart == drag_IntoOrHigher ? gui_Insert_Top : gui_Insert_Bottom;
 				break;
+			default:
+				break;
 			}
 		}
 		else
@@ -1008,6 +1020,8 @@ GUI_DragOperation	GUI_TextTable::CellDra
 				if (mLastOp == gui_Drag_None)	if ((mLastOp = mContent->CanDropBetweenColumns(cell_x + (mDragPart == drag_IntoOrHigher ? 1 : 0), drag, allowed, recommended)) != gui_Drag_None)
 													mDragDest = mDragPart == drag_IntoOrHigher ? gui_Insert_Right : gui_Insert_Left;
 				break;
+			default:
+				break;
 			}
 		}
 		else
@@ -1280,6 +1294,8 @@ int			GUI_TextTable::TerminateEdit(bool 
 			case gui_Cell_Double:
 				mEditInfo.double_val = atof(mEditInfo.text_val.c_str());
 				break;
+			default:
+				break;
 			}
 			mContent->AcceptEdit(mClickCellX, mClickCellY, mEditInfo, in_all);
 		}
@@ -1404,6 +1420,8 @@ int			GUI_TextTable::HandleKeyPress(uint
 			}
 		}
 		break;
+	default:
+		break;
 	}
 
 	if(inKey == GUI_KEY_TAB && HasEdit() && mContent)
