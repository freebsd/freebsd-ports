# New ports collection makefile for:	deng
# Date created:		25 Aug 2004
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	deng
PORTVERSION=	1.8.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	An enhanced Doom, Heretic and Hexen source port

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${LOCALBASE}/bin/timidity:${PORTSDIR}/audio/timidity

USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} `${SDL_CONFIG} --cflags` -I${LOCALBASE}/include -I${X11BASE}/include" \
		CPPFLAGS="`${SDL_CONFIG} --cflags` -I${LOCALBASE}/include -I${X11BASE}/include"
USE_SDL=	sdl mixer net
USE_GL=		yes
INSTALLS_SHLIB=	yes
NOT_FOR_ARCHS=	amd64

PKGMESSAGE=	${WRKDIR}/pkg-message

.if exists(${LOCALBASE}/lib/libopenal.so.0) || defined(WITH_OPENAL)
WITH_OPENAL=	yes
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal
.endif

.if !defined(WITH_OPENAL)
PLIST_SUB=	WITH_OPENAL="@comment "
.else
PLIST_SUB=	WITH_OPENAL=""
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64" || ${ARCH} == "alpha"
BROKEN=		"Does not build on ia64, sparc64 or alpha"
.endif

.ifndef (WITH_OPENAL)
pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Optionally define WITH_OPENAL=yes to build OpenAL sound plugin"
	@${ECHO_CMD} ""
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's/-Wunused-.+ / /g; \
				 s/SDL(\\|\/)//g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name '*.[ch]' | \
		${XARGS} ${REINPLACE_CMD} -E -e 's/SDL(\\|\/)//g'

post-install:
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/*.txt ${DOCSDIR}
.for i in jDoom jHeretic jHexen
	@${MKDIR} ${DOCSDIR}/${i}
	${INSTALL_DATA} ${WRKSRC}/Doc/${i}/*.txt ${DOCSDIR}/${i}
.endfor
.endif
	@(${SED} -e 's|%%PREFIX%%|${PREFIX}|; s|%%DOCSDIR%%|${DOCSDIR}|' \
		<pkg-message >${PKGMESSAGE} && ${CAT} ${PKGMESSAGE})

.include <bsd.port.post.mk>
