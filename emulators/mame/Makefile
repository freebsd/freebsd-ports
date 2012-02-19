# New ports collection makefile for:	sdlmame
# Date created:				2007-01-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	mame
PORTVERSION=	0.145${PATCHSUFFIX}
CATEGORIES=	emulators
MASTER_SITES=	http://mame.mirrors.zippykid.com/releases/ \
		http://emumovies.com/aarongiles/releases/ \
		http://mamedev.mameworld.info/releases/ \
		http://mamedev.thiswebhost.com/releases/ \
		http://mamedev.org/updates/:patchsets
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//:C/\.p[0-9]*$//}s
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${UPDATE_PATCHES:C/$/.zip:patchsets/}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The popular MAME (Multi Arcade Machine Emulator)

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	liberation-fonts-ttf>=0:${PORTSDIR}/x11-fonts/liberation-fonts-ttf

OPTIONS=	BUILTIN_DEBUGGER "Enable builtin debugger support" off

ONLY_FOR_ARCHS=	i386 amd64

NO_WRKSUBDIR=	yes

USE_ZIP=	yes
USE_XORG=	xext xi xinerama xrender
USE_GL=		gl
USE_SDL=	sdl ttf
USE_GCC=	4.4+
USE_GMAKE=	yes
MAKE_ENV=	NOWERROR=1 OPT_FLAGS="${CXXFLAGS}" GCC_LDFLAGS="${LDFLAGS}"
MAKEFILE=	makefile
MAKE_JOBS_SAFE=	yes

SUB_FILES=	pkg-message

PATCHLEVEL=	# none

.if defined(PATCHLEVEL) && ${PATCHLEVEL}
PATCHSUFFIX=	.p${PATCHLEVEL}
UPDATE_PATCHES!=	/usr/bin/jot -s " " \
		-w ${PORTVERSION:S/.//:C/\.p[0-9]*$//}u%d_diff \
		${PATCHLEVEL} 1 ${PATCHLEVEL}
.endif

.include <bsd.port.options.mk>

.if defined(WITH_BUILTIN_DEBUGGER)
USE_GNOME=	gtk20 gconf2
MAKE_ENV+=	GTK_INCPATH="$$(pkg-config --cflags-only-I gtk+-2.0 gconf-2.0)" \
		GTK_CCOMFLAGS="$$(pkg-config --cflags-only-other gtk+-2.0 gconf-2.0)" \
		GTK_LIBS="$$(pkg-config --libs gtk+-2.0 gconf-2.0)"
.else
MAKE_ENV+=	NO_DEBUGGER=1 \
		GTK_INCPATH="" \
		GTK_CCOMFLAGS="" \
		GTK_LIBS=""
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
MAKE_ENV+=	PTR64=1
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
	@${REINPLACE_CMD} -e \
		's|^BUILD_EXPAT|# BUILD_EXPAT| ; \
		 s|^BUILD_ZLIB|# BUILD_ZLIB| ; \
		 /--warn-common/s|= -Wl,|= $$(GCC_LDFLAGS) -Wl,| ; \
		 s| = @gcc| := $$(CC)| ; \
		 s| = @g++| := $$(CXX)| ; \
		 s|^FULLNAME =.*|FULLNAME = $$(NAME)|' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e \
		'/-system/s|/usr/local/|${LOCALBASE}/| ; \
		 /--cflags-only-I gtk+-2.0/s|=.*|= $$(GTK_INCPATH)| ; \
		 /--cflags-only-other gtk+-2.0/s|=.*|= $$(GTK_CCOMFLAGS)| ; \
		 /--libs gtk+-2.0/s|=.*|= $$(GTK_LIBS)| ; \
		 /X11R6/s|^|#|' ${WRKSRC}/src/osd/sdl/sdl.mak
	@${REINPLACE_CMD} -e \
		's|int getc()|int getcf()|g' ${WRKSRC}/src/emu/fileio.h
	@${REINPLACE_CMD} -e \
		's|::getc()|::getcf()|g' ${WRKSRC}/src/emu/fileio.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/libexec/${PORTNAME}
.for FILE in chdman jedutil ldresample ldverify romcmp testkeys unidasm
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/libexec/${PORTNAME}
.endfor
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} artwork ${DATADIR})
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} hash ${DATADIR})
	@(cd ${WRKSRC}/src/osd/sdl && ${COPYTREE_SHARE} keymaps ${DATADIR})
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/mame.ini ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
