# New ports collection makefile for:    xmame
# Date created:         4 Sep 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	xmame
PORTVERSION?=	0.56.2
CATEGORIES=	emulators
MASTER_SITES=	http://x.mame.net/download/ \
		http://www.mame.net/zips/ \
		http://cheat.retrogames.com/ \
		http://www.sys2064.com/files/mame/
DISTNAME=	xmame-${XMAMEVERSION:S/p/pre/}
DIST_SUBDIR=	xmame

MAINTAINER?=	stijn@win.tue.nl

USE_BZIP2=	yes
USE_GMAKE=	yes

MAN6=		x${MAMEMESS}.6

XMAMEVERSION?=	${PORTVERSION}

.if !defined(WITH_SVGALIB) || ${WITH_SVGALIB} != "yes"
USE_XPM=	yes
USE_X_PREFIX=	yes
.endif

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
		multiplayer-readme.txt \
		xmame-doc-1.html \
		xmame-doc-2.html \
		xmame-doc-3.html \
		xmame-doc-4.html \
		xmame-doc-5.html \
		xmame-doc-6.html \
		xmame-doc-7.html \
		xmame-doc-8.html \
		xmame-doc.html \
		xmame-gdoc-1.html \
		xmame-gdoc-2.html \
		xmame-gdoc-3.html \
		xmame-gdoc-4.html \
		xmame-gdoc-5.html \
		xmame-gdoc-6.html \
		xmame-gdoc-7.html \
		xmame-gdoc-8.html \
		xmame-gdoc.html \
		xmame.css \
		xmame-doc.lyx \
		xmame-doc.txt \
		dga2.txt
XMAMEDOCS=	changes.mame \
		gamelist.mame \
		readme.mame
XMESSDOCS=	changes.mess \
		credits.mess \
		gamelist.mess \
		readme.mess \
		messroms.txt \
		imgtool.txt \
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
.if !defined(WITH_DATFILES)
pre-everything::
	@${ECHO_MSG} "===> If you want to install additional information with MAME (such as game"
	@${ECHO_MSG} "     history, cheats, and highscores) use \"make WITH_DATFILES=yes\""
.endif
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

# Heavy optimization - disabled by default because it breaks things. It's
# still available because it enables considerable speedup.
.if defined(WITH_OPTIMIZATION) && ${WITH_OPTIMIZATION} == "yes"
CFLAGS+=	-O3 -Wall -Wno-unused -funroll-loops \
		-fstrength-reduce -fomit-frame-pointer -ffast-math \
		-malign-functions=4 -malign-jumps=4 -malign-loops=4
.else
.if !defined(WITH_OPTIMIZATION)
pre-everything::
	@${ECHO_MSG} "===> If you want to enable high optimization levels, use "
	@${ECHO_MSG} "     \"make WITH_OPTIMIZATION=yes\". Be warned that this is known to"
	@${ECHO_MSG} "     break some games though."
.endif
.endif

# Choose one of several display targets:
#  WITH_GL	OpenGL based, displays vector games with hardware
#		acceleration
#  WITH_SDL	Uses the SDL library to be able to play fullscreen
#		without root rights
#  WITH_SVGALIB	Uses the svgalib library to allow playing without X. This
#		has not been extensively tested; patches welcome to make
#		this actually work.
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
.if defined(WITH_SVGALIB) && ${WITH_SVGALIB} == "yes"
LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	LOCALBASE=${LOCALBASE}
DISPLAY_METHOD=	svgalib
.else
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
.endif
PKGNAMESUFFIX=-${DISPLAY_METHOD:L}

# USB joysticks - only enabled on -STABLE because of conflicting USB
# prototypes in -STABLE & -CURRENT.
.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
JOYUSBCOMMENT=\#\ 
.else
JOYUSBCOMMENT=
.endif

# Esound audio - handy for a GNOME environment
.if defined(WITH_ESOUND) && ${WITH_ESOUND} == "yes"
ESOUNDCOMMENT=
USE_ESOUND=	yes
.else
ESOUNDCOMMENT=\#\ 
.if !defined(WITH_ESOUND)
pre-everything::
	@echo "===> If you want to build ${MAMEMESS:U} with support for ESound,"
	@echo "     use \"make WITH_ESOUND=yes\""
.endif
.endif

# Some simple patches that don't warrant a separate patch
post-patch:
	${PERL} -pi -e 's@SDL/@SDL11/@' ${WRKSRC}/src/unix/video-drivers/SDL.c
	${PERL} -pi -e 's@png.h@../../png.h@' \
				${WRKSRC}/src/unix/video-drivers/glexport.c
	${PERL} -pi -e 's@malloc.h@stdlib.h@' \
				${WRKSRC}/src/unix/video-drivers/gljpg.c
	${PERL} -pi -e 's@asm/io.h@machine/cpufunc.h@' \
				${WRKSRC}/src/unix/video-drivers/twkuser.c

# The large number of sed regexes here is intended to make this port a whole
# lot easier to maintain - please don't convert them into a patch.
do-configure:
	${SED} -e "s@= gcc@?=  ${CC}@g" \
		-e "s@^CFLAGS.*@CFLAGS ?= ${CFLAGS}@g" \
		-e "s@= cp@?=  ${INSTALL} ${COPY}@g" \
		-e "s@lib/x\$$(TARGET)@share/x\$$(TARGET)@g" \
		-e "s@/usr/X11R6@${X11BASE}@g" \
		-e "s@-g bin@-g wheel@g" \
		-e "s@ARCH  = linux@ARCH  = freebsd@g" \
		-e "s@# X11_DGA@X11_DGA@g" \
		-e "s@# JOY_USB@${JOYUSBCOMMENT}JOY_USB@g" \
		-e "s@= x11@= ${DISPLAY_METHOD}@g" \
		-e "s@= mame@= ${MAMEMESS}@g" \
		-e "s@# X86_ASM@${ASM_COMMENT}X86_ASM@g" \
		-e "s@# SOUND_ESOUND@${ESOUNDCOMMENT}SOUND_ESOUND@g" \
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
.endif
.if ${MAMEMESS} == "mess"
	${INSTALL_DATA} ${WRKSRC}/doc/sysinfo.dat \
				${PREFIX}/share/xmess/history.dat
.endif
.if ${MAMEMESS} == "mame" && defined(WITH_DATFILES) && ${WITH_DATFILES} == "yes"
	${INSTALL_DATA} ${WRKDIR}/hiscore.dat ${PREFIX}/share/xmame
	${INSTALL_DATA} ${WRKDIR}/history.dat ${PREFIX}/share/xmame
	${INSTALL_DATA} ${WRKDIR}/cheat.dat ${PREFIX}/share/xmame
.endif

.include <bsd.port.post.mk>
