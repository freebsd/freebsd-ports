PORTNAME=	xdpi
DISTVERSION=	g20240413
CATEGORIES=	deskutils

MAINTAINER=	nimaje+fbz@bureaucracy.de
COMMENT=	X11 DPI information retrieval
WWW=		https://github.com/Oblomov/xdpi

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS+=	libxcb-xrm.so:x11/xcb-util-xrm

USES=		localbase:ldflags xorg

USE_GITHUB=	yes
GH_ACCOUNT=	Oblomov
GH_TAGNAME=	b902c3df22152b79d95c9afba84d309d714e855a
USE_XORG=	x11 xcb xinerama xrandr

ALL_TARGET=	xdpi

PLIST_FILES=	bin/xdpi

CFLAGS+=	-DWITH_XCB=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdpi ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
