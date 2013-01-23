# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	xpilot-ng
PORTVERSION=	4.7.3
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/xpilot/xpilot_ng/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX?=	-server

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Enhanced version of XPilot (server program)

LICENSE=	GPLv2

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--program-prefix=""

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}

PKGFILESUFFIX=	${PKGNAMESUFFIX:S/-/./}
DESCR=		${PKGDIR}/pkg-descr${PKGFILESUFFIX}
PLIST=		${PKGDIR}/pkg-plist${PKGFILESUFFIX}

.if ${PKGNAMESUFFIX} == "-server"
MAN6=		xpilot-ng-server.6

CONFIGURE_ARGS+=--disable-replay \
		--disable-xp-mapedit \
		--disable-x11-client \
		--disable-sdl-client
.else		# client
MAN6=		xpilot-ng-replay.6 \
		xpilot-ng-x11.6 \
		xpilot-ng-xp-mapedit.6

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	SDL SOUND
OPTIONS_DEFAULT=	SDL
SOUND_DESC=	Enable sound support

DESKTOP_ENTRIES=	"Xpilot-ng X11" "Xpilot game client program" \
			"" "xpilot-ng-x11" "Game;ArcadeGame;" false \
			"Xpilot-ng Map Editor" "Xpilot Map Editor" \
			"" "xpilot-ng-xp-mapedit" "Game;ArcadeGame;" false
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
USE_SDL=	image sdl ttf
USE_GL=		yes
PLIST_SUB+=	SDL=""
MAN6+=		xpilot-ng-sdl.6
DESKTOP_ENTRIES+=	"Xpilot-ng SDL" "Xpilot game client program" \
			"" "xpilot-ng-sdl" "Game;ArcadeGame;" false
.else
CONFIGURE_ARGS+=--disable-sdl-client
PLIST_SUB+=	SDL="@comment "
.endif

.if ${PORT_OPTIONS:MSOUND}
USE_OPENAL=	al alut
CONFIGURE_ARGS+=--enable-sound
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
PLIST_SUB+=	SOUND=""
.else
PLIST_SUB+=	SOUND="@comment "
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
