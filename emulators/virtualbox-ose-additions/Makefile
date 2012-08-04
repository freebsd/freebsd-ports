# New ports collection makefile for:	virtualbox-ose-additions
# Date created:		2009-09-21
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	virtualbox-ose
DISTVERSION=	4.1.18
PORTREVISION=	1
CATEGORIES=	emulators kld
MASTER_SITES=	http://tmp.chruetertee.ch/ \
		http://freebsd.unixfreunde.de/sources/ \
		SF/virtualbox.mirror/ \
		http://disasterarea.chruetertee.ch/
PKGNAMESUFFIX=	-additions
DISTNAME=	VirtualBox-${DISTVERSION}

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	VirtualBox additions for FreeBSD guests

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		as86:${PORTSDIR}/devel/dev86 \
		kmk:${PORTSDIR}/devel/kBuild-devel

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}
WRKSRC=		${WRKDIR}/VirtualBox-${PORTVERSION}
USE_RC_SUBR=	vboxguest vboxservice
ONLY_FOR_ARCHS=	i386 amd64
USE_BZIP2=	yes
MAKE_JOBS_UNSAFE=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gcc="${CC}" --with-g++="${CXX}" --nofatal \
		--disable-xpcom --disable-sdl-ttf --disable-pulse \
		--disable-alsa --disable-dbus --disable-python \
		--build-headless

CONFLICTS=	bcc-[0-9]*
CONFLICTS_BUILD=	kBuild-[0-9]*
CONFLICTS_INSTALL=	virtualbox-ose-additions-devel-[3,4]* virtualbox-ose-[3,4]* virtualbox-ose-devel-[3,4]* virtualbox-ose-legacy-[3,4]*

OPTIONS_DEFINE=	DEBUG X11 OPENGL
OPTIONS_DEFAULT=	X11

.include <bsd.port.options.mk>

PLIST_SUB+=	KMODDIR=${KMODDIR:C,^/,,}

KMODDIR=	/boot/modules
SRC_BASE?=	/usr/src
VIDEODIR=	${PREFIX}/lib/xorg/modules/drivers
INPUTDIR=	${PREFIX}/lib/xorg/modules/input

VBOX_BIN=	${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/additions

KMK_BUILDTYPE=	release
KMK_CONFIG=	VBOX_LIBPATH_X11=${LOCALBASE}
KMK_FLAGS=

.if ${PORT_OPTIONS:MDEBUG}
KMK_FLAGS+=	BUILD_TYPE=debug
KMK_BUILDTYPE=	debug
.endif

.if ${PORT_OPTIONS:MX11}
VBOX_WITH_X11=	1
USE_XORG=	xcursor xmu inputproto xorg-server xrandr
PLIST_SUB+=	X11=""
.else
VBOX_WITH_X11=
PLIST_SUB+=	X11="@comment "
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=		gl
.else
CONFIGURE_ARGS+=--disable-opengl
.endif

.if ${ARCH} == i386
KMK_ARCH=	freebsd.x86
.else
KMK_ARCH=	freebsd.${ARCH}
.endif

XSERVER_ABI:=	${XSERVER_VER:S/.//:R}

.if !exists(${SRC_BASE}/sys/kern/bus_if.m)
IGNORE=		requires kernel sources
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900012
EXTRA_PATCHES=	${FILESDIR}/extrapatch-include-iprt-string.h
.endif

pre-everything::
.if ${ARCH} == "amd64"
.if !exists(/usr/lib32/libc.so)
	@${ECHO} 'Requires 32-bit libraries installed under /usr/lib32.'
	@${ECHO} 'Do: cd /usr/src; make build32 install32; ldconfig -v -m -R /usr/lib32'
	@${FALSE}
.endif
.endif

post-patch:
	@${ECHO} 'VBOX_ONLY_ADDITIONS = 1' > ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_X11_ADDITIONS = ${VBOX_WITH_X11}' >> ${WRKSRC}/LocalConfig.kmk
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Config.kmk \
		${WRKSRC}/configure \
		${WRKSRC}/kBuild/units/qt4.kmk \
		${WRKSRC}/kBuild/sdks/LIBSDL.kmk \
		${WRKSRC}/src/VBox/Additions/x11/Installer/98vboxadd-xclient \
		${WRKSRC}/src/VBox/Additions/x11/Installer/vboxclient.desktop
	@${REINPLACE_CMD} -e 's|\$$KBUILDDIR_BIN/kmk_sed|${LOCALBASE}/bin/kmk_sed|g' ${WRKSRC}/configure

pre-build:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/env.sh \
		${WRKSRC}/src/VBox/Additions/freebsd/Installer/vboxguest.sh

do-build:
	cd ${WRKSRC} && ${SH} env.sh && ${KMK_CONFIG} ${LOCALBASE}/bin/kmk ${KMK_FLAGS}
	cd ${VBOX_BIN}/src && make SYSDIR=${SRC_BASE}/sys

do-install:
	${MKDIR} ${KMODDIR}
	${INSTALL_KLD} ${VBOX_BIN}/src/vboxguest/vboxguest.ko ${KMODDIR}
	@/usr/sbin/kldxref ${KMODDIR}

	${MKDIR} ${PREFIX}/etc/rc.d/

	${MKDIR} ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${VBOX_BIN}/VBoxControl ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${VBOX_BIN}/VBoxService ${PREFIX}/sbin/

.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${VBOX_BIN}/VBoxClient ${PREFIX}/bin/

	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/VBox/Additions/x11/Installer/98vboxadd-xclient \
		${PREFIX}/bin/VBoxClient-all

	# X11 autostart
	${MKDIR} ${PREFIX}/etc/xdg/autostart/
	${INSTALL_DATA} ${WRKSRC}/src/VBox/Additions/x11/Installer/vboxclient.desktop \
		${PREFIX}/etc/xdg/autostart/

	# KDE autostart
	${MKDIR} ${PREFIX}/share/autostart/
	${INSTALL_DATA} ${WRKSRC}/src/VBox/Additions/x11/Installer/vboxclient.desktop \
		${PREFIX}/share/autostart/

	${MKDIR} ${VIDEODIR}
	${INSTALL_DATA} ${VBOX_BIN}/vboxvideo_drv_${XSERVER_ABI}.so ${VIDEODIR}/vboxvideo_drv.so

	${MKDIR} ${INPUTDIR}
	${INSTALL_DATA} ${VBOX_BIN}/vboxmouse_drv_${XSERVER_ABI}.so ${INPUTDIR}/vboxmouse_drv.so
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
