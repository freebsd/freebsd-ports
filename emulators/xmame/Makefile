# New ports collection makefile for:    xmame
# Date created:         4 Sep 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	xmame
PORTVERSION?=	0.37b13.2
CATEGORIES=	emulators
MASTER_SITES=	http://x.mame.net/download/ \
		ftp://ftp.kaupp.cx/pub/xmame/ \
		http://www.ozemail.com.au/~knebauer/xmame/files/ \
		http://www.mame.net/zips/ \
		http://cheat.retrogames.com/ \
		http://www.sys2064.com/files/mame/
DISTNAME=	xmame-${XMAMEVERSION:S/p/pre/}
DIST_SUBDIR=	xmame
XMAMEVERSION?=	${PORTVERSION}
USE_BZIP2=	yes

MAINTAINER?=	stijn@win.tue.nl

USE_XPM=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes

MAN6=		x${MAMEMESS}.6

# Are we building MAME, MESS or PinMAME? (also set by slave ports)
MAMEMESS?=	mame

PLIST_SUB+=	MAMEMESS="x${MAMEMESS}" SPOOLGAMES="${SPOOLGAMES}"
.if ${MAMEMESS} == "mame"
PLIST_SUB+=	MAMEONLY="" MESSONLY="@comment " PINMAMEONLY="@comment "
.else
.if ${MAMEMESS} == "mess"
PLIST_SUB+=	MAMEONLY="@comment " MESSONLY="" PINMAMEONLY="@comment "
.else
.if ${MAMEMESS} == "pinmame"
PLIST_SUB+=	MAMEONLY="@comment " MESSONLY="@comment " PINMAMEONLY=""
.else
.error MAMEMESS must be set to one of "mame", "mess" or "pinmame".
.endif
.endif
.endif

# Where do we want game spool data?
SPOOLGAMES?=	/var/games

# Docs list
GENERALDOCS=	changes.unix \
		liesmich.unix \
		credits.txt \
		multiplayer-readme.txt \
		xmame-doc-1.html \
		xmame-doc-2.html \
		xmame-doc-3.html \
		xmame-doc-4.html \
		xmame-doc-5.html \
		xmame-doc-6.html \
		xmame-doc-7.html \
		xmame-doc.html \
		xmame-doc.lyx \
		xmame-doc.ps \
		xmame-doc.sgml \
		xmame-doc.txt
XMAMEDOCS=	changes.mame \
		gamelist.mame \
		readme.mame
XMESSDOCS=	changes.mess \
		gamelist.mess \
		readme.mess \
		messold.txt \
		messroms.txt
PINMAMEDOCS=	pinmame/simulation.txt \
		pinmame/whatsnew.txt \
		pinmame/pinmame.txt \
		pinmame/gamelist.txt \
		pinmame/keys.txt \
		pinmame/sounds.dat
GLDOCS=		changes.opengl
.if ${MAMEMESS} == "mame"
ALLDOCS=	${GENERALDOCS} ${XMAMEDOCS}
.else
.if ${MAMEMESS} == "mess"
ALLDOCS=	${GENERALDOCS} ${XMESSDOCS}
.else
ALLDOCS=	${GENERALDOCS} ${PINMAMEDOCS}
.endif
.endif

# CPS-2 patches - this enables extra games in MAME.
.if ${MAMEMESS} == "mame"
.if defined(WITH_CPS2) && ${WITH_CPS2} == "yes"
CPS2VERSION=	20010415

PATCH_SITES+=	http://www.win.tue.nl/~stijn/xmame/
PATCHFILES+=	${DISTNAME}-cps2-${CPS2VERSION}.patch.gz
.else
pre-everything::
	@${ECHO_MSG} "===> If you want to compile MAME with CPS-2 support, use \"make WITH_CPS2=yes\""
.endif
.endif

