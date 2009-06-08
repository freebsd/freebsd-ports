# New ports collection makefile for:	sdlmess
# Date created:				2007-01-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	sdlmess
PORTVERSION=	0.131
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.arcadebsd.org/pub/FreeBSD/ports/distfiles/ \
		http://rbelmont.mameworld.info/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	elbarto@ArcadeBSD.org
COMMENT=	SDL port of the popular MESS (Multiple Emulator Super System)

FETCH_ENV=	HTTP_USER_AGENT=defined
USE_ZIP=	yes
USE_XORG=	xext xrender xinerama xi
USE_GL=		gl
USE_GNOME?=	gtk20 gconf2
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
USE_SDL=	sdl
MAKEFILE=	makefile.sdl
ONLY_FOR_ARCH=	i386 amd64
SUB_FILES=	pkg-message

OPTIONS=	DEBUG "Build sdlmess debugger" off

.include <bsd.port.pre.mk>

.if !defined(WITH_DEBUG)
USE_GNOME=		#
EXTRA_PATCHES+=		${FILESDIR}/sdl.mak.patch
.endif

MAKE_JOBS_UNSAFE=	yes

.if ${ARCH} == "amd64"
MAKE_ENV+=	PTR64=1
.endif
.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|ui.bdf|${DATADIR}/ui.bdf|g" ${WRKSRC}/src/emu/ui.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/libexec/sdlmess
	${INSTALL_PROGRAM} ${WRKSRC}/chdman ${PREFIX}/libexec/sdlmess
	${INSTALL_PROGRAM} ${WRKSRC}/ldresample ${PREFIX}/libexec/sdlmess
	${INSTALL_PROGRAM} ${WRKSRC}/ldverify ${PREFIX}/libexec/sdlmess
	${INSTALL_PROGRAM} ${WRKSRC}/testkeys ${PREFIX}/libexec/sdlmess
	${INSTALL_PROGRAM} ${WRKSRC}/imgtool ${PREFIX}/libexec/sdlmess
	${INSTALL_PROGRAM} ${WRKSRC}/jedutil ${PREFIX}/libexec/sdlmess
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs ${DOCSDIR}
.endif
	${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/ui.bdf ${DATADIR}/
	${CP} -R ${WRKSRC}/keymaps ${DATADIR}/
	${CP} -R ${WRKSRC}/hash ${DATADIR}/
	${CP} -R ${WRKSRC}/artwork ${DATADIR}/
	${MKDIR} ${EXAMPLESDIR}
	${CP} ${FILESDIR}/mess.ini ${EXAMPLESDIR}

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
