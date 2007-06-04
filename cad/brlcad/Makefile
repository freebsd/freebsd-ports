# New ports collection makefile for:	brlcad
# Date created:		Jan 2005
# Whom:			Pedro F. Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	brlcad
PORTVERSION=	7.10.0
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	brlcad

MAINTAINER=	erik@smluc.org
COMMENT=	CSG modelling system from the US Ballistic Research Laboratory

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		rle.1:${PORTSDIR}/graphics/urt

USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
USE_GL=		yes
USE_GMAKE=	yes
USE_XLIB=	yes

PREFIX?=	${LOCALBASE}/${PORTNAME}
GNU_CONFIGURE=	yes
NO_MTREE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--enable-tcl-build --enable-tk-build --disable-adrt-build \
	--with-libs="-lpng ${EXTRA_LIBS}" --program-transform-name="" \
	--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/libs \
	--disable-jove-build
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MAN1=	alias-pix.1 all_sf.1 anim_cascade.1 anim_fly.1 anim_hardtrack.1		\
	anim_keyread.1 anim_lookat.1 anim_offset.1 anim_orient.1		\
	anim_script.1 anim_sort.1 anim_time.1 anim_track.1 anim_turn.1		\
	ap-pix.1 asc-nmg.1 asc-pl.1 awf.1 azel.1 bary.1 benchmark.1		\
	bot_shell-vtk.1 brlcad.1 brlman.1 buffer.1 bw-fb.1 bw-imp.1 bw-pix.1	\
	bw-png.1 bw-ps.1 bw-rle.1 bw3-pix.1 bwcrop.1 bwdiff.1 bwfilter.1	\
	bwhist.1 bwhisteq.1 bwmod.1 bwrect.1 bwrot.1 bwscale.1 bwshrink.1	\
	bwstat.1 bwthresh.1 cad_boundp.1 cad_parea.1 cat-fb.1 cell-fb.1		\
	chan_mult.1 chan_permute.1 cmap-fb.1 comgeom-g.1 conv-vg2g.1 cv.1	\
	cy-g.1 dbclean.1 dbcp.1 dbupgrade.1 decimate.1 dpix-pix.1 dunncolor.1	\
	dunnsnap.1 dxf-g.1 enf-g.1 euclid-g.1 fast4-g.1 fb-bw.1 fb-cmap.1	\
	fb-fb.1 fb-orle.1 fb-pix.1 fb-png.1 fb-rle.1 fbanim.1 fbcbars.1		\
	fbclear.1 fbcmap.1 fbcmrot.1 fbcolor.1 fbed.1 fbfade.1 fbframe.1	\
	fbfree.1 fbgamma.1 fbgrid.1 fbhelp.1 fblabel.1 fbline.1 fbpoint.1	\
	fbscanplot.1 fbserv.1 fbstretch.1 fbzoom.1 firpass.1 g-acad.1 g-dxf.1	\
	g-euclid.1 g-iges.1 g-nff.1 g-nmg.1 g-obj.1 g-shell.rect.1 g-stl.1	\
	g-tankill.1 g-var.1 g-vrml.1 g-x3d.1 g2asc.1 g_diff.1 g_lint.1 g_qa.1	\
	gencolor.1 gif-fb.1 gif2fb.1 halftone.1 hd.1 iges-g.1 imgdims.1 ir-X.1	\
	ir-sgi.1 irdisp.1 lgt.1 loop.1 mac-pix.1 mged.1 mk_bolt.1 mk_gastank.1	\
	mk_handle.1 mk_window.1 mk_winfrm.1 mk_wire.1 morphedit.1 nastran-g.1	\
	nirt.1 nmg-bot.1 nmg-rib.1 op-bw.1 orle-fb.1 orle-pix.1 patch-g.1	\
	pcd-pix.1 picket_fence.1 pix-alias.1 pix-bw.1 pix-bw3.1 pix-fb.1	\
	pix-orle.1 pix-png.1 pix-ps.1 pix-rle.1 pix-sun.1 pix2asc.1		\
	pixautosize.1 pixbackgnd.1 pixbgstrip.1 pixblend.1 pixborder.1		\
	pixbustup.1 pixclump.1 pixcolors.1 pixcut.1 pixdiff.1 pixdsplit.1	\
	pixfade.1 pixfilter.1 pixhalve.1 pixhist.1 pixhist3d-pl.1 pixhist3d.1	\
	pixinterp2x.1 pixmatte.1 pixmerge.1 pixmorph.1 pixrect.1 pixrot.1	\
	pixsaturate.1 pixscale.1 pixshrink.1 pixstat.1 pixsubst.1 pixtile.1	\
	pixuntile.1 pl-X.1 pl-X10.1 pl-asc.1 pl-fb.1 pl-hpgl.1 pl-pl.1 pl-ps.1	\
	pl-sgi.1 pl-starbase.1 pl-tek.1 plcolor.1 pldebug.1 plgetframe.1	\
	plline2.1 plrot.1 ply-g.1 png-bw.1 png-fb.1 png-pix.1 png_info.1	\
	polar-fb.1 poly-bot.1 pp-fb.1 proe-g.1 query.1 remrt.1 rle-fb.1		\
	rle-pix.1 rpatch.1 rt.1 rt_bot_faces.1 rtarea.1 rtcheck.1 rtedge.1	\
	rtg3.1 rthide.1 rtpp.1 rtrange.1 rtray.1 rtregis.1 rtscale.1 rtshot.1	\
	rttherm.1 rtwalk.1 rtweight.1 rtxray.1 scriptsort.1 secpass.1		\
	shapefact.1 showshot.1 showtherm.1 ssamp-bw.1 stl-g.1 sun-pix.1		\
	tabinterp.1 tabsub.1 tankill-g.1 tclsh.1 terrain.1 vas4.1 vdeck.1 	\
	viewpoint-g.1 wavelet.1 wish.1 pixcmp.1 enigma.1 canonize.1

