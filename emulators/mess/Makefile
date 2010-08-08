# New ports collection makefile for:	sdlmess
# Date created:				2007-01-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	mess
PORTVERSION=	0.139
CATEGORIES=	emulators
MASTER_SITES=	http://www.aarongiles.com/mirror/releases/:mame \
		http://www.mess.org/files/:mess \
		ftp://ftp.arcadebsd.org/pub/ArcadeBSD/ports/distfiles/
DISTFILES=	mame${PORTVERSION:S/.//}s.zip:mame \
		mess${PORTVERSION:S/.//}s.zip:mess

MAINTAINER=	elbarto@ArcadeBSD.org
COMMENT=	The popular MESS (Multiple Emulator Super System)

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
USE_XORG=	xext xrender xinerama xi
USE_GL=		gl
USE_GNOME?=	gtk20 gconf2
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" TARGET=mess
USE_SDL=	sdl
USE_GCC=	4.4+
MAKEFILE=	makefile
ONLY_FOR_ARCHS=	i386 amd64
SUB_FILES=	pkg-message
USE_DOS2UNIX=	sdl.mak debugcpu.c makefile

OPTIONS=	DEBUG "Build mess debugger" off

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
	${INSTALL_PROGRAM} ${WRKSRC}/imgtool ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/jedutil ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/ldresample ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/ldverify ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/testkeys ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/unidasm ${PREFIX}/libexec/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs ${DOCSDIR}
.endif
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/hash ${DATADIR}/
	${CP} -R ${WRKSRC}/artwork ${DATADIR}/
	${MKDIR} ${EXAMPLESDIR}
	${CP} ${FILESDIR}/mess.ini ${EXAMPLESDIR}

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
