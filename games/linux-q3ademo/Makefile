# New ports collection makefile for:	linux-q3ademo
# Date created:				11 December 2000
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# - inspired by linux realplayer 7 port
# - special thanks to the Emacs key board macro
#
# $FreeBSD$
#

PORTNAME=	linux-q3ademo
PORTVERSION=	1.11.6
PORTREVISION=	1
CATEGORIES=	games graphics linux
# fetch manually
MASTER_SITES=
DISTNAME=	linuxq3ademo-1.11-6.x86.gz.sh
# dont uncompress
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux 3d shooter from id Software / Loki Software (demo version)

RUN_DEPENDS=	/compat/linux/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-3
RUN_DEPENDS +=	/compat/linux/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri
.else
RUN_DEPENDS +=	/compat/linux/lib/libGL.so:${PORTSDIR}/graphics/linux_glx
.endif

USE_X_PREFIX=	yes
USE_MESA=	yes

# Linux binary should not be stripped by INSTALL_PROGRAM as it uses /usr/bin/strip which then brands the binary as a FreeBSD ELF one.
STRIP=

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		may not be automatically fetched due to licensing\
		restrictions.  You MUST manually fetch the Linux version from:\
		http://quake3.lokigames.com \
		- once ${DISTFILES} has been downloaded, move it to\
		${DISTDIR} and then restart this build.
.endif

ONLY_FOR_ARCHS=	i386
NO_CDROM=	"Redistribution not allowed"
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/q3ademo
Q3ADIR=		${PREFIX}/share/q3ademo

pre-extract:
	@${MKDIR} ${WRKDIR}
	@${MKDIR} ${WRKSRC}

do-extract:
	@${SH} ${FILESDIR}/peel ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}

