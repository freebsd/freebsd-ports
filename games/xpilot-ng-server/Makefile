# New ports collection makefile for:	xpilot-ng
# Date created:			11 Sep 2003
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	xpilot-ng
PORTVERSION=	4.7.2
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/xpilot/xpilot_ng/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX?=	-server

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	An enhanced version of XPilot (server program)

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
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

OPTIONS=	SDL "SDL/OpenGL client" on \
		SOUND "Sound" off
.endif

.include <bsd.port.pre.mk>

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
.if defined(WITH_SDL)
USE_SDL=	image sdl ttf
USE_GL=		yes
PLIST_SUB+=	SDL=""
MAN6+=		xpilot-ng-sdl.6
.else
CONFIGURE_ARGS+=--disable-sdl-client
PLIST_SUB+=	SDL="@comment "
.endif

.if defined(WITH_SOUND)
LIB_DEPENDS+=	openal:${PORTSDIR}/audio/openal
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
.if defined(WITHOUT_SDL)
	@${REINPLACE_CMD} -e 's|xpilot-ng-sdl\.man||' \
		${WRKSRC}/doc/man/Makefile.in
.endif
.endif

.include <bsd.port.post.mk>
