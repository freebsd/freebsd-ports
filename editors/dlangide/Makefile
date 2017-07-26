# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dlangide
PORTVERSION=	0.7.30
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	acm@FreeBSD.org
COMMENT=	D language IDE based on DlangUI

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		dub:devel/dub \
		${LOCALBASE}/lib/d/libdlangui.a:devel/dlangui \
		${LOCALBASE}/lib/d/libdsymbol.a:devel/dsymbol \
		${LOCALBASE}/lib/d/libdparse.a:devel/libdparse \
		${LOCALBASE}/lib/d/libemsi_containers.a:devel/containers \
		${LOCALBASE}/lib/d/libmsgpack-d.a:devel/msgpack-d \
		${LOCALBASE}/lib/d/libdlib.a:devel/dlib \
		${LOCALBASE}/lib/d/libDerelictUtil.a:devel/derelict-util \
		${LOCALBASE}/lib/d/libDerelictGL3.a:graphics/derelict-gl3 \
		${LOCALBASE}/lib/d/libDerelictSDL2.a:devel/derelict-sdl2 \
		${LOCALBASE}/lib/d/libDerelictFT.a:print/derelict-ft \
		dcd-server:devel/dcd-server

USE_GITHUB=	yes
GH_ACCOUNT=	buggins

PLIST_FILES=	bin/${PORTNAME}
DUB_CMD=	${LOCALBASE}/bin/dub build --build=release

do-build:
	@cd ${WRKSRC} && ${DUB_CMD}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
