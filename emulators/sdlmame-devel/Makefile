# New ports collection makefile for:	sdlmame
# Date created:				2007-01-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	sdlmame
PORTVERSION=	0.124
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.alepulver.com.ar/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	SDL port of the popular MAME (Multi Arcade Machine Emulator)

USE_ZIP=	yes
USE_XORG=	xext xrender xinerama xi
USE_GL=		gl
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
USE_SDL=	sdl
MAKEFILE=	makefile

SUB_FILES=	${PORTNAME} pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/libexec/sdlmame
.for f in obj/sdl/mame/build/file2str obj/sdl/mame/build/png2bdc mame \
	testkeys romcmp chdman jedutil makemeta regrep srcclean
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/libexec/sdlmame
.endfor
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ui.bdf ${DATADIR}
	${CP} -R ${WRKSRC}/keymaps ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
