# $FreeBSD$

PORTNAME=	imhex
PORTVERSION=	1.5.0
CATEGORIES=	editors

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Hex editor for reverse engineers and programmers

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	__uint128_t and __int128_t are not supported

BUILD_DEPENDS=	c++10:lang/gcc10 \
		glm>0:math/glm \
		nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libcapstone.so:devel/capstone4 \
		libglfw.so:graphics/glfw \
		libstdc++.so:lang/gcc10 \
		libtre.so:textproc/libtre

USES=		cmake pkgconfig python:3.8+ ssl xorg
USE_XORG=	x11 xcb xau xdmcp
USE_GITHUB=	yes
GH_ACCOUNT=	WerWolv
GH_PROJECT=	ImHex
GH_TAGNAME=	v1.5.0

CXX=	${LOCALBASE}/bin/c++10

PLIST_FILES=	bin/imhex
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS NLS
NLS_USES=	gettext

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/imhex ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
