# New ports collection makefile for:	glheretic
# Date created:		04 Feb 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	heretic
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://heretic.linuxgames.com/heretic/src/:source \
		http://heretic.linuxgames.com/wad/:wad
DISTNAME=	gl${PORTNAME}-${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Unix source-port of the famous Heretic game by id Software

USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}

OPTIONS=	X11	"Use X11"		on \
		FASTX11	"Use FastX11"		off \
		SDL	"Use SDL"		off \
		WAD	"With shareware WAD"	on

.include <bsd.port.pre.mk>

.if (defined(WITH_X11) && (defined(WITH_FASTX11) || defined(WITH_SDL))) || \
    (defined(WITH_FASTX11) && (defined(WITH_X11) || defined(WITH_SDL)))
IGNORE=		you must only define X11, xor FASTX11, xor SDL
.endif

.if defined(WITH_X11)
ALL_TARGET=	x11
BINARY=		xheretic
.endif

.if defined(WITH_FASTX11)
ALL_TARGET=	fastx11
BINARY=		xaheretic
.endif

.if defined(WITH_SDL)
USE_SDL=	yes
ALL_TARGET=	sdl
BINARY=		sdlheretic
CFLAGS+=	`${SDL_CONFIG} --cflags`
.endif

.if defined(WITH_WAD)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source heretic_share.wad.gz:wad
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
PLIST_SUB=	WAD:=""
.else
PLIST_SUB=	WAD:="@comment "
.endif

post-extract:
.if !defined(WITHOUT_WAD)
	@${GZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/heretic_share.wad.gz \
		> ${WRKSRC}/heretic_share.wad
.endif
	@${FIND} ${WRKSRC} -name .depend -type f -delete

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${PREFIX}/bin/heretic
	${INSTALL_PROGRAM} ${WRKSRC}/sndserver ${PREFIX}/bin/sndserver
.if !defined(WITHOUT_WAD)
	@${MKDIR} ${PREFIX}/share/heretic
	${INSTALL_DATA} ${WRKSRC}/heretic_share.wad ${PREFIX}/share/heretic
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/heretic
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/heretic
.endif

.include <bsd.port.post.mk>
