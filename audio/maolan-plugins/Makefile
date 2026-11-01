PORTNAME=	maolan-plugins
DISTVERSION=	0.1.3
CATEGORIES=	audio

MAINTAINER=	meka@sys.it.com
COMMENT=	CLAP plugins from the Maolan ecosystem
WWW=		https://maolan.rs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libX11.so:x11/libX11 \
		libXcursor.so:x11/libXcursor \
		libXi.so:x11/libXi \
		libxkbcommon.so:x11/libxkbcommon \
		libXrandr.so:x11/libXrandr

USES=		cargo pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	maolan
GH_PROJECT=	plugins

CARGO_INSTALL=	no

PLIST_FILES=	lib/clap/Maolan.clap

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/clap
	${INSTALL_LIB} ${WRKDIR}/target/release/libmaolan_plugins.so ${STAGEDIR}${PREFIX}/lib/clap/Maolan.clap

.include <bsd.port.mk>
