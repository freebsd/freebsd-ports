# New ports collection makefile for:	deng
# Date created:		25 Aug 2004
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	deng
PORTVERSION=	1.8.1.r4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-1.8.1-rc4

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	An enhanced Doom, Heretic and Hexen source port

USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} `${SDL_CONFIG} --cflags` -I${LOCALBASE}/include -I${X11BASE}/include" \
		CPPFLAGS="`${SDL_CONFIG} --cflags` -I${LOCALBASE}/include -I${X11BASE}/include"
USE_SDL=	sdl mixer net
USE_GL=		yes
INSTALLS_SHLIB=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libopenal.so.0)
WITH_OPENAL=	yes
BUILD_DEPENDS=	${LOCALBASE}/lib/libopenal.so.0:${PORTSDIR}/audio/openal
RUN_DEPENDS=	${LOCALBASE}/lib/libopenal.so.0:${PORTSDIR}/audio/openal
.endif

.if !defined(WITH_OPENAL)
PLIST_SUB=	WITH_OPENAL="@comment "
.else
PLIST_SUB=	WITH_OPENAL=""
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
