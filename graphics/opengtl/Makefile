# New ports collection makefile for:	opengtl
# Date created:				28 September 2009
# Whom:					Alberto Villa <villa.alberto@gmail.com>
#
# $FreeBSD$

PORTNAME=	opengtl
PORTVERSION=	0.9.15
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	http://download.${PORTNAME}.org/
DISTNAME=	OpenGTL-${PORTVERSION}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Graphics Transformation Languages

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png
BUILD_DEPENDS=	llvm>=2.8<2.9.*:${PORTSDIR}/devel/llvm

USE_BZIP2=	yes
USE_GCC=	4.2+
USE_PERL5=	yes
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes
CMAKE_USE_PTHREAD=	yes

OPTIONS=	SHIVA	"Install filters and generators" on

.include <bsd.port.options.mk>

.ifndef(WITHOUT_SHIVA)
RUN_DEPENDS+=	${LOCALBASE}/share/OpenGTL/shiva/kernels/oilify.shiva:${PORTSDIR}/graphics/shiva-collections
.endif

post-patch:
# Disable latex doc, it's not ready yet.
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
