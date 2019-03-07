# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dlangide
PORTVERSION=	0.8.12
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	acm@FreeBSD.org
COMMENT=	D language IDE based on DlangUI

LICENSE=	BSL

BROKEN=		does not compile with latest version of ldc

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
		${LOCALBASE}/lib/d/libstdx-allocator.a:devel/stdx-allocator \
                ${LOCALBASE}/lib/d/libisfreedesktop.a:devel/isfreedesktop \
		${LOCALBASE}/lib/d/libinilike.a:devel/inilike \
		${LOCALBASE}/lib/d/libxdgpaths.a:devel/xdgpaths \
		${LOCALBASE}/lib/d/libicontheme.a:devel/icontheme \
		dcd-server:devel/dcd-server

USE_GITHUB=	yes
GH_ACCOUNT=	buggins

PLIST_FILES=	bin/${PORTNAME}
DUB_CMD=	${LOCALBASE}/bin/dub build --build=release

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/dub.json
	${REINPLACE_CMD} -e 's|server.|dcd.server.|g' \
		-e 's|common.messages|dcd.common.messages|g' \
			 ${WRKSRC}/src/dlangide/tools/d/dcdinterface.d

do-build:
	@cd ${WRKSRC} && ${DUB_CMD} --config=default
	@cd ${WRKSRC} && ${DUB_CMD} --config=console

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
