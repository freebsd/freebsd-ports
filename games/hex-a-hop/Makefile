# Created by: jamie
# $FreeBSD$

PORTNAME=	hex-a-hop
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME:S/-//g}/${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Puzzle game based on hexagonal tiles

USE_SDL=	sdl
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	PANGO SOUND NLS DEBUG
OPTIONS_DEFAULT=	SOUND
PANGO_DESC=	Use sdl_pango instead of sdl_ttf
SOUND_DESC=	Sound support

DESKTOP_ENTRIES="Hex-a-Hop" "${COMMENT}" \
		"${DATADIR}/icon.bmp" \
		"hex-a-hop" "LogicGame;Game;" false

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--disable-debug
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ENV+=	ac_cv_header_libintl_h=yes
LDFLAGS+=	-lintl
.else
CONFIGURE_ENV+=	ac_cv_header_libintl_h=no
.endif

.if ${PORT_OPTIONS:MPANGO}
USE_SDL+=	pango
CONFIGURE_ARGS+=--disable-sdlttf
.else
USE_SDL+=	ttf
.endif

.if ${PORT_OPTIONS:MSOUND}
USE_SDL+=	mixer
.else
CONFIGURE_ARGS+=--disable-sound
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -E '/CFLAGS|CXXFLAGS/s/-g//' ${WRKSRC}/configure

.include <bsd.port.mk>
