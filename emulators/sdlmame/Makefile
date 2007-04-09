# New ports collection makefile for:	sdlmame
# Date created:				2007-01-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	sdlmame
PORTVERSION=	0.114
CATEGORIES=	emulators
MASTER_SITES=	http://rbelmont.mameworld.info/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	SDL port of the popular MAME (Multi Arcade Machine Emulator)

USE_ZIP=	yes
USE_GL=		yes
USE_GMAKE=	yes
USE_SDL=	sdl
MAKEFILE=	makefile

SUB_FILES=	${PORTNAME} pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
.for f in obj/mame/file2str obj/mame/png2bdc mame testkeys romcmp chdman \
	  jedutil makemeta regrep srcclean
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/libexec/${PORTNAME}
.endfor
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ui.bdf ${DATADIR}
	cd ${DATADIR} && ${MKDIR} artwork cfg comments diff ini nvram roms
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