# Datfiles - for history/bugs/cheats/highscores in MAME
.if ${MAMEMESS} == "mame"
.if defined(WITH_DATFILES) && ${WITH_DATFILES} == "yes"
PLIST_SUB+=	DATFILES=""

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

HIVER=		7

DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} \
			hsdat${HIVER}.zip history.zip cheat.zip
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

post-extract:
	cd ${WRKDIR} && \
		unzip -q ${DISTDIR}/${DIST_SUBDIR}/hsdat${HIVER}.zip hiscore.dat
	cd ${WRKDIR} && \
		unzip -q ${DISTDIR}/${DIST_SUBDIR}/history.zip history.dat
	cd ${WRKDIR} && \
		unzip -q ${DISTDIR}/${DIST_SUBDIR}/cheat.zip cheat.dat
.else
PLIST_SUB+=	DATFILES="@comment "
pre-everything::
	@${ECHO_MSG} "===> If you want to install additional information with MAME (such as game"
	@${ECHO_MSG} "     history, cheats, and highscores) use \"make WITH_DATFILES=yes\""
.endif
.endif

# ASM 68k cores - disabled by default, because they break things (pbobble2
# being a prime example). These also only work on i386. Should be enabled
# by default when ready for prime time.
.if defined(WITH_ASM68K) && ${WITH_ASM68K} == "yes"
ASM_COMMENT=
.else
ASM_COMMENT=\#
.endif

# Heavy optimization - enabled by default because it doesn't seem
# to break things, and enables considerable speedup.
.if !defined(WITH_OPTIMIZATION) || ${WITH_OPTIMIZATION} != "no"
CFLAGS+=	-O3 -Wall -Wno-unused -funroll-loops \
		-fstrength-reduce -fomit-frame-pointer -ffast-math \
		-malign-functions=4 -malign-jumps=4 -malign-loops=4
.endif

# Choose one of several display targets:
#  WITH_GL	OpenGL based, displays vector games with hardware
#		acceleration
#  WITH_SDL	Uses the SDL library to be able to play fullscreen
#		without root rights
#  WITH_X11	The standard display target, should work without
#		dependancies other than X
#
# WITH_SDL is enabled by default because x{mame,mess} can run full
# screen without having to be setuid root.
.if defined(WITH_GL) && ${WITH_GL} == "yes"
CFLAGS+=	${PTHREAD_CFLAGS}
USE_MESA=	yes
DISPLAY_METHOD=	xgl
PLIST_SUB+=	OPENGL=""
ALL_DOCS+=	${GLDOCS}
.else
PLIST_SUB+=	OPENGL="@comment "
.if !defined(WITH_SDL) || ${WITH_SDL} != "no"
LIB_DEPENDS=    SDL-1.1.3:${PORTSDIR}/devel/sdl12
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
MAKE_ENV+=	SDL_CONFIG=${SDL_CONFIG}
DISPLAY_METHOD=	SDL
.if !defined(WITH_SDL)
pre-everything::
	@${ECHO_MSG} "===> If you don't want ${MAMEMESS:U} to be built with SDL support,"
	@${ECHO_MSG} "     use \"make WITH_SDL=no\""
	@${ECHO_MSG} "===> If you want to build ${MAMEMESS:U} with OpenGL support for vector games,"
	@${ECHO_MSG} "     use \"make WITH_GL=yes\""
.endif
.else
DISPLAY_METHOD=	x11
.endif
.endif

# Some simple patches that don't warrant a separate patch
post-patch:
	${PERL} -pi -e 's@SDL/@SDL11/@' ${WRKSRC}/src/unix/video-drivers/SDL.c
	${PERL} -pi -e 's@png.h@../../png.h@' \
				${WRKSRC}/src/unix/video-drivers/glexport.c
	${PERL} -pi -e 's@malloc.h@stdlib.h@' \
				${WRKSRC}/src/unix/video-drivers/gljpg.c

