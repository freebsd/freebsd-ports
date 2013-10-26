# Created by: alepulver
# $FreeBSD$

PORTNAME=	mess
PORTVERSION=	0.149${PATCHSUFFIX}
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/mame.mirror/MAME%20${PORTVERSION} \
		http://mame.mirrors.zippykid.com/releases/ \
		http://emumovies.com/aarongiles/releases/ \
		http://mamedev.org/updates/:patchsets
DISTNAME=	mame${PORTVERSION:S/.//:C/p[0-9]*$//}s
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${UPDATE_PATCHES:C/$/.zip:patchsets/}
DIST_SUBDIR=	mame

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiple Emulator Super System

LIB_DEPENDS=	FLAC:${PORTSDIR}/audio/flac \
		jpeg:${PORTSDIR}/graphics/jpeg \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	liberation-fonts-ttf>=0:${PORTSDIR}/x11-fonts/liberation-fonts-ttf

OPTIONS_DEFINE=	DEBUG DOCS EXAMPLES
OPTIONS_RADIO=	BUILTIN_DEBUGGER
OPTIONS_RADIO_BUILTIN_DEBUGGER=	GTK2 QT4
BUILTIN_DEBUGGER_DESC=	Builtin debugger support

NO_WRKSUBDIR=	yes

USE_ZIP=	yes
USES=		pkgconfig shebangfix
SHEBANG_FILES=	src/emu/cpu/m6502/m6502make.py \
		src/emu/cpu/m6809/m6809make.py \
		src/emu/cpu/mcs96/mcs96make.py \
		src/emu/cpu/tms57002/tmsmake.py
USE_DOS2UNIX=	${SHEBANG_FILES}
USE_XORG=	xext xi xinerama xrender
USE_GL=		gl
USE_SDL=	sdl ttf
USE_PYTHON_BUILD=yes
USE_GMAKE=	yes
MAKE_ENV=	NOWERROR=1 OPTIMIZE=0 USE_NETWORK=1 \
		OPT_FLAGS="${CXXFLAGS}" GCC_LDFLAGS="${LDFLAGS}" \
		TARGET="${PORTNAME}"
MAKEFILE=	makefile

SUB_FILES=	pkg-message

PATCHLEVEL=	# none

.if defined(PATCHLEVEL) && ${PATCHLEVEL}
PATCHSUFFIX=	p${PATCHLEVEL}
UPDATE_PATCHES!=	/usr/bin/jot -s " " \
		-w ${PORTVERSION:S/.//:C/\.p[0-9]*$//}u%d_diff \
		${PATCHLEVEL} 1 ${PATCHLEVEL}
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ENV+=	DEBUG=1
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20 gconf2
MAKE_ENV+=	GTK_INCPATH="$$(pkg-config --cflags-only-I gtk+-2.0 gconf-2.0)" \
		GTK_CCOMFLAGS="$$(pkg-config --cflags-only-other gtk+-2.0 gconf-2.0)" \
		GTK_LIBS="$$(pkg-config --libs gtk+-2.0 gconf-2.0)"
.else
MAKE_ENV+=	GTK_INCPATH="" \
		GTK_CCOMFLAGS="" \
		GTK_LIBS=""
.endif

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	gui moc_build qmake_build
.else
MAKE_ENV+=	NO_USE_QTDEBUG=1
.endif

.if empty(PORT_OPTIONS:MGTK2) && empty(PORT_OPTIONS:MQT4)
MAKE_ENV+=	NO_DEBUGGER=1
.endif

.include <bsd.port.pre.mk>

.if exists(/usr/bin/clang) && ${OSVERSION} >= 900014
CC=		/usr/bin/clang
CPP=		/usr/bin/clang-cpp
CXX=		/usr/bin/clang++
.else
USE_GCC=	yes
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not install on ia64, powerpc, or sparc64
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
		 s|^BUILD_FLAC|# BUILD_FLAC| ; \
		 s|^BUILD_JPEGLIB|# BUILD_JPEGLIB| ; \
		 s| = @gcc| := $$(CC)| ; \
		 s| = @g++| := $$(CXX)| ; \
		 s|^FULLNAME =.*|FULLNAME = $$(NAME)| ; \
		 /--warn-common/s|= -Wl,|= $$(GCC_LDFLAGS) -Wl,| ; \
		 /LDFLAGS/s|-s|| ; \
		 /LIBS/s|-lstdc++|| ; \
		 /LIBS/s|-lpthread|-pthread|' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e \
		'/LIBS/s|-lpthread|-pthread| ; \
		 /-system/s|/usr/local/|${LOCALBASE}/| ; \
		 /--cflags-only-I gtk+-2.0/s|=.*|= $$(GTK_INCPATH)| ; \
		 /--cflags-only-other gtk+-2.0/s|=.*|= $$(GTK_CCOMFLAGS)| ; \
		 /--libs gtk+-2.0/s|=.*|= $$(GTK_LIBS)| ; \
		 /X11R6/s|^|#|' ${WRKSRC}/src/osd/sdl/sdl.mak

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/libexec/${PORTNAME}
.for F in castool chdman imgtool jedutil ldresample ldverify romcmp \
	testkeys unidasm
	${INSTALL_PROGRAM} ${WRKSRC}/${F} ${PREFIX}/libexec/${PORTNAME}
.endfor
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} artwork ${DATADIR})
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} hash ${DATADIR})
	@(cd ${WRKSRC}/src/osd/sdl && ${COPYTREE_SHARE} keymaps ${DATADIR})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/mess.ini ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
