# New ports collection makefile for:	sdlmame
# Date created:				2007-01-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	mame
PATCHLEVEL=	2
PORTVERSION=	0.143${PATCHSUFFIX}
CATEGORIES=	emulators
MASTER_SITES=	http://mame.mirrors.zippykid.com/releases/:src \
		http://emumovies.com/aarongiles/releases/:src \
		http://mamedev.mameworld.info/releases/:src \
		http://mamedev.thiswebhost.com/releases/:src \
		ftp://ftp.arcadebsd.org/pub/ArcadeBSD/ports/distfiles/:src \
		http://mamedev.org/updates/:patchsets
DISTFILES=	\
	${PORTNAME}${PORTVERSION:S/.//:C/\.p[0-9]*$//}s${EXTRACT_SUFX}:src \
	${UPDATE_PATCHES:C/$/.zip:patchsets/}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	elbarto@ArcadeBSD.org
COMMENT=	The popular MAME (Multi Arcade Machine Emulator)

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
USE_XORG=	xext xrender xinerama xi
USE_GL=		gl
USE_GNOME?=	gtk20 gconf2
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
USE_SDL=	sdl ttf
USE_GCC=	4.2+
MAKEFILE=	makefile
ONLY_FOR_ARCHS=	i386 amd64
SUB_FILES=	pkg-message
USE_DOS2UNIX=	makefile sdl.mak debugcpu.c *.c *.h

PORTDOCS=	*
PORTEXAMPLES=	*

.if defined(PATCHLEVEL) && ${PATCHLEVEL}
PATCHSUFFIX=	.p${PATCHLEVEL}
UPDATE_PATCHES!=	/usr/bin/jot -s " " \
		-w ${PORTVERSION:S/.//:C/\.p[0-9]*$//}u%d_diff \
		${PATCHLEVEL} 1 ${PATCHLEVEL}
.endif

OPTIONS=	DEBUG "Build mame debugger" off

.include <bsd.port.pre.mk>

.if !defined(WITH_DEBUG)
USE_GNOME=		#
EXTRA_PATCHES+=		${PATCHDIR}/sdl.mak.patch
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
# Use post-extract target to get in before dos2unix-isation
.if defined(UPDATE_PATCHES)
. for patch in ${UPDATE_PATCHES:S/_/./}
	@${ECHO_MSG} -n "===> Applying upstream development patch ${patch}... "
	@${PATCH} ${PATCH_ARGS} < ${WRKSRC}/${patch}
	@${ECHO_MSG} "[DONE]"
. endfor
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|ui.bdf|${DATADIR}/ui.bdf|g" ${WRKSRC}/src/emu/ui.c
	@${REINPLACE_CMD} -e "s|int getc()|int getcf()|g" ${WRKSRC}/src/emu/fileio.h
	@${REINPLACE_CMD} -e "s|::getc()|::getcf()|g" ${WRKSRC}/src/emu/fileio.c

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
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} docs ${DOCSDIR})
.endif
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/src/osd/sdl/ && ${COPYTREE_SHARE} keymaps ${DATADIR})
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/mame.ini ${EXAMPLESDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