# The large number of sed regexes here is intended to make this port a whole
# lot easier to maintain - please don't convert them into a patch.
do-configure:
	${SED} -e "s@= gcc@?=  ${CC}@g" \
		-e "s@= -O2 -Wall@?=  ${CFLAGS}@g" \
		-e "s@= cp@?=  ${INSTALL} ${COPY}@g" \
		-e "s@lib/x\$$(TARGET)@share/x\$$(TARGET)@g" \
		-e "s@/usr/X11R6@${X11BASE}@g" \
		-e "s@-g bin@-g wheel@g" \
		-e "s@ARCH  = linux@ARCH  = freebsd@g" \
		-e "s@# X11_DGA@X11_DGA@g" \
		-e "s@# JOY_USB@JOY_USB@g" \
		-e "s@= x11@= ${DISPLAY_METHOD}@g" \
		-e "s@= mame@= ${MAMEMESS}@g" \
		-e "s@# X86_ASM@${ASM_COMMENT}X86_ASM@g" \
		-e "s@GLLIBS=.-ldl@GLLIBS= ${PTHREAD_LIBS}@g" \
			${WRKSRC}/makefile.unix > ${WRKSRC}/Makefile

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} SDL_VIDEODRIVER=aalib \
		${GMAKE} doc/x${MAMEMESS}.6
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} SDL_VIDEODRIVER=aalib \
		${GMAKE} doc/x${MAMEMESS}rc.dist
	@${CP} ${WRKSRC}/doc/x${MAMEMESS}rc.dist \
		${WRKSRC}/doc/x${MAMEMESS}rc.dist.sed
	${SED} -e "s@^spooldir.*\$$@spooldir		${SPOOLGAMES}/x${MAMEMESS}@" \
		-e "s@^rompath.*\$$@rompath			${PREFIX}/share/x${MAMEMESS}/roms@" \
		${WRKSRC}/doc/x${MAMEMESS}rc.dist.sed > ${WRKSRC}/doc/x${MAMEMESS}rc.dist

post-install:
	${MV} ${PREFIX}/bin/x${MAMEMESS}.${DISPLAY_METHOD} \
		${PREFIX}/bin/x${MAMEMESS}
	${CHOWN} root:games ${PREFIX}/bin/x${MAMEMESS}
	${CHMOD} u-s,g+s ${PREFIX}/bin/x${MAMEMESS}
	${MKDIR} ${PREFIX}/share/x${MAMEMESS} ${PREFIX}/share/x${MAMEMESS}/roms
	${MKDIR} ${SPOOLGAMES}/x${MAMEMESS}
	${CHOWN} -R root:games ${SPOOLGAMES}/x${MAMEMESS}
	${CHMOD} 775 ${SPOOLGAMES}/x${MAMEMESS}
	${INSTALL_DATA} ${WRKSRC}/doc/x${MAMEMESS}rc.dist \
				${PREFIX}/etc/x${MAMEMESS}rc.sample
	${LN} -sf ${PREFIX}/etc/x${MAMEMESS}rc \
				${PREFIX}/share/x${MAMEMESS}/x${MAMEMESS}rc
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/x${MAMEMESS}
.for file in ${ALLDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/x${MAMEMESS}
.endfor
.if ${MAMEMESS} == "mess"
	${MKDIR} ${PREFIX}/share/doc/x${MAMEMESS}/sysinfo
	${INSTALL_DATA} ${WRKSRC}/doc/sysinfo/* \
		${PREFIX}/share/doc/x${MAMEMESS}/sysinfo
.endif
.endif
.if ${MAMEMESS} == "mame" && defined(WITH_DATFILES) && ${WITH_DATFILES} == "yes"
	${INSTALL_DATA} ${WRKDIR}/hiscore.dat ${PREFIX}/share/xmame
	${INSTALL_DATA} ${WRKDIR}/history.dat ${PREFIX}/share/xmame
	${INSTALL_DATA} ${WRKDIR}/cheat.dat ${PREFIX}/share/xmame
.endif

.include <bsd.port.mk>
