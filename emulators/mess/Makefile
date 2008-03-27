# New ports collection makefile for:	sdlmess
# Date created:				2007-01-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	sdlmess
PORTVERSION=	0.122
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.alepulver.com.ar/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	SDL port of MESS (Multiple Emulator Super System)

USE_ZIP=	yes
USE_GL=		gl
USE_XORG=	xext xrender xinerama xi
USE_GMAKE=	yes
USE_SDL=	sdl
MAKEFILE=	makefile.sdl

SUB_FILES=	${PORTNAME} pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/libexec/sdlmess
.for f in obj/sdl/mess/build/file2str obj/sdl/mess/build/png2bdc mess \
	testkeys dat2html messtest imgtool romcmp chdman jedutil makemeta \
	regrep srcclean src2html
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/libexec/sdlmess
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
