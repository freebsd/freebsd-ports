# ex:ts=8
# Ports collection makefile for:	X3DToolKit
# Date created:			Oct 29, 2005
# Whom:				German Tischler <tanis@gaspode.franken.de>
#
# $FreeBSD$
#

PORTNAME=	libx3dtk
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://artis.imag.fr/Members/Yannick.Legoc/X3D/libs/
DISTNAME=	X3DToolKit-${PORTVERSION:R}.${PORTVERSION:E}

MAINTAINER=	tanis@gaspode.franken.de
COMMENT=	An LGPL C++ Toolkit for X3D

BUILD_DEPENDS=	${QMAKE}:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		QGLViewer.2:${PORTSDIR}/graphics/libqglviewer

WRKSRC=		${WRKDIR}/X3DToolKit-1.0

USE_GMAKE=	yes
USE_GNOME=	libxml2
USE_QT_VER=	3
MAKE_ENV=	QTDIR="${QT_PREFIX}"

USE_LDCONFIG=	yes

QMAKE?=		${LOCALBASE}/bin/qmake
QMAKESPEC?=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=	broken on ia64
.endif

post-patch:
	${CP} ${FILESDIR}/X3DAbstractNodeForward.h ${WRKSRC}/include/X3DTK/private/X3DAbstractNodeForward.h

do-configure:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		-spec ${QMAKESPEC} \
		INCLUDEPATH=${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib \
		PARSER=LIBXML \
		LIBXML_DIR=${LOCALBASE} \
		JPEG=YES \
		JPEG_DIR=${LOCALBASE} \
		X3DTK_DIR=${LOCALBASE} \
		LIBXML_INC_DIR=${LOCALBASE}/include/libxml2 \
		LIBXML_LIB_DIR=${LOCALBASE}/lib \
		QGLVIEWER_DIR=${LOCALBASE} \
		PREFIX="${PREFIX}"
	cd ${WRKSRC}/examples && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		-spec ${QMAKESPEC} \
		INCLUDEPATH=${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib \
		PARSER=LIBXML \
		LIBXML_DIR=${LOCALBASE} \
		JPEG=YES \
		JPEG_DIR=${LOCALBASE} \
		X3DTK_DIR=${WRKSRC} \
		LIBXML_INC_DIR=${LOCALBASE}/include/libxml2 \
		LIBXML_LIB_DIR=${LOCALBASE}/lib \
		QGLVIEWER_DIR=${LOCALBASE} \
		PREFIX="${PREFIX}"

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE}
	cd ${WRKSRC}/examples && ${SETENV} ${MAKE_ENV} ${GMAKE}

INSTALL_DIR=	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}

