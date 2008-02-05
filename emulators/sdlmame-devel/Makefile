# New ports collection makefile for:	sdlmame
# Date created:				2007-01-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	sdlmame
PORTVERSION=	0.122u8
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.alepulver.com.ar/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	SDL port of the popular MAME (Multi Arcade Machine Emulator)

USE_ZIP=	yes
USE_GL=		yes
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

# In FreeBSD 5.x fails to build due to an internal compiler error. Using the
# version 3.4 from ports which probably fixes this error requires a hack to
# get around bsd.gcc.mk handling, so use a higher version than in base system.
.if ${OSVERSION} < 600000
USE_GCC=	4.2+
.endif

.include <bsd.port.post.mk>
