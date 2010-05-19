# New ports collection makefile for:	sdlmame
# Date created:				2007-01-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	mame
PORTVERSION=	0.138
CATEGORIES=	emulators
MASTER_SITES=	http://www.aarongiles.com/mirror/releases/ \
		ftp://ftp.arcadebsd.org/pub/ArcadeBSD/ports/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}s

MAINTAINER=	elbarto@ArcadeBSD.org
COMMENT=	The popular MAME (Multi Arcade Machine Emulator)

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
USE_XORG=	xext xrender xinerama xi
USE_GL=		gl
USE_GNOME?=	gtk20 gconf2
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
USE_SDL=	sdl
USE_GCC=	4.2+
MAKEFILE=	makefile
ONLY_FOR_ARCHS=	i386 amd64
SUB_FILES=	pkg-message
USE_DOS2UNIX=	makefile sdl.mak

OPTIONS=	DEBUG "Build mame debugger" off

.include <bsd.port.pre.mk>

.if !defined(WITH_DEBUG)
USE_GNOME=		#
EXTRA_PATCHES+=		${FILESDIR}/sdl.mak.patch
.endif

MAKE_JOBS_SAFE=	yes

.if ${ARCH} == "amd64"
MAKE_ENV+=	PTR64=1
.endif
.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-extract:
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKDIR}/mame.zip ${EXTRACT_AFTER_ARGS}
	@${RM} -f ${WRKDIR}/mame.zip

post-patch:
	@${REINPLACE_CMD} -e "s|ui.bdf|${DATADIR}/ui.bdf|g" ${WRKSRC}/src/emu/ui.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/chdman ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/ldresample ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/ldverify ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/romcmp ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/testkeys ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/unidasm ${PREFIX}/libexec/${PORTNAME}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs ${DOCSDIR}
.endif
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/src/osd/sdl/keymaps ${DATADIR}/
	${MKDIR} ${EXAMPLESDIR}
	${CP} ${FILESDIR}/mame.ini ${EXAMPLESDIR}

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