MAN3=	Tcl_Access.3 Tcl_AddErrorInfo.3 Tcl_AddObjErrorInfo.3			\
	Tcl_AlertNotifier.3 Tcl_Alloc.3 Tcl_AllocStatBuf.3			\
	Tcl_AllowExceptions.3 Tcl_AppInit.3 Tcl_AppendAllObjTypes.3		\
	Tcl_AppendElement.3 Tcl_AppendExportList.3 Tcl_AppendObjToObj.3		\
	Tcl_AppendResult.3 Tcl_AppendResultVA.3 Tcl_AppendStringsToObj.3	\
	Tcl_AppendStringsToObjVA.3 Tcl_AppendToObj.3 Tcl_AppendUnicodeToObj.3	\
	Tcl_AsyncCreate.3 Tcl_AsyncDelete.3 Tcl_AsyncInvoke.3 Tcl_AsyncMark.3	\
	Tcl_AsyncReady.3 Tcl_AttemptAlloc.3 Tcl_AttemptRealloc.3		\
	Tcl_AttemptSetObjLength.3 Tcl_BackgroundError.3 Tcl_Backslash.3		\
	Tcl_BadChannelOption.3 Tcl_CallWhenDeleted.3 Tcl_CancelIdleCall.3	\
	Tcl_ChannelBlockModeProc.3 Tcl_ChannelBuffered.3			\
	Tcl_ChannelClose2Proc.3 Tcl_ChannelCloseProc.3 Tcl_ChannelFlushProc.3	\
	Tcl_ChannelGetHandleProc.3 Tcl_ChannelGetOptionProc.3			\
	Tcl_ChannelHandlerProc.3 Tcl_ChannelInputProc.3 Tcl_ChannelName.3	\
	Tcl_ChannelOutputProc.3 Tcl_ChannelSeekProc.3				\
	Tcl_ChannelSetOptionProc.3 Tcl_ChannelThreadActionProc.3		\
	Tcl_ChannelTruncateProc.3 Tcl_ChannelVersion.3 Tcl_ChannelWatchProc.3	\
	Tcl_ChannelWideSeekProc.3 Tcl_Chdir.3 Tcl_ClearChannelHandlers.3	\
	Tcl_Close.3 Tcl_CommandComplete.3 Tcl_CommandTraceInfo.3 Tcl_Concat.3	\
	Tcl_ConcatObj.3 Tcl_ConditionFinalize.3 Tcl_ConditionNotify.3		\
	Tcl_ConditionWait.3 Tcl_ConvertCountedElement.3 Tcl_ConvertElement.3	\
	Tcl_ConvertToType.3 Tcl_CreateAlias.3 Tcl_CreateAliasObj.3		\
	Tcl_CreateChannel.3 Tcl_CreateChannelHandler.3 Tcl_CreateCloseHandler.3	\
	Tcl_CreateCommand.3 Tcl_CreateEncoding.3 Tcl_CreateEnsemble.3		\
	Tcl_CreateEventSource.3 Tcl_CreateExitHandler.3 Tcl_CreateFileHandler.3	\
	Tcl_CreateHashEntry.3 Tcl_CreateInterp.3 Tcl_CreateMathFunc.3		\
	Tcl_CreateNamespace.3 Tcl_CreateObjCommand.3 Tcl_CreateObjTrace.3	\
	Tcl_CreateSlave.3 Tcl_CreateThread.3 Tcl_CreateThreadExitHandler.3	\
	Tcl_CreateTimerHandler.3 Tcl_CreateTrace.3 Tcl_CutChannel.3		\
	Tcl_DStringAppend.3 Tcl_DStringAppendElement.3 Tcl_DStringEndSublist.3	\
	Tcl_DStringFree.3 Tcl_DStringGetResult.3 Tcl_DStringInit.3		\
	Tcl_DStringLength.3 Tcl_DStringResult.3 Tcl_DStringSetLength.3		\
	Tcl_DStringStartSublist.3 Tcl_DStringTrunc.3 Tcl_DStringValue.3		\
	Tcl_DecrRefCount.3 Tcl_DeleteAssocData.3 Tcl_DeleteChannelHandler.3	\
	Tcl_DeleteCloseHandler.3 Tcl_DeleteCommand.3				\
	Tcl_DeleteCommandFromToken.3 Tcl_DeleteEventSource.3 Tcl_DeleteEvents.3	\
	Tcl_DeleteExitHandler.3 Tcl_DeleteFileHandler.3 Tcl_DeleteHashEntry.3	\
	Tcl_DeleteHashTable.3 Tcl_DeleteInterp.3 Tcl_DeleteNamespace.3		\
	Tcl_DeleteThreadExitHandler.3 Tcl_DeleteTimerHandler.3			\
	Tcl_DeleteTrace.3 Tcl_DetachChannel.3 Tcl_DetachPids.3			\
	Tcl_DictObjDone.3 Tcl_DictObjFirst.3 Tcl_DictObjGet.3 Tcl_DictObjNext.3	\
	Tcl_DictObjPut.3 Tcl_DictObjPutKeyList.3 Tcl_DictObjRemove.3		\
	Tcl_DictObjRemoveKeyList.3 Tcl_DictObjSize.3 Tcl_DiscardInterpState.3	\
	Tcl_DiscardResult.3 Tcl_DoOneEvent.3 Tcl_DoWhenIdle.3			\
	Tcl_DontCallWhenDeleted.3 Tcl_DumpActiveMemory.3 Tcl_DuplicateObj.3	\
	Tcl_Eof.3 Tcl_ErrnoId.3 Tcl_ErrnoMsg.3 Tcl_Eval.3 Tcl_EvalEx.3		\
	Tcl_EvalFile.3 Tcl_EvalObjEx.3 Tcl_EvalObjv.3 Tcl_EvalTokens.3		\
	Tcl_EvalTokensStandard.3 Tcl_EventuallyFree.3 Tcl_Exit.3		\
	Tcl_ExitThread.3 Tcl_Export.3 Tcl_ExposeCommand.3 Tcl_ExprBoolean.3	\
	Tcl_ExprBooleanObj.3 Tcl_ExprDouble.3 Tcl_ExprDoubleObj.3		\
	Tcl_ExprLong.3 Tcl_ExprLongObj.3 Tcl_ExprObj.3 Tcl_ExprString.3		\
	Tcl_ExternalToUtf.3 Tcl_ExternalToUtfDString.3 Tcl_FSAccess.3		\
	Tcl_FSChdir.3 Tcl_FSConvertToPathType.3 Tcl_FSCopyDirectory.3		\
	Tcl_FSCopyFile.3 Tcl_FSCreateDirectory.3 Tcl_FSData.3			\
	Tcl_FSDeleteFile.3 Tcl_FSEqualPaths.3 Tcl_FSEvalFile.3				\
	Tcl_FSEvalFileEx.3 Tcl_FSFileAttrStrings.3 Tcl_FSFileAttrsGet.3		\
	Tcl_FSFileAttrsSet.3 Tcl_FSFileSystemInfo.3 Tcl_FSGetCwd.3		\
	Tcl_FSGetFileSystemForPath.3 Tcl_FSGetInternalRep.3			\
	Tcl_FSGetNativePath.3 Tcl_FSGetNormalizedPath.3 Tcl_FSGetPathType.3	\
	Tcl_FSGetTranslatedPath.3 Tcl_FSGetTranslatedStringPath.3		\
	Tcl_FSJoinPath.3 Tcl_FSJoinToPath.3 Tcl_FSLink.3 Tcl_FSListVolumes.3	\
	Tcl_FSLoadFile.3 Tcl_FSLstat.3 Tcl_FSMatchInDirectory.3			\
	Tcl_FSMountsChanged.3 Tcl_FSNewNativePath.3 Tcl_FSOpenFileChannel.3	\
	Tcl_FSPathSeparator.3 Tcl_FSRegister.3 Tcl_FSRemoveDirectory.3		\
	Tcl_FSRenameFile.3 Tcl_FSSplitPath.3 Tcl_FSStat.3 Tcl_FSUnregister.3	\
	Tcl_FSUtime.3 Tcl_Finalize.3 Tcl_FinalizeNotifier.3			\
	Tcl_FinalizeThread.3 Tcl_FindCommand.3 Tcl_FindEnsemble.3		\
	Tcl_FindExecutable.3 Tcl_FindHashEntry.3 Tcl_FindNamespace.3		\
	Tcl_FirstHashEntry.3 Tcl_Flush.3 Tcl_ForgetImport.3 Tcl_Free.3		\
	Tcl_FreeEncoding.3 Tcl_FreeParse.3 Tcl_FreeResult.3 Tcl_GetAlias.3	\
	Tcl_GetAliasObj.3 Tcl_GetAssocData.3 Tcl_GetBignumAndClearObj.3		\
	Tcl_GetBignumFromObj.3 Tcl_GetBoolean.3 Tcl_GetBooleanFromObj.3		\
	Tcl_GetByteArrayFromObj.3 Tcl_GetChannel.3 Tcl_GetChannelBufferSize.3	\
	Tcl_GetChannelError.3 Tcl_GetChannelErrorInterp.3			\
	Tcl_GetChannelHandle.3 Tcl_GetChannelInstanceData.3			\
	Tcl_GetChannelMode.3 Tcl_GetChannelName.3 Tcl_GetChannelNames.3		\
	Tcl_GetChannelNamesEx.3 Tcl_GetChannelOption.3 Tcl_GetChannelThread.3	\
	Tcl_GetChannelType.3 Tcl_GetCharLength.3 Tcl_GetCommandFromObj.3	\
	Tcl_GetCommandFullName.3 Tcl_GetCommandInfo.3				\
	Tcl_GetCommandInfoFromToken.3 Tcl_GetCommandName.3			\
	Tcl_GetCurrentNamespace.3 Tcl_GetCurrentThread.3 Tcl_GetCwd.3		\
	Tcl_GetDefaultEncodingDir.3 Tcl_GetDouble.3 Tcl_GetDoubleFromObj.3	\
	Tcl_GetEncoding.3 Tcl_GetEncodingFromObj.3 Tcl_GetEncodingName.3	\
	Tcl_GetEncodingNameFromEnvironment.3 Tcl_GetEncodingNames.3		\
	Tcl_GetEncodingSearchPath.3 Tcl_GetEnsembleFlags.3			\
	Tcl_GetEnsembleMappingDict.3 Tcl_GetEnsembleNamespace.3			\
	Tcl_GetEnsembleSubcommandList.3 Tcl_GetEnsembleUnknownHandler.3		\
	Tcl_GetErrno.3 Tcl_GetGloblaNamespace.3 Tcl_GetHashKey.3		\
	Tcl_GetHashValue.3 Tcl_GetHostName.3 Tcl_GetIndexFromObj.3		\
	Tcl_GetIndexFromObjStruct.3 Tcl_GetInt.3 Tcl_GetIntFromObj.3		\
	Tcl_GetInterpPath.3 Tcl_GetLongFromObj.3 Tcl_GetMaster.3		\
	Tcl_GetMathFuncInfo.3 Tcl_GetNameOfExecutable.3				\
	Tcl_GetNamespaceUnknownHandler.3 Tcl_GetObjResult.3 Tcl_GetObjType.3	\
	Tcl_GetOpenFile.3 Tcl_GetPathType.3 Tcl_GetRange.3			\
	Tcl_GetRegExpFromObj.3 Tcl_GetReturnOptions.3 Tcl_GetServiceMode.3	\
	Tcl_GetSlave.3 Tcl_GetStackedChannel.3 Tcl_GetStdChannel.3		\
	Tcl_GetString.3 Tcl_GetStringFromObj.3 Tcl_GetStringResult.3		\
	Tcl_GetThreadData.3 Tcl_GetTime.3 Tcl_GetTopChannel.3 Tcl_GetUniChar.3	\
	Tcl_GetUnicode.3 Tcl_GetUnicodeFromObj.3 Tcl_GetVar.3 Tcl_GetVar2.3	\
	Tcl_GetVar2Ex.3 Tcl_GetVersion.3 Tcl_GetWideIntFromObj.3 Tcl_Gets.3	\
	Tcl_GetsObj.3 Tcl_GlobalEval.3 Tcl_GlobalEvalObj.3 Tcl_HashStats.3	\
	Tcl_HideCommand.3 Tcl_Import.3 Tcl_IncrRefCount.3 Tcl_Init.3		\
	Tcl_InitCustomHashTable.3 Tcl_InitHashTable.3 Tcl_InitMemory.3		\
	Tcl_InitNotifier.3 Tcl_InitObjHashTable.3 Tcl_InitStubs.3		\
	Tcl_InputBlocked.3 Tcl_InputBuffered.3 Tcl_Interp.3 Tcl_InterpDeleted.3	\
	Tcl_InvalidateStringRep.3 Tcl_IsChannelExisting.3			\
	Tcl_IsChannelRegistered.3 Tcl_IsChannelShared.3 Tcl_IsEnsemble.3	\
	Tcl_IsSafe.3 Tcl_IsShared.3 Tcl_IsStandardChannel.3 Tcl_JoinPath.3	\
	Tcl_JoinThread.3 Tcl_LimitAddHandler.3 Tcl_LimitCheck.3			\
	Tcl_LimitExceeded.3 Tcl_LimitGetCommands.3 Tcl_LimitGetGranularity.3	\
	Tcl_LimitGetTime.3 Tcl_LimitReady.3 Tcl_LimitRemoveHandler.3		\
	Tcl_LimitSetCommands.3 Tcl_LimitSetGranularity.3 Tcl_LimitSetTime.3	\
	Tcl_LimitTypeEnabled.3 Tcl_LimitTypeExceeded.3 Tcl_LimitTypeReset.3	\
	Tcl_LimitTypeSet.3 Tcl_LinkVar.3 Tcl_ListMathFuncs.3			\
	Tcl_ListObjAppendElement.3 Tcl_ListObjAppendList.3			\
	Tcl_ListObjGetElements.3 Tcl_ListObjIndex.3 Tcl_ListObjLength.3		\
	Tcl_ListObjReplace.3 Tcl_LogCommandInfo.3 Tcl_MakeFileChannel.3		\
	Tcl_MakeSafe.3 Tcl_MakeTcpClientChannel.3 Tcl_Merge.3			\
	Tcl_MutexFinalize.3 Tcl_MutexLock.3 Tcl_MutexUnlock.3			\
	Tcl_NewBignumObj.3 Tcl_NewBooleanObj.3 Tcl_NewByteArrayObj.3		\
	Tcl_NewDictObj.3 Tcl_NewDoubleObj.3 Tcl_NewIntObj.3 Tcl_NewListObj.3	\
	Tcl_NewLongObj.3 Tcl_NewObj.3 Tcl_NewStringObj.3 Tcl_NewUnicodeObj.3	\
	Tcl_NewWideIntObj.3 Tcl_NextHashEntry.3 Tcl_NotifyChannel.3		\
	Tcl_NumUtfChars.3 Tcl_ObjGetVar2.3 Tcl_ObjSetVar2.3			\
	Tcl_OpenCommandChannel.3 Tcl_OpenFileChannel.3 Tcl_OpenTcpClient.3	\
	Tcl_OpenTcpServer.3 Tcl_OutputBuffered.3 Tcl_Panic.3 Tcl_PanicVA.3	\
	Tcl_ParseBraces.3 Tcl_ParseCommand.3 Tcl_ParseExpr.3			\
	Tcl_ParseQuotedString.3 Tcl_ParseVar.3 Tcl_ParseVarName.3		\
	Tcl_PkgPresent.3 Tcl_PkgPresentEx.3 Tcl_PkgProvide.3 Tcl_PkgProvideEx.3	\
	Tcl_PkgRequire.3 Tcl_PkgRequireEx.3 Tcl_PkgRequireProc.3		\
	Tcl_PosixError.3 Tcl_Preserve.3 Tcl_PrintDouble.3 Tcl_PutEnv.3		\
	Tcl_QueryTimeProc.3 Tcl_QueueEvent.3 Tcl_Read.3 Tcl_ReadChars.3		\
	Tcl_ReadRaw.3 Tcl_Realloc.3 Tcl_ReapDetachedProcs.3 Tcl_RecordAndEval.3	\
	Tcl_RecordAndEvalObj.3 Tcl_RegExpCompile.3 Tcl_RegExpExec.3		\
	Tcl_RegExpExecObj.3 Tcl_RegExpGetInfo.3 Tcl_RegExpMatch.3		\
	Tcl_RegExpMatchObj.3 Tcl_RegExpRange.3 Tcl_RegisterChannel.3		\
	Tcl_RegisterConfig.3 Tcl_RegisterObjType.3 Tcl_Release.3		\
	Tcl_ResetResult.3 Tcl_RestoreInterpState.3 Tcl_RestoreResult.3		\
	Tcl_SaveInterpState.3 Tcl_SaveResult.3 Tcl_ScanCountedElement.3		\
	Tcl_ScanElement.3 Tcl_Seek.3 Tcl_ServiceAll.3 Tcl_ServiceEvent.3	\
	Tcl_SetAssocData.3 Tcl_SetBignumObj.3 Tcl_SetBooleanObj.3		\
	Tcl_SetByteArrayLength.3 Tcl_SetByteArrayObj.3				\
	Tcl_SetChannelBufferSize.3 Tcl_SetChannelError.3			\
	Tcl_SetChannelErrorInterp.3 Tcl_SetChannelOption.3 Tcl_SetCommandInfo.3	\
	Tcl_SetCommandInfoFromToken.3 Tcl_SetDefaultEncodingDir.3		\
	Tcl_SetDoubleObj.3 Tcl_SetEncodingSearchPath.3 Tcl_SetEnsembleFlags.3	\
	Tcl_SetEnsembleMappingDict.3 Tcl_SetEnsembleSubcommandList.3		\
	Tcl_SetEnsembleUnknownHandler.3 Tcl_SetErrno.3 Tcl_SetErrorCode.3	\
	Tcl_SetErrorCodeVA.3 Tcl_SetExitProc.3 Tcl_SetHashValue.3		\
	Tcl_SetIntObj.3 Tcl_SetListObj.3 Tcl_SetLongObj.3 Tcl_SetMainLoop.3	\
	Tcl_SetMaxBlockTime.3 Tcl_SetNamespaceUnknownHandler.3			\
	Tcl_SetObjErrorCode.3 Tcl_SetObjLength.3 Tcl_SetObjResult.3		\
	Tcl_SetPanicProc.3 Tcl_SetRecursionLimit.3 Tcl_SetResult.3		\
	Tcl_SetReturnOptions.3 Tcl_SetServiceMode.3 Tcl_SetStdChannel.3		\
	Tcl_SetStringObj.3 Tcl_SetSystemEncoding.3 Tcl_SetTimeProc.3		\
	Tcl_SetTimer.3 Tcl_SetUnicodeObj.3 Tcl_SetVar.3 Tcl_SetVar2.3		\
	Tcl_SetVar2Ex.3 Tcl_SetWideIntObj.3 Tcl_SignalId.3 Tcl_SignalMsg.3	\
	Tcl_Sleep.3 Tcl_SourceRCFile.3 Tcl_SpliceChannel.3 Tcl_SplitList.3	\
	Tcl_SplitPath.3 Tcl_StackChannel.3 Tcl_StandardChannels.3 Tcl_Stat.3	\
	Tcl_StaticPackage.3 Tcl_StringCaseMatch.3 Tcl_StringMatch.3		\
	Tcl_SubstObj.3 Tcl_Tell.3 Tcl_ThreadAlert.3 Tcl_ThreadQueueEvent.3	\
	Tcl_TraceCommand.3 Tcl_TraceVar.3 Tcl_TraceVar2.3			\
	Tcl_TranslateFileName.3 Tcl_TruncateChannel.3 Tcl_Ungets.3		\
	Tcl_UniChar.3 Tcl_UniCharAtIndex.3 Tcl_UniCharCaseMatch.3		\
	Tcl_UniCharIsAlnum.3 Tcl_UniCharIsAlpha.3 Tcl_UniCharIsControl.3	\
	Tcl_UniCharIsDigit.3 Tcl_UniCharIsGraph.3 Tcl_UniCharIsLower.3		\
	Tcl_UniCharIsPrint.3 Tcl_UniCharIsPunct.3 Tcl_UniCharIsSpace.3		\
	Tcl_UniCharIsUpper.3 Tcl_UniCharIsWordChar.3 Tcl_UniCharLen.3		\
	Tcl_UniCharNcasecmp.3 Tcl_UniCharNcmp.3 Tcl_UniCharToLower.3		\
	Tcl_UniCharToTitle.3 Tcl_UniCharToUpper.3 Tcl_UniCharToUtf.3		\
	Tcl_UniCharToUtfDString.3 Tcl_UnlinkVar.3 Tcl_UnregisterChannel.3	\
	Tcl_UnsetVar.3 Tcl_UnsetVar2.3 Tcl_UnstackChannel.3			\
	Tcl_UntraceCommand.3 Tcl_UntraceVar.3 Tcl_UntraceVar2.3 Tcl_UpVar.3	\
	Tcl_UpVar2.3 Tcl_UpdateLinkedVar.3 Tcl_UtfAtIndex.3 Tcl_UtfBackslash.3	\
	Tcl_UtfCharComplete.3 Tcl_UtfFindFirst.3 Tcl_UtfFindLast.3		\
	Tcl_UtfNext.3 Tcl_UtfPrev.3 Tcl_UtfToExternal.3				\
	Tcl_UtfToExternalDString.3 Tcl_UtfToLower.3 Tcl_UtfToTitle.3		\
	Tcl_UtfToUniChar.3 Tcl_UtfToUniCharDString.3 Tcl_UtfToUpper.3		\
	Tcl_ValidateAllMemory.3 Tcl_VarEval.3 Tcl_VarEvalVA.3			\
	Tcl_VarTraceInfo.3 Tcl_VarTraceInfo2.3 Tcl_WaitForEvent.3 Tcl_WaitPid.3	\
	Tcl_WinTCharToUtf.3 Tcl_WinUtfToTChar.3 Tcl_Write.3 Tcl_WriteChars.3	\
	Tcl_WriteObj.3 Tcl_WriteRaw.3 Tcl_WrongNumArgs.3 Tk_3DBorderColor.3	\
	Tk_3DBorderGC.3 Tk_3DHorizontalBevel.3 Tk_3DVerticalBevel.3		\
	Tk_AddOption.3 Tk_Alloc3DBorderFromObj.3 Tk_AllocBitmapFromObj.3	\
	Tk_AllocColorFromObj.3 Tk_AllocCursorFromObj.3 Tk_AllocFontFromObj.3	\
	Tk_AttachHWND.3 Tk_Attributes.3 Tk_BindEvent.3				\
	Tk_CanvasDrawableCoords.3 Tk_CanvasEventuallyRedraw.3			\
	Tk_CanvasGetCoord.3 Tk_CanvasPsBitmap.3 Tk_CanvasPsColor.3		\
	Tk_CanvasPsFont.3 Tk_CanvasPsPath.3 Tk_CanvasPsStipple.3 Tk_CanvasPsY.3	\
	Tk_CanvasSetStippleOrigin.3 Tk_CanvasTagsOption.3 Tk_CanvasTextInfo.3	\
	Tk_CanvasTkwin.3 Tk_CanvasWindowCoords.3 Tk_ChangeWindowAttributes.3	\
	Tk_Changes.3 Tk_CharBbox.3 Tk_Class.3 Tk_ClearSelection.3		\
	Tk_ClipboardAppend.3 Tk_ClipboardClear.3 Tk_CollapseMotionEvents.3	\
	Tk_Colormap.3 Tk_ComputeTextLayout.3 Tk_ConfigureInfo.3			\
	Tk_ConfigureValue.3 Tk_ConfigureWidget.3 Tk_ConfigureWindow.3		\
	Tk_CoordsToWindow.3 Tk_CreateBinding.3 Tk_CreateBindingTable.3		\
	Tk_CreateClientMessageHandler.3 Tk_CreateErrorHandler.3			\
	Tk_CreateEventHandler.3 Tk_CreateGenericHandler.3 Tk_CreateImageType.3	\
	Tk_CreateItemType.3 Tk_CreateOptionTable.3 Tk_CreatePhotoImageFormat.3	\
	Tk_CreateSelHandler.3 Tk_CreateWindow.3 Tk_CreateWindowFromPath.3	\
	Tk_DefineBitmap.3 Tk_DefineCursor.3 Tk_DeleteAllBindings.3		\
	Tk_DeleteBinding.3 Tk_DeleteBindingTable.3				\
	Tk_DeleteClientMessageHandler.3 Tk_DeleteErrorHandler.3			\
	Tk_DeleteEventHandler.3 Tk_DeleteGenericHandler.3 Tk_DeleteImage.3	\
	Tk_DeleteOptionTable.3 Tk_DeleteSelHandler.3 Tk_Depth.3			\
	Tk_DestroyWindow.3 Tk_Display.3 Tk_DisplayName.3			\
	Tk_DistanceToTextLayout.3 Tk_Draw3DPolygon.3 Tk_Draw3DRectangle.3	\
	Tk_DrawChars.3 Tk_DrawFocusHighlight.3 Tk_DrawTextLayout.3		\
	Tk_Fill3DPolygon.3 Tk_Fill3DRectangle.3 Tk_FindPhoto.3 Tk_FontId.3	\
	Tk_Free3DBorder.3 Tk_Free3DBorderFromObj.3 Tk_FreeBitmap.3		\
	Tk_FreeBitmapFromObj.3 Tk_FreeColor.3 Tk_FreeColorFromObj.3		\
	Tk_FreeColormap.3 Tk_FreeConfigOptions.3 Tk_FreeCursor.3		\
	Tk_FreeCursorFromObj.3 Tk_FreeFont.3 Tk_FreeFontFromObj.3 Tk_FreeGC.3	\
	Tk_FreeImage.3 Tk_FreeOptions.3 Tk_FreePixmap.3 Tk_FreeSavedOptions.3	\
	Tk_FreeTextLayout.3 Tk_FreeXId.3 Tk_GeometryRequest.3 Tk_Get3DBorder.3	\
	Tk_Get3DBorderFromObj.3 Tk_GetAllBindings.3 Tk_GetAnchor.3		\
	Tk_GetAnchorFromObj.3 Tk_GetAtomName.3 Tk_GetBinding.3 Tk_GetBitmap.3	\
	Tk_GetBitmapFromObj.3 Tk_GetCapStyle.3 Tk_GetColor.3			\
	Tk_GetColorByValue.3 Tk_GetColorFromObj.3 Tk_GetColormap.3		\
	Tk_GetCursor.3 Tk_GetCursorFromData.3 Tk_GetCursorFromObj.3		\
	Tk_GetDash.3 Tk_GetFont.3 Tk_GetFontFromObj.3 Tk_GetFontMetrics.3	\
	Tk_GetGC.3 Tk_GetHINSTANCE.3 Tk_GetHWND.3 Tk_GetImage.3			\
	Tk_GetImageMasterData.3 Tk_GetItemTypes.3 Tk_GetJoinStyle.3		\
	Tk_GetJustify.3 Tk_GetJustifyFromObj.3 Tk_GetMMFromObj.3		\
	Tk_GetNumMainWindows.3 Tk_GetOption.3 Tk_GetOptionInfo.3		\
	Tk_GetOptionValue.3 Tk_GetPixels.3 Tk_GetPixelsFromObj.3 Tk_GetPixmap.3	\
	Tk_GetRelief.3 Tk_GetReliefFromObj.3 Tk_GetRootCoords.3			\
	Tk_GetScreenMM.3 Tk_GetScrollInfo.3 Tk_GetScrollInfoObj.3		\
	Tk_GetSelection.3 Tk_GetUid.3 Tk_GetUserInactiveTime.3			\
	Tk_GetVRootGeometry.3 Tk_GetVisual.3 Tk_Grab.3 Tk_HWNDToWindow.3	\
	Tk_HandleEvent.3 Tk_Height.3 Tk_IdToWindow.3 Tk_ImageChanged.3		\
	Tk_InitImageArgs.3 Tk_InitOptions.3 Tk_InitStubs.3 Tk_InternAtom.3	\
	Tk_InternalBorderBottom.3 Tk_InternalBorderLeft.3			\
	Tk_InternalBorderRight.3 Tk_InternalBorderTop.3 Tk_Interp.3		\
	Tk_IntersectTextLayout.3 Tk_IsContainer.3 Tk_IsEmbedded.3 Tk_IsMapped.3	\
	Tk_IsTopLevel.3 Tk_MainLoop.3 Tk_MainWindow.3 Tk_MaintainGeometry.3	\
	Tk_MakeWindowExist.3 Tk_ManageGeometry.3 Tk_MapWindow.3			\
	Tk_MeasureChars.3 Tk_MinReqHeight.3 Tk_MinReqWidth.3			\
	Tk_MoveResizeWindow.3 Tk_MoveToplevelWindow.3 Tk_MoveWindow.3 Tk_Name.3	\
	Tk_NameOf3DBorder.3 Tk_NameOfAnchor.3 Tk_NameOfBitmap.3			\
	Tk_NameOfCapStyle.3 Tk_NameOfColor.3 Tk_NameOfCursor.3 Tk_NameOfFont.3	\
	Tk_NameOfImage.3 Tk_NameOfJoinStyle.3 Tk_NameOfJustify.3		\
	Tk_NameOfRelief.3 Tk_NameToWindow.3 Tk_Offset.3 Tk_OwnSelection.3	\
	Tk_Parent.3 Tk_ParseArgv.3 Tk_PathName.3 Tk_PhotoBlank.3		\
	Tk_PhotoExpand.3 Tk_PhotoGetImage.3 Tk_PhotoGetSize.3			\
	Tk_PhotoPutBlock.3 Tk_PhotoPutZoomedBlock.3 Tk_PhotoSetSize.3		\
	Tk_PointToChar.3 Tk_PostscriptFontName.3 Tk_QueueWindowEvent.3		\
	Tk_RedrawImage.3 Tk_ReqHeight.3 Tk_ReqWidth.3				\
	Tk_ResetUserInactiveTime.3 Tk_ResizeWindow.3 Tk_RestackWindow.3		\
	Tk_RestoreSavedOptions.3 Tk_RestrictEvents.3 Tk_SafeInit.3 Tk_Screen.3	\
	Tk_ScreenNumber.3 Tk_SetAppName.3 Tk_SetBackgroundFromBorder.3		\
	Tk_SetCaretPos.3 Tk_SetClass.3 Tk_SetClassProcs.3 Tk_SetGrid.3		\
	Tk_SetInternalBorder.3 Tk_SetInternalBorderEx.3				\
	Tk_SetMinimumRequestSize.3 Tk_SetOptions.3 Tk_SetWindowBackground.3	\
	Tk_SetWindowBackgroundPixmap.3 Tk_SetWindowBorder.3			\
	Tk_SetWindowBorderPixmap.3 Tk_SetWindowBorderWidth.3			\
	Tk_SetWindowColormap.3 Tk_SetWindowVisual.3 Tk_SizeOfBitmap.3		\
	Tk_SizeOfImage.3 Tk_StrictMotif.3 Tk_TextLayoutToPostscript.3		\
	Tk_TextWidth.3 Tk_Uid.3 Tk_UndefineCursor.3 Tk_UnderlineChars.3		\
	Tk_UnderlineTextLayout.3 Tk_Ungrab.3 Tk_UnmaintainGeometry.3		\
	Tk_UnmapWindow.3 Tk_UnsetGrid.3 Tk_Visual.3 Tk_Width.3 Tk_WindowId.3	\
	Tk_X.3 Tk_Y.3 attemptckalloc.3 attemptckrealloc.3 ckalloc.3 ckfree.3	\
	ckrealloc.3 TCL_MEM_DEBUG.3 Tk_Init.3 htond.3 libcursor.3 liborle.3	\
	librt.3 redblack.3 Tcl_Main.3 Tk_Main.3 libbu.3 libfb.3 libplot3.3	\
	libwdb.3

