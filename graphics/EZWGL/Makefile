# New ports collection makefile for:	EZWGL
# Version required:			1.39
# Date created:				4 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/07/23 15:37:05 asami Exp $
#

DISTNAME=	EZWGL-1.39
CATEGORIES=	graphics devel x11
MASTER_SITES=	ftp://ftp.ma.utexas.edu/pub/mzou/
DISTFILES=	${DISTNAME}-src.tgz ${DISTNAME}-doc.tgz

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg

ALL_TARGET=	shared clean static
USE_X11=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}

MAN3=	EZ.3 EZ_ActivateNoteBookPage.3 EZ_ActivateWidget.3 \
	EZ_AddEventHandler.3 EZ_AddInput.3 EZ_AddItemCallBack.3 \
	EZ_AddMessageHandler.3 EZ_AddWidgetCallBack.3 \
	EZ_AllocateColorFromName.3 EZ_AutoSelectBackBuffer.3 EZ_Begin.3 \
	EZ_CMove2f.3 EZ_CMove3f.3 EZ_CallList.3 EZ_CallWidgetCallbacks.3 \
	EZ_Clear.3 EZ_ClearColorf.3 EZ_ClearLcd.3 EZ_ClearListBox.3 \
	EZ_Color3f.3 EZ_ColorMapMode.3 EZ_ColorMaterial.3 EZ_ComputeItemSize.3 \
	EZ_ConfigureItem.3 EZ_ConfigureWidget.3 \
	EZ_CopyMatrix.3 EZ_CopyTransposeMatrix.3 EZ_CopyVector.3 \
	EZ_CreateCursorFromBitmapFile.3 EZ_CreateDirTree.3 EZ_CreateGLImage.3 \
	EZ_CreateItem.3 EZ_CreateLabelPixmapFromImageFile.3 \
	EZ_CreateSimpleMenu.3 EZ_CreateTimer.3 EZ_CreateTreeNode.3 \
	EZ_CreateWidget.3 EZ_CreateXPixmapFromImageFile.3 EZ_Cube.3 \
	EZ_CullFace.3 EZ_DefineLightModel.3 EZ_DefineLightSrc.3 \
	EZ_DefineMaterial.3 EZ_DeleteList.3 EZ_DestroyItem.3 EZ_DestroyWidget.3 \
	EZ_DestroyWidgetWindows.3 EZ_DisableBubbleHelp.3 EZ_DisableHighlight.3 \
	EZ_DisableImageDithering.3 EZ_DisableLabelOffset.3 \
	EZ_DisableSliderDepression.3 EZ_DisableWidget.3 \
	EZ_DisableWidgetTree.3 EZ_DisplayWidget.3 \
	EZ_DnDGetDragConversionTargets.3 \
	EZ_DnDGetMatchedConversionTargets.3 \
	EZ_DoPopup.3 EZ_DrawBuffer.3 EZ_DrawString.3 EZ_DrawWidget.3 \
	EZ_Enable.3 EZ_EnterEvent.3 EZ_EntryEditBackward.3 EZ_EventMainLoop.3 \
	EZ_FancyListBoxClear.3 EZ_FancyListBoxFindItemAtXY.3 \
	EZ_FancyListBoxFindRowAtXY.3 EZ_FlashWidgetBorder.3 EZ_Fogfv.3 \
	EZ_FreezeWidget.3 EZ_FrontFace.3 EZ_Frustum.3 EZ_GLNextEvent.3 \
	EZ_GLResetEvents.3 EZ_GenLists.3 EZ_GenerateRotationMatrix.3 \
	EZ_Get3DCanvasSize.3 EZ_GetAndUseWidgetResources.3 \
	EZ_GetApplicationResource.3 EZ_GetAtom.3 \
	EZ_GetBubbleHelp.3 EZ_GetCheckButtonState.3 EZ_GetCursor.3 \
	EZ_GetDefaultMaterial.3 EZ_GetDirTreeNodeFullPath.3 EZ_GetDisplay.3 \
	EZ_GetDnDDragSrcXYOffset.3 \
	EZ_GetDnDDropLocation.3 EZ_GetFancyListBoxItemUsingIdx.3 \
	EZ_GetFancyListBoxData.3 EZ_GetFancyListBoxNumberOfRows.3 \
	EZ_GetFancyListBoxNumberofRows.3 EZ_GetFancyListBoxSelection.3 \
	EZ_GetFancyListBoxSelectionIdx.3 EZ_GetFancyListBoxWidgetComponents.3 \
	EZ_GetFancyListBoxXYOffset.3 EZ_GetFileSelectorComponents.3 \
	EZ_GetFileSelectorSelection.3 \
	EZ_GetFontFromId.3 EZ_GetFontName.3 EZ_GetGLImageInfo.3 \
	EZ_GetInstanceName.3 EZ_GetItemClientData.3 \
	EZ_GetItemUnknownData.3 EZ_GetItemWidth.3 \
	EZ_GetLabelItemStringInfo.3 \
	EZ_GetLabelPixmapInfo.3 EZ_GetLedString.c EZ_GetListBoxSelection.3 \
	EZ_GetListBoxWidgetComponents.3 EZ_GetListTreeWidgetComponents.3 \
	EZ_GetListTreeWidgetSelection.3 EZ_GetListTreeWidgetTree.3 \
	EZ_GetListTreeWidgetXYOffset.3 EZ_GetMatrix.3 \
	EZ_GetNoteBookPageTab.3 EZ_GetNumberOfAllocatedColors.3 \
	EZ_GetOptionalEntryWidgetComponents.3 EZ_GetParentWidget.3 \
	EZ_GetRadioButtonGroupID.3 \
	EZ_GetRadioButtonGroupVariableValue.3 EZ_GetScrollbarState.3 \
	EZ_GetSliderValue.3 EZ_GetTextProperty.3 EZ_GetTextWidgetComponents.3 \
	EZ_GetTimerClientData.3 EZ_GetTimerState.3 EZ_GetWidgetAbsoluteGeometry.3 \
	EZ_GetWidgetGeometry.3 EZ_GetWidgetIntData.3 EZ_GetWidgetItemWidget.3 \
	EZ_GetWidgetResource.3 EZ_GetWidgetReturnData.3 \
	EZ_GetWidgetUnknownData.3 EZ_GetWidgetWindow.3 \
	EZ_GetWorkAreaItemUsingIdx.3 EZ_GetWorkAreaNumberOfItems.3 \
	EZ_GetWorkAreaSelection.3 EZ_GetWorkAreaWidgetComponents.3 \
	EZ_GetWorkAreaXYOffset.3 EZ_GetWritableGC.3 \
	EZ_GlobFileName.3 EZ_GlobFiles.3 EZ_GlobHiddenFiles.3 \
	EZ_GrabPointer.3 EZ_HideWidget.3 EZ_IdentityMatrix.3 EZ_Index.3 \
	EZ_Initialize.3 EZ_InsertWidgetAfter.3 EZ_InstallSymbol.3 \
	EZ_InstallSymbolicFloat.3 EZ_InstallSymbolicInt.3 \
	EZ_InstallSymbolicPointer.3 EZ_InstallSymbolicULong.3 \
	EZ_InverseTranspose.3 EZ_InvertMatrix.3 EZ_IsList.3 \
	EZ_ItemAddDnDDataDecoder.3 EZ_ItemExist.3 \
	EZ_LabelItemSetProperty.3 EZ_LedIsFree.3 \
	EZ_LibraryVersion.3 EZ_LightModelf.3 EZ_Lightf.3 \
	EZ_ListTreeFindNodeAtXY.3 EZ_ListTreeWidgetSelectNode.3 \
	EZ_ListTreeWidgetSelectNodeUsingItem.3 \
	EZ_LoadIdentity.3 EZ_LoadMatrix.3 EZ_LoadXFont.3 EZ_LogicOp.3 \
	EZ_LookAt.3 EZ_Malloc.3 EZ_MapColor.3 EZ_Materialf.3 EZ_MatrixMode.3 \
	EZ_MenuBarAddItemAndMenu.3 EZ_MenuBarDeleteItem.3 \
	EZ_MenuBarDeleteItemAndMenu.3 EZ_MenuBarFindItem.3 \
	EZ_MenuBarFindItemAndMenu.3 EZ_MenuBarInsertItemAndMenu.3 \
	EZ_MenuBarSetItemMenu.3 EZ_MultMatrix.3 EZ_MultiplyMatrix.3 \
	EZ_NewList.3 EZ_Normal3f.3 EZ_OnOffSecretEntry.3 \
	EZ_OptionEntryClearOptions.3 EZ_Ortho.3 EZ_Ortho2.3 \
	EZ_Perspective.3 EZ_PolygonMode.3 EZ_PopMatrix.3 \
	EZ_PrintStandardOptions.3 EZ_PushMatrix.3 EZ_PutGLImage.3 \
	EZ_QueueLedAction.3 EZ_RegisterWidget.3 EZ_RemoveEvent.3 \
	EZ_RemoveWidget.3 EZ_Rotate.3 \
	EZ_Save3DCanvas2PPMImage.3 EZ_Save3DCanvas2PS.3 EZ_Scale.3 \
	EZ_SendMessage.3 EZ_Set3DCanvas.3 EZ_SetApplicationName.3 \
	EZ_SetBackBuffer.3 EZ_SetBitmapFont.3 EZ_SetClientMessageHandler.3 \
	EZ_SetDefaultEntryTextFont.3 EZ_SetDefaultMessageHandler.3 \
	EZ_SetDirTreeDefaultPixmaps.3 EZ_SetDirTreeDirectoryNodeCreator.3 \
	EZ_SetDirTreeOpenDirectoryMode.3 EZ_SetEntryString.3 \
	EZ_SetFancyListBoxData.3 EZ_SetFancyListBoxHeader.3 \
	EZ_SetFileSelectorInitialPattern.3 EZ_SetFocusTo.3 \
	EZ_SetGlobalForeground.3 EZ_SetGlobalBackground.3 \
	EZ_SetGrab.3 EZ_SetHScrollbarDiscreteSpeed.3 \
	EZ_SetKbdHighlightColor.3 EZ_SetLcdBackground.3 EZ_SetLcdFontSize.3 \
	EZ_SetLcdInteger.3 EZ_SetLcdNDigits.3 EZ_SetLcdString.3 \
	EZ_SetLedBackground.3 EZ_SetLedColorFunction.3 EZ_SetLedFont.3 \
	EZ_SetLedPixelSize.3 EZ_SetLedSize.3 EZ_SetLedString.3 \
	EZ_SetListBoxItems.3 EZ_SetListTreeWidgetTree.3 EZ_SetMenuButtonMenu.3 \
	EZ_SetOptionalEntryOptionalItems.3 EZ_SetOptionalEntryString.3 \
	EZ_SetScrollbarDiscreteSpeed.3 EZ_SetSliderRange.3 \
	EZ_SetStatusMeterBackground.3 EZ_SetStatusMeterForeground.3 \
	EZ_SetStatusMeterRange.3 EZ_SetStatusMeterValue.3 EZ_SetSubMenuMenu.3 \
	EZ_SetTimerCallBack.3 EZ_SetTimerClientData.3 EZ_SetVectorFont.3 \
	EZ_SetWidgetCallBack.3 EZ_SetWidgetCINames.3 \
	EZ_SetWidgetLabelString.3 EZ_SetWidgetPosition.3 \
	EZ_SetWorkAreaGeometryManager.3 EZ_ShadeModel.3 EZ_Shutdown.3 \
	EZ_SitForALittleBit.3 EZ_Sphere.3 EZ_StartAsIcon.3 EZ_StopStatusMeter.3 \
	EZ_SwapBuffers.3 EZ_TextEndOfLine.3 EZ_TextGetBufferString.3 \
	EZ_TiePopupMenu.3 EZ_TileExpand.3 EZ_Translate.3 \
	EZ_TreeAttachSubtree.3 \
	EZ_TreeDestroyNodeDescendants.3 EZ_TreeDestroySubtree.3 \
	EZ_TreeFindNode.3 EZ_TreeFindNodeUsingItem.3 EZ_TreeNodeGetChildren.3 \
	EZ_TreeNodeGetItem.3 EZ_TreeSetBGColor.3 EZ_TreeSetCharacter.3 \
	EZ_TreeTraverseTree.3 EZ_Tube.3 EZ_UpdateDirTreeWidget.3 EZ_Vertex3f.3 \
	EZ_WaitCursor.3 EZ_WarpPointer.3 EZ_WidgetAddDnDDataDecoder.3 \
	EZ_WidgetExist.3 EZ_WidgetIsViewable.3 EZ_WindowIsWidgetWindow.3 \
	EZ_WorkAreaClear.3 EZ_WorkAreaFindItemAtXY.3

