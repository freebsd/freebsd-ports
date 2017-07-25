# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dlangui
PORTVERSION=	0.9.82
CATEGORIES=	devel
MASTER_SITES=	https://github.com/buggins/dlangui/archive/
DISTNAME=	${PORTVERSION:S/^/v/}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Cross Platform GUI for D programming language

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub \
		${LOCALBASE}/lib/d/libDerelictUtil.a:devel/derelict-util \
		${LOCALBASE}/lib/d/libDerelictGL3.a:graphics/derelict-gl3 \
		${LOCALBASE}/lib/d/libDerelictFT.a:print/derelict-ft \
		${LOCALBASE}/lib/d/libDerelictSDL2.a:devel/derelict-sdl2 \
		${LOCALBASE}/lib/d/libdlib.a:devel/dlib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DUB_CMD=	${LOCALBASE}/bin/dub build --build=release
D_INCLUDE_DIR=	${PREFIX}/include/d
D_LIB_DIR=	${PREFIX}/lib/d

post-patch:
	${REINPLACE_CMD} -e 's|DIMAGE;|DLIBIMAGE;|g' ${WRKSRC}/src/dlangui/graphics/images.d

do-build:
	@cd ${WRKSRC} && ${DUB_CMD}

do-install:
	@${MKDIR} ${STAGEDIR}${D_INCLUDE_DIR}
	@${MKDIR} ${STAGEDIR}${D_LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/lib/lib${PORTNAME}.a ${STAGEDIR}${D_LIB_DIR}
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${D_INCLUDE_DIR} "-name *\.d"

.include <bsd.port.mk>