MAN5=	bw.5 cmap.5 pix.5 plot3.5

MANN=	Archetype.n SafeBase.n Tcl.n Toplevel.n Widget.n after.n append.n	\
	apply.n array.n auto_execok.n auto_import.n auto_load.n auto_mkindex.n	\
	auto_mkindex_old.n auto_qualify.n auto_reset.n bell.n bgerror.n		\
	binary.n bind.n bindtags.n bitmap.n body.n break.n button.n canvas.n	\
	case.n catch.n cd.n chan.n checkbutton.n class.n clipboard.n clock.n	\
	close.n code.n colors.n concat.n configbody.n console.n continue.n	\
	cursors.n dde.n delete.n destroy.n dict.n encoding.n ensemble.n entry.n	\
	eof.n error.n eval.n event.n exec.n exit.n expr.n fblocked.n		\
	fconfigure.n fcopy.n file.n fileevent.n filename.n find.n flush.n	\
	focus.n font.n for.n foreach.n format.n frame.n gets.n glob.n global.n	\
	grab.n grid.n history.n http.n if.n image.n incr.n info.n interp.n is.n	\
	itcl.n itclvars.n itk.n itkvars.n iwidgets_buttonbox.n			\
	iwidgets_calendar.n iwidgets_canvasprintbox.n				\
	iwidgets_canvasprintdialog.n iwidgets_checkbox.n iwidgets_combobox.n	\
	iwidgets_dateentry.n iwidgets_datefield.n iwidgets_dialog.n		\
	iwidgets_dialogshell.n iwidgets_disjointlistbox.n iwidgets_entryfield.n	\
	iwidgets_extbutton.n iwidgets_extfileselectionbox.n			\
	iwidgets_extfileselectiondialog.n iwidgets_feedback.n			\
	iwidgets_fileselectionbox.n iwidgets_fileselectiondialog.n		\
	iwidgets_finddialog.n iwidgets_hierarchy.n iwidgets_hyperhelp.n		\
	iwidgets_labeledframe.n iwidgets_labeledwidget.n iwidgets_mainwindow.n	\
	iwidgets_menubar.n iwidgets_messagebox.n iwidgets_messagedialog.n	\
	iwidgets_notebook.n iwidgets_optionmenu.n iwidgets_panedwindow.n	\
	iwidgets_promptdialog.n iwidgets_pushbutton.n iwidgets_radiobox.n	\
	iwidgets_scopedobject.n iwidgets_scrolledcanvas.n			\
	iwidgets_scrolledframe.n iwidgets_scrolledhtml.n			\
	iwidgets_scrolledlistbox.n iwidgets_scrolledtext.n			\
	iwidgets_selectionbox.n iwidgets_selectiondialog.n iwidgets_shell.n	\
	iwidgets_spindate.n iwidgets_spinint.n iwidgets_spinner.n		\
	iwidgets_spintime.n iwidgets_tabnotebook.n iwidgets_tabset.n		\
	iwidgets_timeentry.n iwidgets_timefield.n iwidgets_toolbar.n		\
	iwidgets_watch.n join.n keysyms.n label.n labelframe.n lappend.n	\
	lassign.n lindex.n linsert.n list.n listbox.n llength.n load.n loadTk.n	\
	local.n lower.n lrange.n lrepeat.n lreplace.n lsearch.n lset.n lsort.n	\
	mathfunc.n memory.n menu.n menubutton.n message.n msgcat.n namespace.n	\
	open.n option.n options.n pack-old.n pack.n package.n panedwindow.n	\
	parray.n photo.n pid.n pkg::create.n pkg_mkIndex.n place.n proc.n	\
	puts.n pwd.n radiobutton.n raise.n re_syntax.n read.n reflectedchan.n	\
	regexp.n registry.n regsub.n rename.n return.n scale.n scan.n scope.n	\
	scrollbar.n seek.n selection.n send.n set.n socket.n source.n spinbox.n	\
	split.n string.n subst.n switch.n tcl_endOfWord.n tcl_findLibrary.n	\
	tcl_startOfNextWord.n tcl_startOfPreviousWord.n tcl_wordBreakAfter.n	\
	tcl_wordBreakBefore.n tcltest.n tclvars.n tell.n text.n time.n tk.n	\
	tk_bindForTraversal.n tk_bisque.n tk_chooseColor.n tk_chooseDirectory.n	\
	tk_dialog.n tk_focusFollowsMouse.n tk_focusNext.n tk_focusPrev.n	\
	tk_getOpenFile.n tk_getSaveFile.n tk_menuBar.n tk_menuSetFocus.n	\
	tk_messageBox.n tk_optionMenu.n tk_popup.n tk_setPalette.n		\
	tk_textCopy.n tk_textCut.n tk_textPaste.n tkerror.n tkvars.n tkwait.n	\
	tm.n toplevel.n trace.n unknown.n unload.n unset.n update.n uplevel.n	\
	upvar.n usual.n variable.n vwait.n while.n winfo.n wm.n