do-configure:
	@${ECHO_CMD} "#!/bin/sh" > ${WRKSRC}/q3demo
	@${ECHO_CMD} "cd "${Q3ADIR} >> ${WRKSRC}/q3demo
	@${ECHO_CMD} "quake=\"./q3demo\"" >> ${WRKSRC}/q3demo
	@${ECHO_CMD} "\""$$"quake\" "$$"*" >> ${WRKSRC}/q3demo
	@${ECHO_CMD} "exit "$$"?" >> ${WRKSRC}/q3demo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/q3demo ${PREFIX}/bin
	@${MKDIR} ${Q3ADIR}
	${INSTALL_DATA} ${WRKSRC}/README ${Q3ADIR}
	${INSTALL_DATA} ${WRKSRC}/icon.bmp ${Q3ADIR}
	${INSTALL_DATA} ${WRKSRC}/icon.xpm ${Q3ADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/x86/glibc-2.0/q3ded ${Q3ADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/x86/glibc-2.0/q3demo ${Q3ADIR}
	@${MKDIR} ${Q3ADIR}/demoq3
	${INSTALL_DATA} ${WRKSRC}/demoq3/pak0.pk3 ${Q3ADIR}/demoq3

.if !defined(NOPORTDOCS)
	@${MKDIR} ${Q3ADIR}/Help
	${INSTALL_DATA} ${WRKSRC}/Help/BotCommands.html ${Q3ADIR}/Help
	${INSTALL_DATA} ${WRKSRC}/Help/DedicatedServer.html ${Q3ADIR}/Help
	${INSTALL_DATA} ${WRKSRC}/Help/Index.html ${Q3ADIR}/Help
	${INSTALL_DATA} ${WRKSRC}/Help/Q3A_EULA.html ${Q3ADIR}/Help
	${INSTALL_DATA} ${WRKSRC}/Help/Q3A_EULA.txt ${Q3ADIR}/Help
	${INSTALL_DATA} ${WRKSRC}/Help/Quake3World.html ${Q3ADIR}/Help
	${INSTALL_DATA} ${WRKSRC}/Help/Readme.html ${Q3ADIR}/Help
	@${MKDIR} ${Q3ADIR}/Help/DocsArt
	${INSTALL_DATA} ${WRKSRC}/Help/DocsArt/Header.jpg ${Q3ADIR}/Help/DocsArt
	${INSTALL_DATA} ${WRKSRC}/Help/DocsArt/fast1.jpg ${Q3ADIR}/Help/DocsArt
	${INSTALL_DATA} ${WRKSRC}/Help/DocsArt/fast2.jpg ${Q3ADIR}/Help/DocsArt
	@${MKDIR} ${Q3ADIR}/Help/Manual
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/index.html ${Q3ADIR}/Help/Manual
	@${MKDIR} ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/arena.html ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/arenaa.html ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/arenae.html ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/arenaf.html ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/arenag.html ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/arenah.html ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/arenam.html ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/arenaw.html ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/credits.html ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/customer.html ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/default.html ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/escmenu.html ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/installation.html ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/main.html ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/mainm.html ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/mains.html ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/navigate.html ${Q3ADIR}/Help/Manual/htmlpages
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/htmlpages/overview.html ${Q3ADIR}/Help/Manual/htmlpages
	@${MKDIR} ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/cornerlogo.jpg ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/cover.jpg ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/nav_01_dn.gif ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/nav_01_up.gif ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/nav_02_dn.gif ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/nav_02_up.gif ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/nav_03_dn.gif ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/nav_03_up.gif ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/nav_04_dn.gif ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/nav_04_up.gif ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/nav_05_dn.gif ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/nav_05_up.gif ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/nav_06_dn.gif ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/nav_06_up.gif ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/nav_07_dn.gif ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/nav_07_up.gif ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/nav_08_dn.gif ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/nav_08_up.gif ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/sidebar.jpg ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/sidebarb.jpg ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/sidebarg.jpg ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/space.jpg ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subcatline.jpg ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtfrag.jpg ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/titlearena.jpg ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/titlecred.jpg ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/titlecust.jpg ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/titledef.jpg ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/titleesc.jpg ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/titleinstall.jpg ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/titleline.jpg ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/titlemain.jpg ${Q3ADIR}/Help/Manual/navart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/titleover.jpg ${Q3ADIR}/Help/Manual/navart
	@${MKDIR} ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Anarki.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Angel.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Biker.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Bitterman.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Bones.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Cadavre.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Crash.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Daemia.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Doom.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Gorre.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Grunt.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Hossman.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Hunter.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Keel.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Klesk.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Lucy.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Major.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Mynx.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Orbb.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Patriot.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Phobos.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Ranger.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Razor.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Sarge.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Slash.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Sorlag.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Stripe.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Tankjr.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Uriel.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Visor.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Wrack.jpg ${Q3ADIR}/Help/Manual/navart/charart
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/charart/Xaero.jpg ${Q3ADIR}/Help/Manual/navart/charart
	@${MKDIR} ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/acceler_l.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/acceler_r.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/bounce_l.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/bounce_r.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/captureflag.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/controls.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/create.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/doors_l.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/doors_r.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/escmenu.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/fog_l.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/fog_r.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/fogdeath.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/freeforall.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/gameoptions.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/gates.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/graphics.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/lava_l.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/lava_r.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/lift.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/multiplayer.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/pendulum.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/platform.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/playerset.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/setup.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/singleplayer.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/skirmish.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/slime.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/teamdeath.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/teleport.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/tourney.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/trigger.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/voids.jpg ${Q3ADIR}/Help/Manual/navart/screens
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/screens/water.jpg ${Q3ADIR}/Help/Manual/navart/screens
	@${MKDIR} ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subarena.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subarmor.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subcarri.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subchoose.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subcontr.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subcontrol.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subcopy.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subdemo.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subenviro.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subflags.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subgame.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subgamg.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subglad.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subgraph.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subheal.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subhost.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subinaust.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subinter.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subintheus.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subitems.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subjoin.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subleave.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/sublook.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/sublook02.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/submedal.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/submisc.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/submisc02.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/submove.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/submove02.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/submulti.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subnews.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subplayer.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subplayer02.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subpower.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subquit.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subquit02.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subreset.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subserve.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subsetup.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subshoot.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subshoot02.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subsing.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subsyst.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subteam.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subtstruct.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/subtitles/subweap.jpg ${Q3ADIR}/Help/Manual/navart/subtitles
	@${MKDIR} ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/BFG-10K.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/Railg.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/armorcombat.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/armorheavy.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/armorshard.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/battles.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/bfg-10ka.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/bfg-10kh.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/blue.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/flight.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/gauntlet.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/grenadea.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/grenadeh.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/grenadel.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/haste.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/healthgld.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/healthgrn.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/healthyelo.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/invisib.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/lightinga.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/lightingg.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/lightningh.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/machinea.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/machineg.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/machineh.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/medacc.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/medexce.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/medfrag.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/medgua.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/medimpr.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/medkit.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/medperf.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/megaheal.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/plasmaa.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/plasmag.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/plasmah.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/quaddam.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/raila.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/railh.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/red.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/regen.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/rocketa.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/rocketh.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/rocketl.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/shotg.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/shotguna.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/shotgunh.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	${INSTALL_DATA} ${WRKSRC}/Help/Manual/navart/weapons/teleport.jpg ${Q3ADIR}/Help/Manual/navart/weapons
	@${MKDIR} ${Q3ADIR}/Help/Support
	${INSTALL_DATA} ${WRKSRC}/Help/Support/Index.html ${Q3ADIR}/Help/Support
	@${MKDIR} ${Q3ADIR}/Help/Support/CustomerSupport
	${INSTALL_DATA} ${WRKSRC}/Help/Support/CustomerSupport/Customer_Support.htm ${Q3ADIR}/Help/Support/CustomerSupport
	@${MKDIR} ${Q3ADIR}/Help/Support/Information
	${INSTALL_DATA} ${WRKSRC}/Help/Support/Information/Improving_Performance.htm ${Q3ADIR}/Help/Support/Information
	${INSTALL_DATA} ${WRKSRC}/Help/Support/Information/Minimum_System_Requirements.htm ${Q3ADIR}/Help/Support/Information
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
