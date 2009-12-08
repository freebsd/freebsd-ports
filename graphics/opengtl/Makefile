# New ports collection makefile for:	opengtl
# Date created:				28 September 2009
# Whom:					Alberto Villa <villa.alberto@gmail.com>
# $FreeBSD$

PORTNAME=	opengtl
PORTVERSION=	0.9.12
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.opengtl.org/download/
DISTNAME=	OpenGTL-${PORTVERSION}

MAINTAINER=	villa.alberto@gmail.com
COMMENT=	Graphics Transformation Languages

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
BUILD_DEPENDS=	llvm>=2.5:${PORTSDIR}/devel/llvm

USE_BZIP2=	yes
USE_PERL5=	yes
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes
CMAKE_USE_PTHREAD=	yes

post-patch:
#disable layex doc, it not ready yer
	${REINPLACE_CMD} -e '/add_subdirectory.*doc/d' \
		${PATCH_WRKSRC}/OpenShiva/CMakeLists.txt

pre-configure:
	${REINPLACE_CMD} -e 's|set(OPENGTL_LIB_SOVERSION.*|set(OPENGTL_LIB_SOVERSION "0")|' \
		${PATCH_WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${PATCH_WRKSRC}/OpenCTL/OpenCTL/CMakeLists.txt \
		${PATCH_WRKSRC}/OpenGTL/GTLCore/CMakeLists.txt \
		${PATCH_WRKSRC}/OpenGTL/GTLImageIO/CMakeLists.txt \
		${PATCH_WRKSRC}/OpenShiva/OpenShiva/CMakeLists.txt
	${REINPLACE_CMD} -e 's|(int) pthread_self|(unsigned long long) pthread_self|' \
		${PATCH_WRKSRC}/OpenGTL/GTLCore/MemoryManager_p.cpp

.include <bsd.port.mk>
