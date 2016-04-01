# $FreeBSD$

PORTNAME=	bzflag
PORTVERSION=	2.4.2
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20source/${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT?=	Multiplayer 3D tank battle game

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

GNU_CONFIGURE=	yes
USES=		libtool tar:bzip2

.ifndef SERVER_ONLY
USE_GL=		glew
USE_SDL=	sdl
.endif

MAKE_JOBS_UNSAFE=	yes

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