OPTIONS=	OPTIMIZATION "Try building with optimizations" on

.include <bsd.port.pre.mk>

EXTRA_LIBS=	${PTHREAD_LIBS}

.if !(${ARCH} == i386 || ${ARCH} == amd64 || ${ARCH} == sparc64)
IGNORE=		dumps core on ${ARCH}
.endif

.ifdef WITH_OPTIMIZATION
CONFIGURE_ARGS+=	--disable-debug
.if (${ARCH} == i386 || ${ARCH} == amd64 || ${ARCH} == sparc64)
CONFIGURE_ARGS+=	--enable-optimized
.endif
.endif

post-patch:
	${REINPLACE_CMD} "s+/usr/X11R6+${X11BASE}+" ${WRKSRC}/configure

pre-install:
	${CP} ${FILESDIR}/mged.sh ${WRKSRC}
	${REINPLACE_CMD} -e 's+%%BRLCAD_ROOT%%+${PREFIX}+g;'	\
		${WRKSRC}/mged.sh

# note that installing outside of PREFIX wigs out package stuff... :/
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mged.sh ${PREFIX}/bin/mged.sh
	${LN} -s ${PREFIX}/bin/mged.sh ${LOCALBASE}/bin/mged.sh
.if defined(WITH_OPTIMIZATION) && !(${ARCH} == i386 || ${ARCH} == amd64)
	@echo "Optimization does not work here, but we went ahead and turned off debugging"
.endif

.if defined(WITH_OPTIMIZATION) && !(${ARCH} == i386 || ${ARCH} == amd64)
post-build:
	@echo "Optimization does not work here, but we went ahead and turned off debugging"
.endif

.include <bsd.port.post.mk>
