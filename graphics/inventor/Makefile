# New ports collection makefile for:   OpenInventor
# Date created: 	14 December 2002
# Whom: 		Christian Gusenbauer
#
# $FreeBSD$
#

PORTNAME=	inventor
PORTVERSION=	2.1.5.p10
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	ftp://oss.sgi.com/projects/inventor/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/-/}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	c47g@gmx.at
COMMENT=	This is SGI's Open Inventor (TM)

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		GLU.1:${PORTSDIR}/graphics/libGLU

USE_XORG=	x11 xi
USE_GL=		glw
USE_GMAKE=	yes
USE_ICONV=	yes
USE_MOTIF=	yes
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/lib:${WRKSRC}/libSoXt
MAKEFILE=	GNUmakefile

.if defined(WITH_DEBUG)
MAKE_ENV+=	LIBTYPE=debug
PKGNAMESUFFIX=	-debug
.endif

MAN1=	SceneViewer.1 inventor.1 iv2toiv1.1 ivcat.1 ivdowngrade.1 ivfix.1 ivinfo.1 ivview.1

MAN3=	SoAction.3iv SoCallbackAction.3iv SoGLRenderAction.3iv \
	SoGetBoundingBoxAction.3iv SoGetMatrixAction.3iv \
	SoHandleEventAction.3iv SoPickAction.3iv SoRayPickAction.3iv \
	SoSearchAction.3iv SoWriteAction.3iv SbBool.3iv SbBox2f.3iv \
	SbBox2s.3iv SbBox3f.3iv SbColor.3iv SbCylinder.3iv SbLine.3iv \
	SbMatrix.3iv SbName.3iv SbPList.3iv SbPlane.3iv SbRotation.3iv \
	SbSphere.3iv SbString.3iv SbTime.3iv SbVec2f.3iv SbVec2s.3iv \
	SbVec3f.3iv SbVec4f.3iv SbViewVolume.3iv SbViewportRegion.3iv \
	SbXfBox3f.3iv SoXt.3iv SoXtClipboard.3iv SoXtComponent.3iv \
	SoXtDirectionalLightEditor.3iv SoXtGLWidget.3iv \
	SoXtLightSliderSet.3iv SoXtMaterialEditor.3iv SoXtMaterialList.3iv \
	SoXtMaterialSliderSet.3iv SoXtPrintDialog.3iv SoXtRenderArea.3iv \
	SoXtResource.3iv SoXtSliderSet.3iv SoXtSliderSetBase.3iv \
	SoXtTransformSliderSet.3iv SoConeDetail.3iv SoCubeDetail.3iv \
	SoCylinderDetail.3iv SoDetail.3iv SoDetailList.3iv SoFaceDetail.3iv \
	SoLineDetail.3iv SoNodeKitDetail.3iv SoPointDetail.3iv \
	SoTextDetail.3iv SoXtDevice.3iv SoXtInputFocus.3iv SoXtKeyboard.3iv \
	SoXtMouse.3iv SoXtSpaceball.3iv SoCenterballDragger.3iv \
	SoDirectionalLightDragger.3iv SoDragPointDragger.3iv SoDragger.3iv \
	SoHandleBoxDragger.3iv SoJackDragger.3iv SoPointLightDragger.3iv \
	SoRotateCylindricalDragger.3iv SoRotateDiscDragger.3iv \
	SoRotateSphericalDragger.3iv SoGate.3iv SoScale1Dragger.3iv \
	SoScale2Dragger.3iv SoScale2UniformDragger.3iv \
	SoScaleUniformDragger.3iv SoSpotLightDragger.3iv SoTabBoxDragger.3iv \
	SoTabPlaneDragger.3iv SoTrackballDragger.3iv \
	SoTransformBoxDragger.3iv SoTransformerDragger.3iv \
	SoTranslate1Dragger.3iv SoTranslate2Dragger.3iv SoBoolOperation.3iv \
	SoCalculator.3iv SoComposeMatrix.3iv SoComposeRotation.3iv \
	SoComposeRotationFromTo.3iv SoComposeVec2f.3iv SoComposeVec3f.3iv \
	SoComposeVec4f.3iv SoComputeBoundingBox.3iv SoConcatenate.3iv \
	SoCounter.3iv SoDecomposeMatrix.3iv SoDecomposeRotation.3iv \
	SoDecomposeVec2f.3iv SoDecomposeVec3f.3iv SoDecomposeVec4f.3iv \
	SoElapsedTime.3iv SoEngine.3iv SoEngineList.3iv SoEngineOutput.3iv \
	SoEngineOutputList.3iv SoInterpolate.3iv SoInterpolateFloat.3iv \
	SoInterpolateRotation.3iv SoInterpolateVec2f.3iv \
	SoInterpolateVec3f.3iv SoInterpolateVec4f.3iv SoOnOff.3iv \
	SoOneShot.3iv SoSelectOne.3iv SoTimeCounter.3iv SoTransformVec3f.3iv \
	SoTriggerAny.3iv SoDebugError.3iv SoError.3iv SoMemoryError.3iv \
	SoReadError.3iv SoButtonEvent.3iv SoEvent.3iv SoKeyboardEvent.3iv \
	SoLocation2Event.3iv SoMotion3Event.3iv SoMouseButtonEvent.3iv \
	SoSpaceballButtonEvent.3iv SoField.3iv SoFieldContainer.3iv \
	SoFieldList.3iv SoMFBitMask.3iv SoMFBool.3iv SoMFColor.3iv \
	SoMFEngine.3iv SoMFEnum.3iv SoMFFloat.3iv SoMFInt32.3iv SoMFLong.3iv \
	SoMFMatrix.3iv SoMFName.3iv SoMFNode.3iv SoMFPath.3iv SoMFPlane.3iv \
	SoMFRotation.3iv SoMFShort.3iv SoMFString.3iv SoMFTime.3iv \
	SoMFUInt32.3iv SoMFULong.3iv SoMFUShort.3iv SoMFVec2f.3iv \
	SoMFVec3f.3iv SoMFVec4f.3iv SoMField.3iv SoSFBitMask.3iv SoSFBool.3iv \
	SoSFColor.3iv SoSFEngine.3iv SoSFEnum.3iv SoSFFloat.3iv SoSFImage.3iv \
	SoSFInt32.3iv SoSFLong.3iv SoSFMatrix.3iv SoSFName.3iv SoSFNode.3iv \
	SoSFPath.3iv SoSFPlane.3iv SoSFRotation.3iv SoSFShort.3iv \
	SoSFString.3iv SoSFTime.3iv SoSFTrigger.3iv SoSFUInt32.3iv \
	SoSFULong.3iv SoSFUShort.3iv SoSFVec2f.3iv SoSFVec3f.3iv SoSFVec4f.3iv \
	SoSField.3iv SoBase.3iv SoBaseList.3iv SoByteStream.3iv \
	SoCallbackList.3iv SoDB.3iv SoInput.3iv SoNodeKitPath.3iv \
	SoNodeList.3iv SoOffscreenRenderer.3iv SoOutput.3iv SoPath.3iv \
	SoPathList.3iv SoPickedPoint.3iv SoPickedPointList.3iv \
	SoPrimitiveVertex.3iv SoTranReceiver.3iv SoTranSender.3iv SoType.3iv \
	SoTypeList.3iv SoBoxHighlightRenderAction.3iv SoEventCallback.3iv \
	SoInteraction.3iv SoLineHighlightRenderAction.3iv SoSceneManager.3iv \
	SoSelection.3iv SoCenterballManip.3iv SoDirectionalLightManip.3iv \
	SoHandleBoxManip.3iv SoJackManip.3iv SoPointLightManip.3iv \
	SoSpotLightManip.3iv SoTabBoxManip.3iv SoTrackballManip.3iv \
	SoTransformBoxManip.3iv SoTransformManip.3iv SoTransformerManip.3iv \
	SoAppearanceKit.3iv SoBaseKit.3iv SoCameraKit.3iv SoInteractionKit.3iv \
	SoLightKit.3iv SoNodeKit.3iv SoNodeKitListPart.3iv \
	SoNodekitCatalog.3iv SoSceneKit.3iv SoSeparatorKit.3iv SoShapeKit.3iv \
	SoWrapperKit.3iv SoAnnotation.3iv SoAntiSquish.3iv SoArray.3iv \
	SoAsciiText.3iv SoBaseColor.3iv SoBlinker.3iv SoCallback.3iv \
	SoCamera.3iv SoClipPlane.3iv SoColorIndex.3iv SoComplexity.3iv \
	SoCone.3iv SoCoordinate3.3iv SoCoordinate4.3iv SoCube.3iv \
	SoCylinder.3iv SoDirectionalLight.3iv SoDrawStyle.3iv \
	SoEnvironment.3iv SoFaceSet.3iv SoFile.3iv SoFont.3iv SoFontStyle.3iv \
	SoGroup.3iv SoIndexedFaceSet.3iv SoIndexedLineSet.3iv \
	SoIndexedNurbsCurve.3iv SoIndexedNurbsSurface.3iv SoIndexedShape.3iv \
	SoIndexedTriangleStripSet.3iv SoInfo.3iv SoLOD.3iv SoLabel.3iv \
	SoLevelOfDetail.3iv SoLight.3iv SoLightModel.3iv SoLineSet.3iv \
	SoLinearProfile.3iv SoLocateHighlight.3iv SoMaterial.3iv \
	SoMaterialBinding.3iv SoMatrixTransform.3iv SoMultipleCopy.3iv \
	SoNode.3iv SoNonIndexedShape.3iv SoNormal.3iv SoNormalBinding.3iv \
	SoNurbsCurve.3iv SoNurbsProfile.3iv SoNurbsSurface.3iv \
	SoOrthographicCamera.3iv SoPackedColor.3iv SoPathSwitch.3iv \
	SoPendulum.3iv SoPerspectiveCamera.3iv SoPickStyle.3iv \
	SoPointLight.3iv SoPointSet.3iv SoProfile.3iv SoProfileCoordinate2.3iv \
	SoProfileCoordinate3.3iv SoQuadMesh.3iv SoResetTransform.3iv \
	SoRotation.3iv SoRotationXYZ.3iv SoRotor.3iv SoScale.3iv \
	SoSeparator.3iv SoShape.3iv SoShapeHints.3iv SoShuttle.3iv \
	SoSphere.3iv SoSpotLight.3iv SoSurroundScale.3iv SoSwitch.3iv \
	SoText2.3iv SoText3.3iv SoTexture2.3iv SoTexture2Transform.3iv \
	SoTextureCoordinate2.3iv SoTextureCoordinateBinding.3iv \
	SoTextureCoordinateDefault.3iv SoTextureCoordinateEnvironment.3iv \
	SoTextureCoordinateFunction.3iv SoTextureCoordinatePlane.3iv \
	SoTransform.3iv SoTransformSeparator.3iv SoTransformation.3iv \
	SoTranslation.3iv SoTriangleStripSet.3iv SoUnits.3iv \
	SoVertexProperty.3iv SoVertexShape.3iv SoWWWAnchor.3iv SoWWWInline.3iv \
	SbCylinderPlaneProjector.3iv SbCylinderProjector.3iv \
	SbCylinderSectionProjector.3iv SbCylinderSheetProjector.3iv \
	SbLineProjector.3iv SbPlaneProjector.3iv SbProjector.3iv \
	SbSpherePlaneProjector.3iv SbSphereProjector.3iv \
	SbSphereSectionProjector.3iv SbSphereSheetProjector.3iv \
	SoAlarmSensor.3iv SoDataSensor.3iv SoDelayQueueSensor.3iv \
	SoFieldSensor.3iv SoIdleSensor.3iv SoNodeSensor.3iv \
	SoOneShotSensor.3iv SoPathSensor.3iv SoSensor.3iv \
	SoTimerQueueSensor.3iv SoTimerSensor.3iv SoXtConstrainedViewer.3iv \
	SoXtExaminerViewer.3iv SoXtFlyViewer.3iv SoXtFullViewer.3iv \
	SoXtPlaneViewer.3iv SoXtViewer.3iv SoXtWalkViewer.3iv

post-patch:
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g ;\
			      s|%%CXX%%|${CXX}|g ; \
			      s|%%CXXFLAGS%%|${CXXFLAGS}|g'  ${WRKSRC}/make/ivcommondefs
post-install:
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${PKGMESSAGE}

.include <bsd.port.mk>
