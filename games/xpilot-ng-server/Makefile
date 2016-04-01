# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	xpilot-ng
PORTVERSION=	4.7.3
PORTREVISION?=	3
CATEGORIES=	games
MASTER_SITES=	SF/xpilot/xpilot_ng/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX?=	-server

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Enhanced version of XPilot (server program)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -Wno-return-type
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--program-prefix=""

PKGFILESUFFIX=	${PKGNAMESUFFIX:S/-/./}
DESCR=		${PKGDIR}/pkg-descr${PKGFILESUFFIX}
PLIST=		${PKGDIR}/pkg-plist${PKGFILESUFFIX}

.if ${PKGNAMESUFFIX} == "-server"
CONFIGURE_ARGS+=--disable-replay \
		--disable-xp-mapedit \
		--disable-x11-client \
		--disable-sdl-client
.else		# client
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-I${LOCALBASE}/include

DESKTOP_ENTRIES=	"Xpilot-ng X11" "Xpilot game client program" \
			"" "xpilot-ng-x11" "Game;ArcadeGame;" false \
			"Xpilot-ng Map Editor" "Xpilot Map Editor" \
			"" "xpilot-ng-xp-mapedit" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	SDL SOUND
OPTIONS_DEFAULT=	SDL
OPTIONS_SUB=	yes

SOUND_DESC=	Enable sound support
SOUND_CONFIGURE_ENABLE=	sound
SOUND_USES=	openal:al,alut

SDL_CONFIGURE_ENABLE=	sdl-client
SDL_USE=	SDL=image,sdl,ttf GL=yes
.endif

.include <bsd.port.options.mk>

.if ${PKGNAMESUFFIX} == "-server"
post-patch:
	@${REINPLACE_CMD} -e \
		's|xpilot-ng-sdl\.man||; \
		 s|xpilot-ng-x11\.man||; \
		 s|xpilot-ng-replay\.man||; \
		 s|xpilot-ng-xp-mapedit\.man||' ${WRKSRC}/doc/man/Makefile.in
	@${REINPLACE_CMD} -e \
		's| fonts||; s| textures||; s| shipshapes\.txt||' \
		${WRKSRC}/lib/Makefile.in
.else		# client
.if ${PORT_OPTIONS:MSDL}
DESKTOP_ENTRIES+=	"Xpilot-ng SDL" "Xpilot game client program" \
			"" "xpilot-ng-sdl" "Game;ArcadeGame;" false
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|mapconvert\.py||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|xpilot-ng-server\.man||' \
		${WRKSRC}/doc/man/Makefile.in
	@${REINPLACE_CMD} -e \
		's| maps||; s|defaults\.txt password\.txt robots\.txt||' \
		${WRKSRC}/lib/Makefile.in
	@${REINPLACE_CMD} -e 's| server||' ${WRKSRC}/src/Makefile.in
.if empty(PORT_OPTIONS:MSDL)
	@${REINPLACE_CMD} -e 's|xpilot-ng-sdl\.man||' \
		${WRKSRC}/doc/man/Makefile.in
.endif
.endif

.include <bsd.port.mk>