do-install:
	${INSTALL_DIR} -d ${PREFIX}/include/X3DTK
	${INSTALL_DIR} -d ${PREFIX}/include/X3DTK/GL
	${INSTALL_DIR} -d ${PREFIX}/include/X3DTK/X3D
	${INSTALL_DIR} -d ${PREFIX}/include/X3DTK/MESH
	${INSTALL_DIR} -d ${PREFIX}/include/X3DTK/private
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libX3DTK.so.1.0.1 ${PREFIX}/lib/libX3DTK.so.1
	cd ${PREFIX}/lib && ${LN} -s libX3DTK.so.1 libX3DTK.so
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/GL/renderer.h ${PREFIX}/include/X3DTK/GL/renderer.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/GL/scenegraph.h ${PREFIX}/include/X3DTK/GL/scenegraph.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/GL/updater.h ${PREFIX}/include/X3DTK/GL/updater.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/X3D/scenesaver.h ${PREFIX}/include/X3DTK/X3D/scenesaver.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/X3D/glbuilder.h ${PREFIX}/include/X3DTK/X3D/glbuilder.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/X3D/sharedcoordcomputer.h ${PREFIX}/include/X3DTK/X3D/sharedcoordcomputer.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/X3D/inlineloader.h ${PREFIX}/include/X3DTK/X3D/inlineloader.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/X3D/meshbuilder.h ${PREFIX}/include/X3DTK/X3D/meshbuilder.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/X3D/scenegraph.h ${PREFIX}/include/X3DTK/X3D/scenegraph.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/X3D/worldcoordtranslator.h ${PREFIX}/include/X3DTK/X3D/worldcoordtranslator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/X3D/coordmerger.h ${PREFIX}/include/X3DTK/X3D/coordmerger.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/X3D/bboxupdater.h ${PREFIX}/include/X3DTK/X3D/bboxupdater.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/X3D/filevalidator.h ${PREFIX}/include/X3DTK/X3D/filevalidator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/MESH/connectedcomcomputer.h ${PREFIX}/include/X3DTK/MESH/connectedcomcomputer.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/MESH/primitivemeshbuilder.h ${PREFIX}/include/X3DTK/MESH/primitivemeshbuilder.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/MESH/normalsdrawer.h ${PREFIX}/include/X3DTK/MESH/normalsdrawer.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/MESH/verticesdrawer.h ${PREFIX}/include/X3DTK/MESH/verticesdrawer.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/MESH/normalsflipper.h ${PREFIX}/include/X3DTK/MESH/normalsflipper.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/MESH/normalsinverter.h ${PREFIX}/include/X3DTK/MESH/normalsinverter.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/MESH/statscalculator.h ${PREFIX}/include/X3DTK/MESH/statscalculator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/MESH/normalsupdater.h ${PREFIX}/include/X3DTK/MESH/normalsupdater.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/MESH/scenegraph.h ${PREFIX}/include/X3DTK/MESH/scenegraph.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/MESH/facesdrawer.h ${PREFIX}/include/X3DTK/MESH/facesdrawer.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/MESH/edgesdrawer.h ${PREFIX}/include/X3DTK/MESH/edgesdrawer.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/MESH/meshsimplifier.h ${PREFIX}/include/X3DTK/MESH/meshsimplifier.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/MESH/x3dbuilder.h ${PREFIX}/include/X3DTK/MESH/x3dbuilder.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/cloner.h ${PREFIX}/include/X3DTK/cloner.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/graphtester.h ${PREFIX}/include/X3DTK/graphtester.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/simplifiedmeshscene.h ${PREFIX}/include/X3DTK/simplifiedmeshscene.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/memreleaser.h ${PREFIX}/include/X3DTK/memreleaser.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/simplex3dglscene.h ${PREFIX}/include/X3DTK/simplex3dglscene.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/kernel.h ${PREFIX}/include/X3DTK/kernel.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_TriangleSet.h ${PREFIX}/include/X3DTK/private/X3D_TriangleSet.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/StateVariables.h ${PREFIX}/include/X3DTK/private/StateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Material.h ${PREFIX}/include/X3DTK/private/X3D_Material.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_SharedCoordComputerRenderingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_SharedCoordComputerRenderingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_QLoader.h ${PREFIX}/include/X3DTK/private/X3D_QLoader.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_UpdaterStateVariables.h ${PREFIX}/include/X3DTK/private/GL_UpdaterStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_WorldCoordTranslatorMulNavigationVisitor.h ${PREFIX}/include/X3DTK/private/X3D_WorldCoordTranslatorMulNavigationVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/SFMatrix34f.h ${PREFIX}/include/X3DTK/private/SFMatrix34f.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_Shape.h ${PREFIX}/include/X3DTK/private/MESH_Shape.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_PointLight.h ${PREFIX}/include/X3DTK/private/X3D_PointLight.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_X3DTextureNode.h ${PREFIX}/include/X3DTK/private/GL_X3DTextureNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DXmlLoader.h ${PREFIX}/include/X3DTK/private/X3D_X3DXmlLoader.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_SharedCoordComputerStateVariables.h ${PREFIX}/include/X3DTK/private/X3D_SharedCoordComputerStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_X3DChildNode.h ${PREFIX}/include/X3DTK/private/GL_X3DChildNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Switch.h ${PREFIX}/include/X3DTK/private/X3D_Switch.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/ProcessHistory.h ${PREFIX}/include/X3DTK/private/ProcessHistory.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_RendererTexturingVisitor.h ${PREFIX}/include/X3DTK/private/GL_RendererTexturingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_DirectionalLight.h ${PREFIX}/include/X3DTK/private/X3D_DirectionalLight.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/QFileElement.h ${PREFIX}/include/X3DTK/private/QFileElement.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_GLBuilderGeometry3DVisitor.h ${PREFIX}/include/X3DTK/private/X3D_GLBuilderGeometry3DVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_BBoxUpdater.h ${PREFIX}/include/X3DTK/private/X3D_BBoxUpdater.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_ConnectedComComputer.h ${PREFIX}/include/X3DTK/private/MESH_ConnectedComComputer.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/EnterFunction.h ${PREFIX}/include/X3DTK/private/EnterFunction.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/SimplifiedMeshScene.h ${PREFIX}/include/X3DTK/private/SimplifiedMeshScene.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_IndexedLineSet.h ${PREFIX}/include/X3DTK/private/X3D_IndexedLineSet.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_CoordMergerStateVariables.h ${PREFIX}/include/X3DTK/private/X3D_CoordMergerStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_PrimitiveMeshBuilderStateVariables.h ${PREFIX}/include/X3DTK/private/MESH_PrimitiveMeshBuilderStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_X3DBuilderCoreVisitor.h ${PREFIX}/include/X3DTK/private/MESH_X3DBuilderCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_RendererShapeVisitor.h ${PREFIX}/include/X3DTK/private/GL_RendererShapeVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_BBoxUpdaterRenderingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_BBoxUpdaterRenderingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_TriangleStripSet.h ${PREFIX}/include/X3DTK/private/X3D_TriangleStripSet.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/Image.h ${PREFIX}/include/X3DTK/private/Image.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_PositionInterpolator2D.h ${PREFIX}/include/X3DTK/private/X3D_PositionInterpolator2D.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_VerticesDrawerStateVariables.h ${PREFIX}/include/X3DTK/private/MESH_VerticesDrawerStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_WorldCoordTranslatorReplaceGroupingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_WorldCoordTranslatorReplaceGroupingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DProcessor.h ${PREFIX}/include/X3DTK/private/X3DProcessor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_TrimmedSurface.h ${PREFIX}/include/X3DTK/private/X3D_TrimmedSurface.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DSensorNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DSensorNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_NURBSVisitor.h ${PREFIX}/include/X3DTK/private/X3D_NURBSVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_RendererStateVariables.h ${PREFIX}/include/X3DTK/private/GL_RendererStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/DFSWalker.h ${PREFIX}/include/X3DTK/private/DFSWalker.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_TriangleStripSet.h ${PREFIX}/include/X3DTK/private/GL_TriangleStripSet.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DTextureCoordinateNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DTextureCoordinateNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/libXMLFileElement.h ${PREFIX}/include/X3DTK/private/libXMLFileElement.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_Transform.h ${PREFIX}/include/X3DTK/private/MESH_Transform.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DObject.h ${PREFIX}/include/X3DTK/private/X3D_X3DObject.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DAppearanceChildNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DAppearanceChildNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DRoute.h ${PREFIX}/include/X3DTK/private/X3DRoute.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_Renderer.h ${PREFIX}/include/X3DTK/private/GL_Renderer.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_NurbsPositionInterpolator.h ${PREFIX}/include/X3DTK/private/X3D_NurbsPositionInterpolator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_FileValidatorStateVariables.h ${PREFIX}/include/X3DTK/private/X3D_FileValidatorStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_ColorRGBA.h ${PREFIX}/include/X3DTK/private/X3D_ColorRGBA.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_MeshData.h ${PREFIX}/include/X3DTK/private/MESH_MeshData.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_MeshSimplifierCoreVisitor.h ${PREFIX}/include/X3DTK/private/MESH_MeshSimplifierCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_X3DComposedGeometryNode.h ${PREFIX}/include/X3DTK/private/GL_X3DComposedGeometryNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GraphTester.h ${PREFIX}/include/X3DTK/private/GraphTester.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/Walker.h ${PREFIX}/include/X3DTK/private/Walker.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/TypeList.h ${PREFIX}/include/X3DTK/private/TypeList.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_CoreVisitor.h ${PREFIX}/include/X3DTK/private/X3D_CoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/Platform.h ${PREFIX}/include/X3DTK/private/Platform.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_EdgesDrawerCoreVisitor.h ${PREFIX}/include/X3DTK/private/MESH_EdgesDrawerCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_NurbsTextureSurface.h ${PREFIX}/include/X3DTK/private/X3D_NurbsTextureSurface.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DTexture2DNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DTexture2DNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DUrlObject.h ${PREFIX}/include/X3DTK/private/X3D_X3DUrlObject.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_ImageTexture.h ${PREFIX}/include/X3DTK/private/GL_ImageTexture.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_BBoxUpdaterNavigationVisitor.h ${PREFIX}/include/X3DTK/private/X3D_BBoxUpdaterNavigationVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_X3DGeometryNode.h ${PREFIX}/include/X3DTK/private/GL_X3DGeometryNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Appearance.h ${PREFIX}/include/X3DTK/private/X3D_Appearance.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_StaticGroup.h ${PREFIX}/include/X3DTK/private/GL_StaticGroup.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_NurbsSurface.h ${PREFIX}/include/X3DTK/private/X3D_NurbsSurface.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_ConnectedComComputerCoreVisitor.h ${PREFIX}/include/X3DTK/private/MESH_ConnectedComComputerCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DComponentCreator.h ${PREFIX}/include/X3DTK/private/X3D_X3DComponentCreator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_X3DTexture2DNode.h ${PREFIX}/include/X3DTK/private/GL_X3DTexture2DNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_MeshBuilderShapeVisitor.h ${PREFIX}/include/X3DTK/private/X3D_MeshBuilderShapeVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/VisitingFunctions.h ${PREFIX}/include/X3DTK/private/VisitingFunctions.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_GroupingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_GroupingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_OrientationInterpolator.h ${PREFIX}/include/X3DTK/private/X3D_OrientationInterpolator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DChildNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DChildNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_NurbsCurve2D.h ${PREFIX}/include/X3DTK/private/X3D_NurbsCurve2D.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_Box.h ${PREFIX}/include/X3DTK/private/GL_Box.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/DFSGraphTraversal.h ${PREFIX}/include/X3DTK/private/DFSGraphTraversal.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_FillProperties.h ${PREFIX}/include/X3DTK/private/GL_FillProperties.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_CoreVisitor.h ${PREFIX}/include/X3DTK/private/MESH_CoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DAttributeRecorder.h ${PREFIX}/include/X3DTK/private/X3DAttributeRecorder.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_ContourPolyline2D.h ${PREFIX}/include/X3DTK/private/X3D_ContourPolyline2D.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_CoordinateInterpolator.h ${PREFIX}/include/X3DTK/private/X3D_CoordinateInterpolator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_SceneGraphTypes.h ${PREFIX}/include/X3DTK/private/GL_SceneGraphTypes.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DParametricGeometryNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DParametricGeometryNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_GLBuilderRenderingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_GLBuilderRenderingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_VerticesDrawerCoreVisitor.h ${PREFIX}/include/X3DTK/private/MESH_VerticesDrawerCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_WorldCoordTranslatorMulRenderingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_WorldCoordTranslatorMulRenderingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_TexturingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_TexturingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DMFNodeFunctor.h ${PREFIX}/include/X3DTK/private/X3DMFNodeFunctor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/ClonerStateVariables.h ${PREFIX}/include/X3DTK/private/ClonerStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_TriangleFanSet.h ${PREFIX}/include/X3DTK/private/X3D_TriangleFanSet.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsInverter.h ${PREFIX}/include/X3DTK/private/MESH_NormalsInverter.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_CoordMergerRenderingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_CoordMergerRenderingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/Progress.h ${PREFIX}/include/X3DTK/private/Progress.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/ClonerAbstractVisitor.h ${PREFIX}/include/X3DTK/private/ClonerAbstractVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_X3DMeshNode.h ${PREFIX}/include/X3DTK/private/MESH_X3DMeshNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DField.h ${PREFIX}/include/X3DTK/private/X3DField.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/Recorder.h ${PREFIX}/include/X3DTK/private/Recorder.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_PositionInterpolator.h ${PREFIX}/include/X3DTK/private/X3D_PositionInterpolator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_ShapeVisitor.h ${PREFIX}/include/X3DTK/private/GL_ShapeVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_TexturingVisitor.h ${PREFIX}/include/X3DTK/private/GL_TexturingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_IndexedFaceSet.h ${PREFIX}/include/X3DTK/private/X3D_IndexedFaceSet.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_WorldCoordTranslatorShareCoreVisitor.h ${PREFIX}/include/X3DTK/private/X3D_WorldCoordTranslatorShareCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/AbstractVisitor.h ${PREFIX}/include/X3DTK/private/AbstractVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_SceneGraphTypes.h ${PREFIX}/include/X3DTK/private/MESH_SceneGraphTypes.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_BBox.h ${PREFIX}/include/X3DTK/private/GL_BBox.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_Scene.h ${PREFIX}/include/X3DTK/private/GL_Scene.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DNodeCloner.h ${PREFIX}/include/X3DTK/private/X3DNodeCloner.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DFileElement.h ${PREFIX}/include/X3DTK/private/X3DFileElement.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsUpdaterStateVariables.h ${PREFIX}/include/X3DTK/private/MESH_NormalsUpdaterStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_LightingCreator.h ${PREFIX}/include/X3DTK/private/X3D_LightingCreator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_BBoxUpdaterGeometry3DVisitor.h ${PREFIX}/include/X3DTK/private/X3D_BBoxUpdaterGeometry3DVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_StatsCalculatorCoreVisitor.h ${PREFIX}/include/X3DTK/private/MESH_StatsCalculatorCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_X3DVertexNode.h ${PREFIX}/include/X3DTK/private/MESH_X3DVertexNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_ScalarInterpolator.h ${PREFIX}/include/X3DTK/private/X3D_ScalarInterpolator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/SphereDrawArray.h ${PREFIX}/include/X3DTK/private/SphereDrawArray.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GraphTraversal.h ${PREFIX}/include/X3DTK/private/GraphTraversal.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_ImageTexture.h ${PREFIX}/include/X3DTK/private/X3D_ImageTexture.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsInverterStateVariables.h ${PREFIX}/include/X3DTK/private/MESH_NormalsInverterStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_MeshBuilder.h ${PREFIX}/include/X3DTK/private/X3D_MeshBuilder.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_RendererRenderingVisitor.h ${PREFIX}/include/X3DTK/private/GL_RendererRenderingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_FacesDrawerCoreVisitor.h ${PREFIX}/include/X3DTK/private/MESH_FacesDrawerCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_InterpolationVisitor.h ${PREFIX}/include/X3DTK/private/X3D_InterpolationVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_GLBuilderGroupingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_GLBuilderGroupingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_NavigationVisitor.h ${PREFIX}/include/X3DTK/private/X3D_NavigationVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DFunction.h ${PREFIX}/include/X3DTK/private/X3DFunction.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_InlineLoaderCoreVisitor.h ${PREFIX}/include/X3DTK/private/X3D_InlineLoaderCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_Shape.h ${PREFIX}/include/X3DTK/private/GL_Shape.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Group.h ${PREFIX}/include/X3DTK/private/X3D_Group.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_Cone.h ${PREFIX}/include/X3DTK/private/GL_Cone.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/SimpleX3DGLScene.h ${PREFIX}/include/X3DTK/private/SimpleX3DGLScene.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_BaseSFVertex.h ${PREFIX}/include/X3DTK/private/MESH_BaseSFVertex.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_TextureCoordinate.h ${PREFIX}/include/X3DTK/private/X3D_TextureCoordinate.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_FileValidatorGeometry3DVisitor.h ${PREFIX}/include/X3DTK/private/X3D_FileValidatorGeometry3DVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_NetworkingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_NetworkingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_Sphere.h ${PREFIX}/include/X3DTK/private/GL_Sphere.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_SharedCoordComputer.h ${PREFIX}/include/X3DTK/private/X3D_SharedCoordComputer.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_MeshSimplifierStateVariables.h ${PREFIX}/include/X3DTK/private/MESH_MeshSimplifierStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GraphTesterStateVariables.h ${PREFIX}/include/X3DTK/private/GraphTesterStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_SceneSaver.h ${PREFIX}/include/X3DTK/private/X3D_SceneSaver.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_NurbsCurve.h ${PREFIX}/include/X3DTK/private/X3D_NurbsCurve.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_BBoxDrawArray.h ${PREFIX}/include/X3DTK/private/GL_BBoxDrawArray.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_BaseSFEdge.h ${PREFIX}/include/X3DTK/private/MESH_BaseSFEdge.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_SceneSaverSetCoreVisitor.h ${PREFIX}/include/X3DTK/private/X3D_SceneSaverSetCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_Cylinder.h ${PREFIX}/include/X3DTK/private/GL_Cylinder.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_BaseSFFace.h ${PREFIX}/include/X3DTK/private/MESH_BaseSFFace.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_PointSet.h ${PREFIX}/include/X3DTK/private/X3D_PointSet.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DTextureNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DTextureNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_X3DGroupingNode.h ${PREFIX}/include/X3DTK/private/GL_X3DGroupingNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_Switch.h ${PREFIX}/include/X3DTK/private/GL_Switch.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Cone.h ${PREFIX}/include/X3DTK/private/X3D_Cone.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DAppearanceNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DAppearanceNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Contour2D.h ${PREFIX}/include/X3DTK/private/X3D_Contour2D.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_SceneSaverStateVariables.h ${PREFIX}/include/X3DTK/private/X3D_SceneSaverStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MemReleaser.h ${PREFIX}/include/X3DTK/private/MemReleaser.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_GLBuilderCoreVisitor.h ${PREFIX}/include/X3DTK/private/X3D_GLBuilderCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_ShapeVisitor.h ${PREFIX}/include/X3DTK/private/X3D_ShapeVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsDrawer.h ${PREFIX}/include/X3DTK/private/MESH_NormalsDrawer.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_RendererGroupingVisitor.h ${PREFIX}/include/X3DTK/private/GL_RendererGroupingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Loader.h ${PREFIX}/include/X3DTK/private/X3D_Loader.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_StaticGroup.h ${PREFIX}/include/X3DTK/private/X3D_StaticGroup.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_LineProperties.h ${PREFIX}/include/X3DTK/private/GL_LineProperties.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Box.h ${PREFIX}/include/X3DTK/private/X3D_Box.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DColorNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DColorNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DActor.h ${PREFIX}/include/X3DTK/private/X3DActor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_X3DGroupingNode.h ${PREFIX}/include/X3DTK/private/MESH_X3DGroupingNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_SFIndirectEdge.h ${PREFIX}/include/X3DTK/private/MESH_SFIndirectEdge.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_Switch.h ${PREFIX}/include/X3DTK/private/MESH_Switch.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Creator.h ${PREFIX}/include/X3DTK/private/X3D_Creator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/Singleton.h ${PREFIX}/include/X3DTK/private/Singleton.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DLoader.h ${PREFIX}/include/X3DTK/private/X3DLoader.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_MeshBuilderGroupingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_MeshBuilderGroupingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_StatsCalculatorStateVariables.h ${PREFIX}/include/X3DTK/private/MESH_StatsCalculatorStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Geometry3DVisitor.h ${PREFIX}/include/X3DTK/private/X3D_Geometry3DVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Collision.h ${PREFIX}/include/X3DTK/private/X3D_Collision.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_BBoxUpdaterShapeVisitor.h ${PREFIX}/include/X3DTK/private/X3D_BBoxUpdaterShapeVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/SFType.h ${PREFIX}/include/X3DTK/private/SFType.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_Material.h ${PREFIX}/include/X3DTK/private/GL_Material.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DGeometryNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DGeometryNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DTypes.h ${PREFIX}/include/X3DTK/private/X3DTypes.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_NURBSCreator.h ${PREFIX}/include/X3DTK/private/X3D_NURBSCreator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_MeshBuilderGeometry3DVisitor.h ${PREFIX}/include/X3DTK/private/X3D_MeshBuilderGeometry3DVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_WorldCoordTranslatorMulCoreVisitor.h ${PREFIX}/include/X3DTK/private/X3D_WorldCoordTranslatorMulCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_RenderingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_RenderingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DCoordinateNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DCoordinateNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_X3DMaterialNode.h ${PREFIX}/include/X3DTK/private/GL_X3DMaterialNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_FileValidator.h ${PREFIX}/include/X3DTK/private/X3D_FileValidator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MemReleaserStateVariables.h ${PREFIX}/include/X3DTK/private/MemReleaserStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MemReleaserAbstractVisitor.h ${PREFIX}/include/X3DTK/private/MemReleaserAbstractVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/NodeFactory.h ${PREFIX}/include/X3DTK/private/NodeFactory.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_EdgesDrawerStateVariables.h ${PREFIX}/include/X3DTK/private/MESH_EdgesDrawerStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_FacesDrawer.h ${PREFIX}/include/X3DTK/private/MESH_FacesDrawer.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_RenderingVisitor.h ${PREFIX}/include/X3DTK/private/GL_RenderingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_FileValidatorCoreVisitor.h ${PREFIX}/include/X3DTK/private/X3D_FileValidatorCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_SFVertex.h ${PREFIX}/include/X3DTK/private/MESH_SFVertex.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_MeshBuilderCoreVisitor.h ${PREFIX}/include/X3DTK/private/X3D_MeshBuilderCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_CoreCreator.h ${PREFIX}/include/X3DTK/private/X3D_CoreCreator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_InlineLoader.h ${PREFIX}/include/X3DTK/private/X3D_InlineLoader.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_CoordMerger.h ${PREFIX}/include/X3DTK/private/X3D_CoordMerger.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DInterpolatorNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DInterpolatorNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_SceneGraphTypes.h ${PREFIX}/include/X3DTK/private/X3D_SceneGraphTypes.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_FacesDrawerStateVariables.h ${PREFIX}/include/X3DTK/private/MESH_FacesDrawerStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Coordinate.h ${PREFIX}/include/X3DTK/private/X3D_Coordinate.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/CylinderDrawArray.h ${PREFIX}/include/X3DTK/private/CylinderDrawArray.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_Info.h ${PREFIX}/include/X3DTK/private/MESH_Info.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_libXMLLoader.h ${PREFIX}/include/X3DTK/private/X3D_libXMLLoader.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_X3DAppearanceChildNode.h ${PREFIX}/include/X3DTK/private/GL_X3DAppearanceChildNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_X3DNode.h ${PREFIX}/include/X3DTK/private/MESH_X3DNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GraphTesterAbstractVisitor.h ${PREFIX}/include/X3DTK/private/GraphTesterAbstractVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_FillProperties.h ${PREFIX}/include/X3DTK/private/X3D_FillProperties.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_GLBuilderShapeVisitor.h ${PREFIX}/include/X3DTK/private/X3D_GLBuilderShapeVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsDrawerStateVariables.h ${PREFIX}/include/X3DTK/private/MESH_NormalsDrawerStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DComponentVisitor.h ${PREFIX}/include/X3DTK/private/X3DComponentVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DOnePassProcessor.h ${PREFIX}/include/X3DTK/private/X3DOnePassProcessor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_EdgesDrawer.h ${PREFIX}/include/X3DTK/private/MESH_EdgesDrawer.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/XercesFileElement.h ${PREFIX}/include/X3DTK/private/XercesFileElement.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_WorldCoordTranslatorMulGroupingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_WorldCoordTranslatorMulGroupingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsFlipper.h ${PREFIX}/include/X3DTK/private/MESH_NormalsFlipper.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_GroupingCreator.h ${PREFIX}/include/X3DTK/private/X3D_GroupingCreator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/SFComponent.h ${PREFIX}/include/X3DTK/private/SFComponent.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_SFDirectEdge.h ${PREFIX}/include/X3DTK/private/MESH_SFDirectEdge.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_RendererCoreVisitor.h ${PREFIX}/include/X3DTK/private/GL_RendererCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsFlipperCoreVisitor.h ${PREFIX}/include/X3DTK/private/MESH_NormalsFlipperCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_IndexedLineSet.h ${PREFIX}/include/X3DTK/private/GL_IndexedLineSet.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_CoordinateInterpolator2D.h ${PREFIX}/include/X3DTK/private/X3D_CoordinateInterpolator2D.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Inline.h ${PREFIX}/include/X3DTK/private/X3D_Inline.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_X3DNode.h ${PREFIX}/include/X3DTK/private/GL_X3DNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_VerticesDrawer.h ${PREFIX}/include/X3DTK/private/MESH_VerticesDrawer.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_TexturingCreator.h ${PREFIX}/include/X3DTK/private/X3D_TexturingCreator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsDrawerCoreVisitor.h ${PREFIX}/include/X3DTK/private/MESH_NormalsDrawerCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_NormalInterpolator.h ${PREFIX}/include/X3DTK/private/X3D_NormalInterpolator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_TriangleSet.h ${PREFIX}/include/X3DTK/private/GL_TriangleSet.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_BBoxUpdaterGroupingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_BBoxUpdaterGroupingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsFlipperStateVariables.h ${PREFIX}/include/X3DTK/private/MESH_NormalsFlipperStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_SpotLight.h ${PREFIX}/include/X3DTK/private/X3D_SpotLight.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_Updater.h ${PREFIX}/include/X3DTK/private/GL_Updater.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DTextureTransformNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DTextureTransformNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_Mesh.h ${PREFIX}/include/X3DTK/private/MESH_Mesh.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_SFEdgeContent.h ${PREFIX}/include/X3DTK/private/MESH_SFEdgeContent.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_X3DTextureTransform2DNode.h ${PREFIX}/include/X3DTK/private/GL_X3DTextureTransform2DNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/BBox.h ${PREFIX}/include/X3DTK/private/BBox.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Color.h ${PREFIX}/include/X3DTK/private/X3D_Color.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/Cloner.h ${PREFIX}/include/X3DTK/private/Cloner.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_SceneSaverWriteCoreVisitor.h ${PREFIX}/include/X3DTK/private/X3D_SceneSaverWriteCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/CreationFunction.h ${PREFIX}/include/X3DTK/private/CreationFunction.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_Transform.h ${PREFIX}/include/X3DTK/private/GL_Transform.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/WalkOnFunction.h ${PREFIX}/include/X3DTK/private/WalkOnFunction.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_X3DAppearanceNode.h ${PREFIX}/include/X3DTK/private/GL_X3DAppearanceNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/BaseRecorder.h ${PREFIX}/include/X3DTK/private/BaseRecorder.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_Group.h ${PREFIX}/include/X3DTK/private/GL_Group.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_BBoxUpdaterStateVariables.h ${PREFIX}/include/X3DTK/private/X3D_BBoxUpdaterStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DBaseTypes.h ${PREFIX}/include/X3DTK/private/X3DBaseTypes.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_InterpolationCreator.h ${PREFIX}/include/X3DTK/private/X3D_InterpolationCreator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_XercesLoader.h ${PREFIX}/include/X3DTK/private/X3D_XercesLoader.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DGroupingNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DGroupingNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/SFString.h ${PREFIX}/include/X3DTK/private/SFString.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_WorldCoordTranslator.h ${PREFIX}/include/X3DTK/private/X3D_WorldCoordTranslator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_Appearance.h ${PREFIX}/include/X3DTK/private/GL_Appearance.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_X3DShapeNode.h ${PREFIX}/include/X3DTK/private/GL_X3DShapeNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_Vertex.h ${PREFIX}/include/X3DTK/private/MESH_Vertex.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsInverterCoreVisitor.h ${PREFIX}/include/X3DTK/private/MESH_NormalsInverterCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DNormalNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DNormalNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_NavigationCreator.h ${PREFIX}/include/X3DTK/private/X3D_NavigationCreator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DMultiPassProcessor.h ${PREFIX}/include/X3DTK/private/X3DMultiPassProcessor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsUpdaterVerticesCoreVisitor.h ${PREFIX}/include/X3DTK/private/MESH_NormalsUpdaterVerticesCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_NetworkingCreator.h ${PREFIX}/include/X3DTK/private/X3D_NetworkingCreator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_CoordinateDeformer.h ${PREFIX}/include/X3DTK/private/X3D_CoordinateDeformer.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/LeaveFunction.h ${PREFIX}/include/X3DTK/private/LeaveFunction.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DTextureTransform2DNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DTextureTransform2DNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/SFVec2f.h ${PREFIX}/include/X3DTK/private/SFVec2f.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/SFVec3f.h ${PREFIX}/include/X3DTK/private/SFVec3f.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsUpdater.h ${PREFIX}/include/X3DTK/private/MESH_NormalsUpdater.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/ConeDrawArray.h ${PREFIX}/include/X3DTK/private/ConeDrawArray.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_UpdaterCoreVisitor.h ${PREFIX}/include/X3DTK/private/GL_UpdaterCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DAbstractNode.h ${PREFIX}/include/X3DTK/private/X3DAbstractNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_GroupingVisitor.h ${PREFIX}/include/X3DTK/private/GL_GroupingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_Geometry3DVisitor.h ${PREFIX}/include/X3DTK/private/GL_Geometry3DVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_ConnectedComComputerMeshCoreVisitor.h ${PREFIX}/include/X3DTK/private/MESH_ConnectedComComputerMeshCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DGeometricPropertyNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DGeometricPropertyNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/Signal.h ${PREFIX}/include/X3DTK/private/Signal.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_SFEdge.h ${PREFIX}/include/X3DTK/private/MESH_SFEdge.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_InlineLoaderStateVariables.h ${PREFIX}/include/X3DTK/private/X3D_InlineLoaderStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DSFNodeRecorder.h ${PREFIX}/include/X3DTK/private/X3DSFNodeRecorder.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_CoreVisitor.h ${PREFIX}/include/X3DTK/private/GL_CoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_TextureTransform.h ${PREFIX}/include/X3DTK/private/X3D_TextureTransform.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_TriangleFanSet.h ${PREFIX}/include/X3DTK/private/GL_TriangleFanSet.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_LightingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_LightingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_SFFace.h ${PREFIX}/include/X3DTK/private/MESH_SFFace.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_LineProperties.h ${PREFIX}/include/X3DTK/private/X3D_LineProperties.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_WorldCoordTranslatorStateVariables.h ${PREFIX}/include/X3DTK/private/X3D_WorldCoordTranslatorStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Cylinder.h ${PREFIX}/include/X3DTK/private/X3D_Cylinder.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_ShapeCreator.h ${PREFIX}/include/X3DTK/private/X3D_ShapeCreator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_IndexedFaceSet.h ${PREFIX}/include/X3DTK/private/GL_IndexedFaceSet.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_X3DBuilderStateVariables.h ${PREFIX}/include/X3DTK/private/MESH_X3DBuilderStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Normal.h ${PREFIX}/include/X3DTK/private/X3D_Normal.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DLightNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DLightNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_TextureTransform.h ${PREFIX}/include/X3DTK/private/GL_TextureTransform.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_ConnectedComComputerStateVariables.h ${PREFIX}/include/X3DTK/private/MESH_ConnectedComComputerStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_GLBuilderNavigationVisitor.h ${PREFIX}/include/X3DTK/private/X3D_GLBuilderNavigationVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Scene.h ${PREFIX}/include/X3DTK/private/X3D_Scene.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_GLBuilder.h ${PREFIX}/include/X3DTK/private/X3D_GLBuilder.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_MeshBuilderRenderingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_MeshBuilderRenderingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_PrimitiveMeshBuilderGeometry3DVisitor.h ${PREFIX}/include/X3DTK/private/X3D_PrimitiveMeshBuilderGeometry3DVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DMaterialNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DMaterialNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_GLBuilderStateVariables.h ${PREFIX}/include/X3DTK/private/X3D_GLBuilderStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DComposedGeometryNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DComposedGeometryNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsUpdaterFacesCoreVisitor.h ${PREFIX}/include/X3DTK/private/MESH_NormalsUpdaterFacesCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DComponent.h ${PREFIX}/include/X3DTK/private/X3DComponent.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DMemberFunctor.h ${PREFIX}/include/X3DTK/private/X3DMemberFunctor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_PrimitiveMeshBuilder.h ${PREFIX}/include/X3DTK/private/MESH_PrimitiveMeshBuilder.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_MeshBuilderStateVariables.h ${PREFIX}/include/X3DTK/private/X3D_MeshBuilderStateVariables.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/Visitor.h ${PREFIX}/include/X3DTK/private/Visitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_NurbsGroup.h ${PREFIX}/include/X3DTK/private/X3D_NurbsGroup.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_ColorInterpolator.h ${PREFIX}/include/X3DTK/private/X3D_ColorInterpolator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_StatsCalculator.h ${PREFIX}/include/X3DTK/private/MESH_StatsCalculator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_InlineLoaderNetworkingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_InlineLoaderNetworkingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_PointSet.h ${PREFIX}/include/X3DTK/private/GL_PointSet.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_GLBuilderTexturingVisitor.h ${PREFIX}/include/X3DTK/private/X3D_GLBuilderTexturingVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/GL_X3DTextureTransformNode.h ${PREFIX}/include/X3DTK/private/GL_X3DTextureTransformNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DBoundedObject.h ${PREFIX}/include/X3DTK/private/X3D_X3DBoundedObject.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/SFSceneGraph.h ${PREFIX}/include/X3DTK/private/SFSceneGraph.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Geometry3DCreator.h ${PREFIX}/include/X3DTK/private/X3D_Geometry3DCreator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_X3DBuilder.h ${PREFIX}/include/X3DTK/private/MESH_X3DBuilder.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/CLog.h ${PREFIX}/include/X3DTK/private/CLog.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_Scene.h ${PREFIX}/include/X3DTK/private/MESH_Scene.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DShapeNode.h ${PREFIX}/include/X3DTK/private/X3D_X3DShapeNode.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/SFPoint2f.h ${PREFIX}/include/X3DTK/private/SFPoint2f.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/SFPoint3f.h ${PREFIX}/include/X3DTK/private/SFPoint3f.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/JPGImageType.h ${PREFIX}/include/X3DTK/private/JPGImageType.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Shape.h ${PREFIX}/include/X3DTK/private/X3D_Shape.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DMFNodeRecorder.h ${PREFIX}/include/X3DTK/private/X3DMFNodeRecorder.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/BoxDrawArray.h ${PREFIX}/include/X3DTK/private/BoxDrawArray.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_MeshSimplifier.h ${PREFIX}/include/X3DTK/private/MESH_MeshSimplifier.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_BBoxUpdaterCoreVisitor.h ${PREFIX}/include/X3DTK/private/X3D_BBoxUpdaterCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Transform.h ${PREFIX}/include/X3DTK/private/X3D_Transform.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DSFNodeFunctor.h ${PREFIX}/include/X3DTK/private/X3DSFNodeFunctor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_SceneSaverGetCoreVisitor.h ${PREFIX}/include/X3DTK/private/X3D_SceneSaverGetCoreVisitor.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_RenderingCreator.h ${PREFIX}/include/X3DTK/private/X3D_RenderingCreator.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_Sphere.h ${PREFIX}/include/X3DTK/private/X3D_Sphere.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DAbstractNodeForward.h ${PREFIX}/include/X3DTK/private/X3DAbstractNodeForward.h
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_X3DComponentCreator.inl ${PREFIX}/include/X3DTK/private/X3D_X3DComponentCreator.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_FacesDrawer.inl ${PREFIX}/include/X3DTK/private/MESH_FacesDrawer.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_EdgesDrawerCoreVisitor.inl ${PREFIX}/include/X3DTK/private/MESH_EdgesDrawerCoreVisitor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_SFEdge.inl ${PREFIX}/include/X3DTK/private/MESH_SFEdge.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsDrawerCoreVisitor.inl ${PREFIX}/include/X3DTK/private/MESH_NormalsDrawerCoreVisitor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_SFEdgeContent.inl ${PREFIX}/include/X3DTK/private/MESH_SFEdgeContent.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DAttributeRecorder.inl ${PREFIX}/include/X3DTK/private/X3DAttributeRecorder.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsFlipper.inl ${PREFIX}/include/X3DTK/private/MESH_NormalsFlipper.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_EdgesDrawer.inl ${PREFIX}/include/X3DTK/private/MESH_EdgesDrawer.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_Info.inl ${PREFIX}/include/X3DTK/private/MESH_Info.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_Vertex.inl ${PREFIX}/include/X3DTK/private/MESH_Vertex.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_VerticesDrawerStateVariables.inl ${PREFIX}/include/X3DTK/private/MESH_VerticesDrawerStateVariables.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_VerticesDrawer.inl ${PREFIX}/include/X3DTK/private/MESH_VerticesDrawer.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_SFFace.inl ${PREFIX}/include/X3DTK/private/MESH_SFFace.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_MeshBuilderStateVariables.inl ${PREFIX}/include/X3DTK/private/X3D_MeshBuilderStateVariables.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsUpdaterStateVariables.inl ${PREFIX}/include/X3DTK/private/MESH_NormalsUpdaterStateVariables.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/Image.inl ${PREFIX}/include/X3DTK/private/Image.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsFlipperStateVariables.inl ${PREFIX}/include/X3DTK/private/MESH_NormalsFlipperStateVariables.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_MeshSimplifierCoreVisitor.inl ${PREFIX}/include/X3DTK/private/MESH_MeshSimplifierCoreVisitor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsDrawer.inl ${PREFIX}/include/X3DTK/private/MESH_NormalsDrawer.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_SceneGraphTypes.inl ${PREFIX}/include/X3DTK/private/MESH_SceneGraphTypes.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_VerticesDrawerCoreVisitor.inl ${PREFIX}/include/X3DTK/private/MESH_VerticesDrawerCoreVisitor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DComponentVisitor.inl ${PREFIX}/include/X3DTK/private/X3DComponentVisitor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/SimplifiedMeshScene.inl ${PREFIX}/include/X3DTK/private/SimplifiedMeshScene.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_MeshBuilder.inl ${PREFIX}/include/X3DTK/private/X3D_MeshBuilder.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsInverterCoreVisitor.inl ${PREFIX}/include/X3DTK/private/MESH_NormalsInverterCoreVisitor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/NodeFactory.inl ${PREFIX}/include/X3DTK/private/NodeFactory.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_EdgesDrawerStateVariables.inl ${PREFIX}/include/X3DTK/private/MESH_EdgesDrawerStateVariables.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_Mesh.inl ${PREFIX}/include/X3DTK/private/MESH_Mesh.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_StatsCalculator.inl ${PREFIX}/include/X3DTK/private/MESH_StatsCalculator.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DField.inl ${PREFIX}/include/X3DTK/private/X3DField.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_FacesDrawerCoreVisitor.inl ${PREFIX}/include/X3DTK/private/MESH_FacesDrawerCoreVisitor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsFlipperCoreVisitor.inl ${PREFIX}/include/X3DTK/private/MESH_NormalsFlipperCoreVisitor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_SFDirectEdge.inl ${PREFIX}/include/X3DTK/private/MESH_SFDirectEdge.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_SFIndirectEdge.inl ${PREFIX}/include/X3DTK/private/MESH_SFIndirectEdge.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DSFNodeFunctor.inl ${PREFIX}/include/X3DTK/private/X3DSFNodeFunctor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/Singleton.inl ${PREFIX}/include/X3DTK/private/Singleton.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DSFNodeRecorder.inl ${PREFIX}/include/X3DTK/private/X3DSFNodeRecorder.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_StatsCalculatorCoreVisitor.inl ${PREFIX}/include/X3DTK/private/MESH_StatsCalculatorCoreVisitor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DNodeCloner.inl ${PREFIX}/include/X3DTK/private/X3DNodeCloner.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DMFNodeRecorder.inl ${PREFIX}/include/X3DTK/private/X3DMFNodeRecorder.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_SFVertex.inl ${PREFIX}/include/X3DTK/private/MESH_SFVertex.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsInverter.inl ${PREFIX}/include/X3DTK/private/MESH_NormalsInverter.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_MeshSimplifierStateVariables.inl ${PREFIX}/include/X3DTK/private/MESH_MeshSimplifierStateVariables.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DMFNodeFunctor.inl ${PREFIX}/include/X3DTK/private/X3DMFNodeFunctor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_FacesDrawerStateVariables.inl ${PREFIX}/include/X3DTK/private/MESH_FacesDrawerStateVariables.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_MeshBuilderCoreVisitor.inl ${PREFIX}/include/X3DTK/private/X3D_MeshBuilderCoreVisitor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsInverterStateVariables.inl ${PREFIX}/include/X3DTK/private/MESH_NormalsInverterStateVariables.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_MeshBuilderGroupingVisitor.inl ${PREFIX}/include/X3DTK/private/X3D_MeshBuilderGroupingVisitor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsUpdater.inl ${PREFIX}/include/X3DTK/private/MESH_NormalsUpdater.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/Recorder.inl ${PREFIX}/include/X3DTK/private/Recorder.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_X3DBuilder.inl ${PREFIX}/include/X3DTK/private/MESH_X3DBuilder.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_MeshBuilderShapeVisitor.inl ${PREFIX}/include/X3DTK/private/X3D_MeshBuilderShapeVisitor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DMemberFunctor.inl ${PREFIX}/include/X3DTK/private/X3DMemberFunctor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsUpdaterVerticesCoreVisitor.inl ${PREFIX}/include/X3DTK/private/MESH_NormalsUpdaterVerticesCoreVisitor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_MeshBuilderGeometry3DVisitor.inl ${PREFIX}/include/X3DTK/private/X3D_MeshBuilderGeometry3DVisitor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_StatsCalculatorStateVariables.inl ${PREFIX}/include/X3DTK/private/MESH_StatsCalculatorStateVariables.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_X3DBuilderStateVariables.inl ${PREFIX}/include/X3DTK/private/MESH_X3DBuilderStateVariables.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_X3DBuilderCoreVisitor.inl ${PREFIX}/include/X3DTK/private/MESH_X3DBuilderCoreVisitor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_MeshSimplifier.inl ${PREFIX}/include/X3DTK/private/MESH_MeshSimplifier.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3D_MeshBuilderRenderingVisitor.inl ${PREFIX}/include/X3DTK/private/X3D_MeshBuilderRenderingVisitor.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/X3DAbstractNode.inl ${PREFIX}/include/X3DTK/private/X3DAbstractNode.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsDrawerStateVariables.inl ${PREFIX}/include/X3DTK/private/MESH_NormalsDrawerStateVariables.inl
	${INSTALL_DATA} ${WRKSRC}/include/X3DTK/private/MESH_NormalsUpdaterFacesCoreVisitor.inl ${PREFIX}/include/X3DTK/private/MESH_NormalsUpdaterFacesCoreVisitor.inl
	${INSTALL_PROGRAM} ${WRKSRC}/examples/meshCreation/meshcreation ${PREFIX}/bin/meshcreation
	${INSTALL_PROGRAM} ${WRKSRC}/examples/glNormalViewer/glnormalviewer ${PREFIX}/bin/glnormalviewer
	${INSTALL_PROGRAM} ${WRKSRC}/examples/nodeCounter/nodecounter ${PREFIX}/bin/nodecounter
	${INSTALL_PROGRAM} ${WRKSRC}/examples/meshTransformComputer/meshtransformcomputer ${PREFIX}/bin/meshtransformcomputer
	${INSTALL_PROGRAM} ${WRKSRC}/examples/meshExtension/extendedmeshsaver ${PREFIX}/bin/extendedmeshsaver
	${INSTALL_PROGRAM} ${WRKSRC}/examples/simplifiedMeshViewer/simplifiedmeshviewer ${PREFIX}/bin/simplifiedmeshviewer
	${INSTALL_PROGRAM} ${WRKSRC}/examples/meshViewer/meshviewer ${PREFIX}/bin/meshviewer
	${INSTALL_PROGRAM} ${WRKSRC}/examples/newNodeViewer/newnodeviewer ${PREFIX}/bin/newnodeviewer
	${INSTALL_PROGRAM} ${WRKSRC}/examples/X3DViewer/x3dviewer ${PREFIX}/bin/x3dviewer
	${INSTALL_PROGRAM} ${WRKSRC}/examples/myMemReleaser/mymemreleaser ${PREFIX}/bin/mymemreleaser
	${INSTALL_PROGRAM} ${WRKSRC}/examples/simpleNodeCounter/simplenodecounter ${PREFIX}/bin/simplenodecounter
	${INSTALL_PROGRAM} ${WRKSRC}/examples/myStructureComputer/mystructurecomputer ${PREFIX}/bin/mystructurecomputer
	${INSTALL_PROGRAM} ${WRKSRC}/examples/infoReader/inforeader ${PREFIX}/bin/inforeader
	${INSTALL_PROGRAM} ${WRKSRC}/examples/redefineNodeTester/redefineNodeTester ${PREFIX}/bin/redefineNodeTester
	${INSTALL_PROGRAM} ${WRKSRC}/examples/icosahedronViewer/icosahedronViewer ${PREFIX}/bin/icosahedronViewer
	${INSTALL_PROGRAM} ${WRKSRC}/examples/simpleAnimationViewer/simpleanimationviewer ${PREFIX}/bin/simpleanimationviewer

.include <bsd.port.post.mk>
