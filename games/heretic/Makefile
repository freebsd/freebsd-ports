# New ports collection makefile for:	glheretic
# Date created:		04 Feb 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	heretic
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	http://heretic.linuxgames.com/heretic/src/ \
		http://heretic.linuxgames.com/wad/
DISTNAME=	gl${PORTNAME}-${PORTVERSION}
.if !defined(WITHOUT_WAD)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} heretic_share.wad.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	lehmann@ans-netz.de

USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}

ALL_TARGET=	x11
BINARY=		xheretic

.if defined(WITH_FASTX11)
ALL_TARGET=	fastx11
BINARY=		xaheretic
.endif

.if defined(WITH_SDL)
ALL_TARGET=	sdl
BINARY=		sdlheretic
LIB_DEPENDS=	SDL-1.0.2:${PORTSDIR}/devel/sdl10
.endif

.if defined(WITHOUT_WAD)
PLIST_SUB=	WAD:="@comment "
.else
PLIST_SUB=	WAD:=""
.endif

pre-everything:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_FASTX11=yes  Use FastX11 support"
	@${ECHO} "      WITH_SDL=yes      Use SDL."
	@${ECHO} "      WITHOUT_WAD=yes   Don't install the wad file."
	@${ECHO} ""

post-extract:
.if !defined(WITHOUT_WAD)
	@${GZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/heretic_share.wad.gz \
		> ${WRKSRC}/heretic_share.wad
.endif

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

.include <bsd.port.mk>
