# New ports collection makefile for:	deng
# Date created:		25 Aug 2004
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	deng
PORTVERSION=	1.9.0b4
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Doomsday%20Engine/1.9.0-beta4
DISTNAME=	${PORTNAME}-${PORTVERSION:S/b/-beta/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An enhanced Doom, Heretic and Hexen source port

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

USE_GL=		gl
USE_LDCONFIG=	yes
USE_SDL=	sdl mixer net
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
		`${SDL_CONFIG} --cflags`"
CONFIGURE_SCRIPT=	../configure
CONFIGURE_WRKSRC=	${BUILD_WRKSRC}
BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/Build
INSTALL_WRKSRC=	${BUILD_WRKSRC}

OPTIONS=	OPENAL "Build OpenAL sound plugin" off

SUB_FILES=	${PORTNAME} pkg-message

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/games/doom-data/Makefile.include"

.if defined(WITH_OPENAL) || exists(${LOCALBASE}/lib/libopenal.so.0)
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal
PLIST_SUB=	OPENAL=""
.else
PLIST_SUB=	OPENAL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's,-Wunused-variable -Wunused-function ,,; \
		 s,SDL(\\|/),,' \
		 ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${FIND} ${PATCH_WRKSRC} -name '*.[ch]' -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -Ee 's,SDL(\\|/),,'

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/*.txt ${DOCSDIR}
.for i in jDoom jHeretic jHexen
		@${MKDIR} ${DOCSDIR}/${i}
		${INSTALL_DATA} ${WRKSRC}/Doc/${i}/*.txt ${DOCSDIR}/${i}
.endfor
.endif
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
