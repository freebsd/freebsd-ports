# New ports collection makefile for:	hex-a-hop
# Date created:				21 February 2006
# Whom:					jamie
#
# $FreeBSD$
#

PORTNAME=	hex-a-hop
PORTVERSION=	1.1.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME:S/-//g}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jamie@bishopston.net
COMMENT=	A puzzle game based on hexagonal tiles

USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	PANGO "Use sdl_pango instead of sdl_ttf" off \
		SOUND "Compile sound support" on

DESKTOP_ENTRIES="Hex-a-Hop" "A puzzle game based on hexagonal tiles" \
		"${DATADIR}/icon.bmp" \
		"hex-a-hop" "Application;LogicGame;Game;" false

.include <bsd.port.pre.mk>

.if !defined(WITH_DEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ENV+=	ac_cv_header_libintl_h=yes
LDFLAGS+=	-lintl
.else
CONFIGURE_ENV+=	ac_cv_header_libintl_h=no
.endif

.if !defined(WITHOUT_PANGO)
USE_SDL+=	pango
CONFIGURE_ARGS+=--disable-sdlttf
.else
USE_SDL+=	ttf
.endif

.if !defined(WITHOUT_SOUND)
USE_SDL+=	mixer
.else
CONFIGURE_ARGS+=--disable-sound
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -E '/CFLAGS|CXXFLAGS/s/-g//' ${WRKSRC}/configure

.include <bsd.port.post.mk>
