# New ports collection makefile for:	volpack
# Date created:		2012-05-29
# Whom:			Guido Falsi <madpilot@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	volpack
PORTVERSION=	1.0b3
CATEGORIES=	graphics
MASTER_SITES=	http://www-graphics.stanford.edu/software/volpack/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Portable software library for volume rendering

LICENCE=	BSD

GNU_CONFIGURE=	yes

PLIST_FILES=	lib/libvolpack.a \
		include/volpack.h

MAN3=		BruteForce.3 Callback.3 ClientData.3 ClsfyScalar.3 \
		ClsfyScan.3 ClsfyTable.3 ClsfyVolume.3 Context.3 \
		CurrentMatrix.3 Debug.3 DepthCueing.3 Enable.3 Error.3 \
		Extract.3 Filter.3 FilterTab.3 Get.3 GetImage.3 \
		GetLight.3 GetMaterial.3 GetMatrix.3 Identity.3 \
		Image.3 Light.3 LinAlgebra.3 Load.3 LookupShader.3 \
		Material.3 MinMaxOctree.3 MultMatrix.3 NormalIndex.3 \
		OctreeMask.3 Ramp.3 RawVoxels.3 Render.3 Resample.3 \
		Rotate.3 Scale.3 ScanNormals.3 Set.3 SetMatrix.3 \
		ShadeTable.3 Shadow.3 Store.3 Timer.3 TracePixel.3 \
		Translate.3 Transpose.3 VolPack.3 VolumeNormals.3 \
		VolumeSize.3 VoxelField.3 VoxelSize.3 Window.3 WindowPHIGS.3

.include <bsd.port.mk>