pre-install:
	@ ${RM} ${WRKSRC}/examples/Makefile.orig
	@ ${RM} ${WRKSRC}/examples/ExampleMsg

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/include/EZ.h ${PREFIX}/include
	@ ${INSTALL_DATA} ${WRKSRC}/lib/libEZ.a ${PREFIX}/lib
	@ ${INSTALL_DATA} ${WRKSRC}/lib/libEZ.so.1.3 ${PREFIX}/lib
	@ ln -s ${PREFIX}/lib/libEZ.so.1.3 ${PREFIX}/lib/libEZ.so
	@ ln -s ${PREFIX}/lib/libEZ.so.1.3 ${PREFIX}/lib/libEZ.so.1
.for file in ${MAN3}
	@ ${INSTALL_MAN} ${WRKSRC}/man3/${file} ${PREFIX}/man/man3
	@ ${RM} ${WRKSRC}/man3/${file}
.endfor
.for file in \
	EZ_AllocateColorFromRGB.3 EZ_AppendListBoxItem.3 EZ_BindLightSrc.3 \
	EZ_BindMaterial.3 EZ_BroadcastMessage.3 EZ_CMove3fv.3 \
	EZ_CMoveScreen3f.3 EZ_CMoveScreen3fv.3 EZ_CallLists.3 \
	EZ_CallWidgetMotionCallbacks.3 \
	EZ_CancelTimer.3 EZ_ClearIndex.3 EZ_Color3fv.3 EZ_Color4f.3 \
	EZ_Color4fv.3 EZ_CreateCursorFromBitmapData.3 \
	EZ_CreateLabelPixmapFromXBitmapData.3 \
	EZ_CreateLabelPixmapFromXBitmapFile.3 \
	EZ_CreateLabelPixmapFromXpmData.3 \
	EZ_CreateLabelPixmapFromXpmFile.3 EZ_CreateWidgetXrm.3 \
	EZ_CreateXPixmapFromBitmapFile.3 EZ_CreateXPixmapFromXpmData.3 \
	EZ_CreateXPixmapFromXpmFile.3 EZ_DeActivateWidget.3 \
	EZ_DeleteListBoxItem.3 EZ_DeleteLists.3 EZ_DeleteMessageHandler.3 \
	EZ_Disable.3 EZ_DoPopupAt.3 EZ_Dodecahedron.3 EZ_EnableBubbleHelp.3 \
	EZ_EnableHighlight.3 EZ_EnableImageDithering.3 EZ_EnableLableOffset.3 \
	EZ_EnableSliderDepression.3 EZ_EnableWidget.3 EZ_EnableWidgetTree.3 \
	EZ_EndList.3 EZ_EntryEditBackwardWord.3 EZ_EntryEditBeginOfInput.3 \
	EZ_EntryEditDeleteChar.3 EZ_EntryEditEndOfInput.3 EZ_EntryEditForeward.3 \
	EZ_EntryEditForwardWord.3 EZ_EntryEditInsertString.3 \
	EZ_EntryEditKillEndOfLine.3 EZ_EntryEditKillRegion.3 \
	EZ_EntryEditSetMarker.3 EZ_EntryPasteSelection.3 \
	EZ_FancyListBoxDeleteRow.3 EZ_FancyListBoxInsertRow.3 \
	EZ_FancyListBoxReplaceItem.3 EZ_FancyListBoxReplaceItemUsingIdx.3 \
	EZ_FancyListBoxSelectItem.3 EZ_FancyListBoxSelectItemUsingIdx.3 \
	EZ_Free.3 EZ_FreeGLImage.3 EZ_FreeLabelPixmap.3 EZ_FreeXPixmap.3 \
	EZ_GLEnterEvent.3 EZ_GetApplicationName.3 EZ_GetChildrenWidget.3 \
	EZ_GetClassName.3 EZ_GetColormap.3 \
	EZ_GetCursorByName.3 EZ_GetDepth.3 EZ_GetDisplayInfo.3 \
	EZ_GetEntryString.3 EZ_GetFancyListBoxNumberOfColumns.3 \
	EZ_GetFontFromName.3 EZ_GetItemDimension.3 EZ_GetItemHeight.3 \
	EZ_GetItemIntData.3 EZ_GetItemPosition.3 EZ_GetItemPtrData.3 \
	EZ_GetItemUnknownDataPtr.3 EZ_GetListBoxSelectedItem.3 \
	EZ_GetListBoxSelectionLineNumber.3 EZ_GetNumberOfReservedColorsForGL.3 \
	EZ_GetScreen.3 EZ_GetSelectedMenuItem.3 EZ_GetSiblingWidget.3 \
	EZ_GetTimerIntData.3 EZ_GetTimerPtrData.3 EZ_GetVisual.3 \
	EZ_GetWidgetBorderWidth.3 EZ_GetWidgetClientData.3 \
	EZ_GetWidgetCINames.3 EZ_GetWidgetDimension.3 EZ_GetWidgetHeight.3 \
	EZ_GetWidgetLabelPosition.3 EZ_GetWidgetLabelString.3 \
	EZ_GetWidgetMinHeight.3 EZ_GetWidgetMinWidth.3 \
	EZ_GetWidgetPosition.3 EZ_GetWidgetPtrData.3 \
	EZ_GetWidgetUnknownDataPtr.3 EZ_GetWidgetWidth.3 \
	EZ_Icosahedron.3 EZ_InitializeXrm.3 EZ_InsertListBoxItem.3 \
	EZ_InsertWidgetBefore.3 EZ_ItemAddDnDDataEncoder.3 \
	EZ_ItemDeleteAllDnDDataDecoders.3 EZ_ItemDeleteAllDnDDataEncoders.3 \
	EZ_ItemDeleteDnDDataDecoder.3 EZ_ItemDeleteDnDDataEncoder.3 \
	EZ_LightModelfv.3 EZ_Lightfv.3 EZ_ListBoxSelectItem.3 \
	EZ_ListBoxSelectItemUsingIdx.3 EZ_Materialfv.3 EZ_ModifyListBoxItem.3 \
	EZ_Normal3fv.3 EZ_NormalCursor.3 EZ_Octahedron.3 \
	EZ_OptionEntryAppendOption.3 EZ_OptionEntryDeleteOption.3 \
	EZ_PixelValue2RGB.3 EZ_PutGLImageScreen.3 EZ_PutGLImageWindow.3 \
	EZ_PutGLImageXWindow.3 EZ_RGBMode.3 EZ_ReleaseGrab.3 \
	EZ_RemoveAllEventHandlers.3 EZ_RemoveAllItemCallBacks.3 \
	EZ_RemoveAllWidgetCallBacks.3 EZ_RemoveEventHandler.3 \
	EZ_RemoveInput.3 EZ_RemoveItemCallBack.3 \
	EZ_RemoveLedAction.3 EZ_RemoveWidgetCallBack.3 EZ_ReplyMessage.3 \
	EZ_ResetTimer.3 EZ_RetrieveSymbol.3 EZ_RetrieveSymbolicFloat.3 \
	EZ_RetrieveSymbolicInt.3 EZ_RetrieveSymbolicPointer.3 \
	EZ_RetrieveSymbolicULong.3 EZ_Save3DCanvas2PSA.3 EZ_ServiceEvents.3 \
	EZ_SetCheckButtonState.3 EZ_SetDefaultLabelFont.3 \
	EZ_SetDefaultMenuTitleFont.3 EZ_SetDirTreeDefaultPixmapsFromXpmFiles.3 \
	EZ_SetDirTreeFileNodeCreator.3 EZ_SetFancyListBoxXYOffset.3 \
	EZ_SetForeground.3 EZ_SetItemClientData.3 \
	EZ_SetItemDimension.3 EZ_SetItemHeight.3 EZ_SetItemIntData.3 \
	EZ_SetItemPosition.3 EZ_SetItemPtrData.3 EZ_SetItemUnknownData.3 \
	EZ_SetItemWidth.3 EZ_SetKbdHighlightColorRGB.3 EZ_SetLcdFloat.3 \
	EZ_SetLcdForeground.3 EZ_SetLedHeight.3 EZ_SetLedWidth.3 \
	EZ_SetListTreeWidgetXYOffset.3 EZ_SetOffPixelColor.3 \
	EZ_SetRadioButtonGroupVariableValue.3 EZ_SetSliderValue.3 \
	EZ_SetStatusMeterForegroundN.3 EZ_SetStatusMeterRangeN.3 \
	EZ_SetStatusMeterValueN.3 EZ_SetTimerIntData.3 EZ_SetTimerPtrData.3 \
	EZ_SetVScrollbarDiscreteSpeed.3 EZ_SetWidgetClientData.3 \
	EZ_SetWidgetHeight.3 EZ_SetWidgetIntData.3 EZ_SetWidgetPtrData.3 \
	EZ_SetWidgetUnknownData.3 EZ_SetWidgetWidth.3 EZ_SetWorkAreaXYOffset.3 \
	EZ_StartStatusMeter.3 EZ_SwapWidgets.3 EZ_Tetrahedron.3 \
	EZ_TextBackwardChar.3 EZ_TextBackwardWord.3 \
	EZ_TextBeginningOfBuffer.3 EZ_TextBeginningOfLine.3 EZ_TextClear.3 \
	EZ_TextDeleteNextChar.3 EZ_TextDeletePreviousChar.3 EZ_TextEndOfBuffer.3 \
	EZ_TextForwardChar.3 EZ_TextForwardWord.3 EZ_TextGetPosition.3 \
	EZ_TextGetRegionString.3 EZ_TextGotoPosition.3 EZ_TextInsertChar.3 \
	EZ_TextInsertNewLine.3 EZ_TextInsertString.3 \
	EZ_TextInsertStringWithProperty.3 EZ_TextKillEndOfLine.3 \
	EZ_TextKillRegion.3 EZ_TextLoadAnnotatedFile.3 EZ_TextLoadFile.3 \
	EZ_TextNextLine.3 EZ_TextNextPage.3 EZ_TextPasteSelection.3 \
	EZ_TextPreviousLine.3 EZ_TextPreviousPage.3 EZ_TextReDisplay.3 \
	EZ_TextReplaceRegionWithPixmap.3 EZ_TextSaveAnnotatedText.3 \
	EZ_TextSaveText.3 EZ_TextSetMarker.3 EZ_TextSetRegionBackground.3 \
	EZ_TextSetRegionFont.3 EZ_TextSetRegionForeground.3 \
	EZ_TextSetRegionProperty.3 EZ_TextSetRegionUnderline.3 \
	EZ_TreeDetachSubtree.3 EZ_TreeNodeGetParent.3 EZ_TreeNodeGetSibling.3 \
	EZ_UnFreezeWidget.3 EZ_UngrabPointer.3 EZ_UpdateScrollbar.3 \
	EZ_Vertex2f.3 EZ_Vertex2fv.3 EZ_Vertex3fv.3 EZ_WaitAndServiceNextEvent.3 \
	EZ_WidgetAddDnDDataEncoder.3 EZ_WidgetDeleteAllDnDDataDecoders.3 \
	EZ_WidgetDeleteAllDnDDataEncoders.3 EZ_WidgetDeleteDnDDataDecoder.3 \
	EZ_WidgetDeleteDnDDataEncoder.3 EZ_WorkAreaDeleteItem.3 \
	EZ_WorkAreaDeleteItemUsingIdx.3 EZ_WorkAreaInsertItem.3 \
	EZ_WorkAreaInsertItemAfter.3 EZ_WorkAreaInsertItemBefore.3 \
	EZ_WorkAreaInsertItemUsingIdx.3 EZ_WorkAreaRearrange.3 \
	EZ_WorkAreaSelectItem.3 EZ_WorkAreaSelectItemUsingIdx.3 EZ_ZeroMatrix.3
	@ cd ${WRKSRC}/man3; ln -s ${PREFIX}/man/man3/`ls -l ${file} | ${AWK} '{print $$11}'`.gz ${PREFIX}/man/man3/${file}.gz
	@ ${RM} ${WRKSRC}/man3/${file}
.endfor
	@ ${MKDIR} ${PREFIX}/share/examples/EZ
	@ ${MKDIR} ${PREFIX}/share/examples/EZ/pixmaps
	@ ${INSTALL_DATA} ${WRKSRC}/examples/pixmaps/* ${PREFIX}/share/examples/EZ/pixmaps
	@ ${RM} -rf ${WRKSRC}/examples/pixmaps
	@ ${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/EZ
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/EZ
	@ ${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/EZ
	@ cd ${WRKSRC}; tar cf - html ps | (cd ${PREFIX}/share/doc/EZ; tar xf - )
.endif

.include <bsd.port.mk>
