# Created by: Natacha Porté <natbsd@instinctive.eu>
# $FreeBSD$

PORTNAME=	luxrays
PORTVERSION=	1.2.1
CATEGORIES=	graphics
MASTER_SITES=	http://src.luxrender.net/luxrays/archive/
DISTNAME=	${HG_NODEID}
DIST_SUBDIR=	luxrender

MAINTAINER=	natbsd@instinctive.eu
COMMENT=	Accelerate the ray intersection process by using GPUs

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/lib/libfreeimage.a:${PORTSDIR}/graphics/freeimage
LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs

HG_NODEID=	475fbf15f0ca

USES=		bison cmake
USE_BZIP2=	yes
USE_GL=		glew glut
WRKSRC=		${WRKDIR}/luxrays-${HG_NODEID}

CMAKE_ARGS=	-DLUXRAYS_DISABLE_OPENCL:BOOL=ON

NO_STAGE=	yes
do-install:
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${PREFIX}/include)
	${INSTALL_DATA} ${WRKSRC}/lib/libluxrays.a ${PREFIX}/lib

.include <bsd.port.mk>
