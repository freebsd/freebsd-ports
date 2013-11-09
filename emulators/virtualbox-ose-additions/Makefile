# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	virtualbox-ose
DISTVERSION=	4.2.18
CATEGORIES=	emulators
MASTER_SITES=	http://download.virtualbox.org/virtualbox/${DISTVERSION}/ \
		http://tmp.chruetertee.ch/ \
		http://disasterarea.chruetertee.ch/
PKGNAMESUFFIX=	-additions
DISTNAME=	VirtualBox-${DISTVERSION}

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	VirtualBox additions for FreeBSD guests

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		as86:${PORTSDIR}/devel/dev86 \
		kmk:${PORTSDIR}/devel/kBuild

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}
WRKSRC=		${WRKDIR}/VirtualBox-${PORTVERSION}
USE_RC_SUBR=	vboxguest vboxservice
USES=		iconv kmod
ONLY_FOR_ARCHS=	i386 amd64
FETCH_ARGS=	-pRr
USE_BZIP2=	yes
MAKE_JOBS_UNSAFE=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gcc="${CC}" --with-g++="${CXX}" --nofatal \
		--disable-xpcom --disable-sdl-ttf --disable-pulse \
		--disable-alsa --disable-dbus --disable-python

CONFLICTS=	bcc-[0-9]*
CONFLICTS_INSTALL=	virtualbox-ose-additions-devel-[3,4]* virtualbox-ose-[3,4]* virtualbox-ose-devel-[3,4]* virtualbox-ose-legacy-[3,4]*

OPTIONS_DEFINE=	DEBUG X11 OPENGL
OPTIONS_DEFAULT=	X11

NO_STAGE=	yes
.include <bsd.port.options.mk>

VIDEODIR=	${PREFIX}/lib/xorg/modules/drivers
INPUTDIR=	${PREFIX}/lib/xorg/modules/input

VBOX_BIN=	${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/additions

KMK_BUILDTYPE=	release
KMK_CONFIG=	VBOX_LIBPATH_X11=${LOCALBASE}
KMK_FLAGS=

MAKE_FLAGS=	SYSDIR=${SRC_BASE}/sys

.if ${PORT_OPTIONS:MDEBUG}
KMK_FLAGS+=	BUILD_TYPE=debug
KMK_BUILDTYPE=	debug
MAKE_FLAGS+=	DEBUG_FLAGS="-O1 -g"
PLIST_SUB+=	WITH_DEBUG=""
.else
PLIST_SUB+=	WITH_DEBUG="@comment "
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
USE_XORG+=	xcomposite xdamage xext xfixes
USE_GL=		gl
PLIST_SUB+=	OPENGL=""
.else
CONFIGURE_ARGS+=--disable-opengl
PLIST_SUB+=	OPENGL="@comment "
.endif

.if ${ARCH} == i386
KMK_ARCH=	freebsd.x86
.else
KMK_ARCH=	freebsd.${ARCH}
.endif

XSERVER_ABI:=	${XSERVER_VER:S/.//:R}

.include <bsd.port.pre.mk>

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
.if empty(ICONV_LIB)
	@${REINPLACE_CMD} -e 's|iconv||' ${WRKSRC}/Config.kmk ${WRKSRC}/src/VBox/Runtime/Makefile.kmk \
		${WRKSRC}/src/VBox/Additions/x11/VBoxClient/Makefile.kmk
.endif

pre-build:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/env.sh \
		${WRKSRC}/src/VBox/Additions/freebsd/Installer/vboxguest.sh

do-build:
	cd ${WRKSRC} && ${SH} env.sh && ${KMK_CONFIG} ${LOCALBASE}/bin/kmk ${KMK_FLAGS}
	cd ${VBOX_BIN}/src && make ${MAKE_FLAGS}

do-install:
	${INSTALL_KLD} ${VBOX_BIN}/src/vboxguest/vboxguest.ko ${KMODDIR}
.if ${PORT_OPTIONS:MDEBUG}
	${INSTALL_KLD} ${VBOX_BIN}/src/vboxguest/vboxguest.ko.symbols ${KMODDIR}
.endif
.if ${PORT_OPTIONS:MX11}
	${INSTALL_KLD} ${VBOX_BIN}/vboxvideo.ko ${KMODDIR}
.if ${PORT_OPTIONS:MDEBUG}
	${INSTALL_KLD} ${VBOX_BIN}/vboxvideo.ko.symbols ${KMODDIR}
.endif
.endif

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

.if ${PORT_OPTIONS:MOPENGL}
	${MKDIR} ${PREFIX}/lib
	${INSTALL_DATA} ${VBOX_BIN}/VBoxOGL.so ${PREFIX}/lib/
	${INSTALL_DATA} ${VBOX_BIN}/VBoxOGLarrayspu.so ${PREFIX}/lib/
	${INSTALL_DATA} ${VBOX_BIN}/VBoxOGLcrutil.so ${PREFIX}/lib/
	${INSTALL_DATA} ${VBOX_BIN}/VBoxOGLerrorspu.so ${PREFIX}/lib/
	${INSTALL_DATA} ${VBOX_BIN}/VBoxOGLfeedbackspu.so ${PREFIX}/lib/
	${INSTALL_DATA} ${VBOX_BIN}/VBoxOGLpackspu.so ${PREFIX}/lib/
	${INSTALL_DATA} ${VBOX_BIN}/VBoxOGLpassthroughspu.so ${PREFIX}/lib/

	${MKDIR} ${PREFIX}/lib/dri
	${LN} -sf ${PREFIX}/lib/VBoxOGL.so ${PREFIX}/lib/dri/vboxvideo_dri.so
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
