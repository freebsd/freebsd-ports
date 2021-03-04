# $FreeBSD$

PORTNAME=	bzflag
PORTVERSION=	2.4.22
CATEGORIES=	games
MASTER_SITES=	https://download.bzflag.org/bzflag/source/${PORTVERSION}/

MAINTAINER=	kevinz5000@gmail.com
COMMENT?=	Multiplayer 3D tank battle game

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libcares.so:dns/c-ares

GNU_CONFIGURE=	yes
USES=		autoreconf compiler:c++11-lib libtool localbase tar:bzip2
INSTALL_TARGET=	install-strip

.ifndef SERVER_ONLY
USES+=		gl sdl xorg
USE_GL=		gl glu glew
USE_SDL=	sdl
USE_XORG=	x11 xext xxf86vm sm ice xcb xshmfence xdamage xfixes
.endif

CONFIGURE_ARGS=	--enable-ares-build
CPPFLAGS+=	-I ${LOCALBASE}/include

.ifdef SERVER_ONLY
CONFIGURE_ARGS+=	--disable-client
PLIST_SUB+=		CLIENT="@comment "
.else
DESKTOP_ENTRIES=	"BZFlag" "Battle enemy tanks" \
			"${DATADIR}/bzflag-256x256.png" \
			"bzflag" "Game;ActionGame;" false
PLIST_SUB+=		CLIENT=""
.endif

.include <bsd.port.mk>
