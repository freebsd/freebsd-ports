# New ports collection makefile for:	sdlmess
# Date created:				2007-01-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	sdlmess
PORTVERSION=	0.116
CATEGORIES=	emulators
MASTER_SITES=	http://rbelmont.mameworld.info/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	SDL port of MESS (Multiple Emulator Super System)

USE_ZIP=	yes
USE_GL=		yes
USE_GMAKE=	yes
USE_SDL=	sdl
MAKEFILE=	makefile.sdl

SUB_FILES=	${PORTNAME} pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
.for f in obj/sdlmess/file2str sdlmess testkeys dat2html messtest messdocs \
	  imgtool romcmp chdman jedutil makemeta regrep srcclean
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/libexec/${f:T:S/sdl//}
.endfor
	${MKDIR} ${DATADIR}
.for f in artwork hash keymaps sysinfo.dat
	${CP} -R ${WRKSRC}/${f} ${DATADIR}
.endfor
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
