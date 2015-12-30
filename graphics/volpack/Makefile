# $FreeBSD$

PORTNAME=	volpack
PORTVERSION=	1.0b3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://graphics.stanford.edu/software/volpack/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Portable software library for volume rendering

LICENSE=	MIT

GNU_CONFIGURE=	yes
MAKE_ARGS=	MFLAGS=""	# required for bmake(1) and -jX builds

PLIST_FILES=	lib/libvolpack.a include/volpack.h \
		man/man3/volpack-BruteForce.3.gz man/man3/volpack-Callback.3.gz \
		man/man3/volpack-ClientData.3.gz man/man3/volpack-ClsfyScalar.3.gz \
		man/man3/volpack-ClsfyScan.3.gz man/man3/volpack-ClsfyTable.3.gz \
		man/man3/volpack-ClsfyVolume.3.gz man/man3/volpack-Context.3.gz \
		man/man3/volpack-CurrentMatrix.3.gz man/man3/volpack-Debug.3.gz \
		man/man3/volpack-DepthCueing.3.gz man/man3/volpack-Enable.3.gz \
		man/man3/volpack-Error.3.gz man/man3/volpack-Extract.3.gz \
		man/man3/volpack-Filter.3.gz man/man3/volpack-FilterTab.3.gz \
		man/man3/volpack-Get.3.gz man/man3/volpack-GetImage.3.gz \
		man/man3/volpack-GetLight.3.gz man/man3/volpack-GetMaterial.3.gz \
		man/man3/volpack-GetMatrix.3.gz man/man3/volpack-Identity.3.gz \
		man/man3/volpack-Image.3.gz man/man3/volpack-Light.3.gz \
		man/man3/volpack-LinAlgebra.3.gz man/man3/volpack-Load.3.gz \
		man/man3/volpack-LookupShader.3.gz man/man3/volpack-Material.3.gz \
		man/man3/volpack-MinMaxOctree.3.gz man/man3/volpack-MultMatrix.3.gz \
		man/man3/volpack-NormalIndex.3.gz man/man3/volpack-OctreeMask.3.gz \
		man/man3/volpack-Ramp.3.gz man/man3/volpack-RawVoxels.3.gz \
		man/man3/volpack-Render.3.gz man/man3/volpack-Resample.3.gz \
		man/man3/volpack-Rotate.3.gz man/man3/volpack-Scale.3.gz \
		man/man3/volpack-ScanNormals.3.gz man/man3/volpack-Set.3.gz \
		man/man3/volpack-SetMatrix.3.gz man/man3/volpack-ShadeTable.3.gz \
		man/man3/volpack-Shadow.3.gz man/man3/volpack-Store.3.gz \
		man/man3/volpack-Timer.3.gz man/man3/volpack-TracePixel.3.gz \
		man/man3/volpack-Translate.3.gz man/man3/volpack-Transpose.3.gz \
		man/man3/volpack-VolPack.3.gz man/man3/volpack-VolumeNormals.3.gz \
		man/man3/volpack-VolumeSize.3.gz man/man3/volpack-VoxelField.3.gz \
		man/man3/volpack-VoxelSize.3.gz man/man3/volpack-Window.3.gz \
		man/man3/volpack-WindowPHIGS.3.gz

.include <bsd.port.mk>
