# New ports collection makefile for:   panorama-tools
# Date created:        26 august 2004
# Whom:                cartola (Carlos E. G. Carvalho)
#
# $FreeBSD$
#
# This port has been made as a building dependence for the hugin port.
# As far as I could test the hugin port runs without this port installed, so the package
# does not need to refer to this dependence.
# The hugin port is a gui interface to interact with panorama tools.

PORTNAME=	vigra
PORTVERSION=	1.7.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://hci.iwr.uni-heidelberg.de/vigra/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	vd@FreeBSD.org
COMMENT=	VIGRA stands for "Vision with Generic Algorithms"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_CMAKE=	yes
CMAKE_ARGS=	-DDEPENDENCY_SEARCH_PREFIX:PATH=${LOCALBASE} \
		-DDOCINSTALL:PATH=${DOCSDIR_REL} \
		-DWITH_HDF5=1

USE_LDCONFIG=	yes

# Vigra's CMakeLists.txt does not support disabling those so we hook them
# as dependencies here unconditionally (without OPTIONS=) even though if
# they are not present then Vigra/CMake will do without them (they are not
# mandatory).
#
# Notice that if you define e.g. WITHOUT_VIGRA_TIFF and graphics/tiff is
# installed on your system, then the lib will be picked up by Vigra, the
# dependency will not be recorded by the ports system and later deletion
# of graphics/tiff will break Vigra. Only define WITHOUT_VIGRA_TIFF if you
# do not have graphics/tiff installed and do not want TIFF support in Vigra.

.if !defined(WITHOUT_VIGRA_TIFF)
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
.endif

.if !defined(WITHOUT_VIGRA_JPEG)
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
.endif

.if !defined(WITHOUT_VIGRA_PNG)
LIB_DEPENDS+=	png:${PORTSDIR}/graphics/png
.endif

.if !defined(WITHOUT_VIGRA_FFTW)
LIB_DEPENDS+=	fftw3:${PORTSDIR}/math/fftw3
.endif

.if !defined(WITHOUT_VIGRA_HDF5)
LIB_DEPENDS+=	hdf5.7:${PORTSDIR}/science/hdf5-18
.endif

.include <bsd.port.mk>
