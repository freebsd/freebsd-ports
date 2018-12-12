# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	virtualbox-ose
PORTVERSION=	5.2.22
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://download.virtualbox.org/virtualbox/${PORTVERSION}/
PKGNAMESUFFIX?=	-additions
DISTNAME=	VirtualBox-${PORTVERSION}

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	VirtualBox additions for FreeBSD guests

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	yasm:devel/yasm \
		kmk:devel/kBuild \
		xsltproc:textproc/libxslt

CPE_VENDOR=	oracle
CPE_PRODUCT=	vm_virtualbox

PATCHDIR=	${.CURDIR}/../${PORTNAME}/files
WRKSRC=		${WRKDIR}/VirtualBox-${PORTVERSION}
USE_RC_SUBR=	vboxguest vboxservice
USES=		compiler:c++11-lang cpe iconv kmod python:build tar:bzip2
ONLY_FOR_ARCHS=	i386 amd64
MAKE_JOBS_UNSAFE=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-alsa \
			--disable-docs \
			--disable-libvpx \
			--disable-pulse \
			--disable-python \
			--disable-sdl-ttf \
			--disable-xpcom
CONFIGURE_ARGS+=	--nofatal --with-gcc="${CC}" --with-g++="${CXX}"

CONFLICTS_INSTALL=	virtualbox-ose-[0-9]* \
			virtualbox-ose-additions-devel-[0-9]* \
			virtualbox-ose-devel-[0-9]* \
			virtualbox-ose-legacy-[0-9]* \
			virtualbox-ose-lite-[0-9]* \
			virtualbox-ose-nox11-[0-9]*

OPTIONS_DEFINE=	DBUS DEBUG OPENGL X11
OPTIONS_DEFAULT=	DBUS X11
OPTIONS_SUB=	yes

DBUS_CONFIGURE_OFF=	--disable-dbus
DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
OPENGL_CONFIGURE_OFF=	--disable-opengl

.include <bsd.port.options.mk>

.if ${SLAVE_PORT} == no
CONFLICTS_INSTALL+=	virtualbox-ose-additions-nox11-[0-9]*
.else
CONFLICTS_INSTALL+=	virtualbox-ose-additions-[0-9]*
.endif

.if ${PORT_OPTIONS:MOPENGL} && empty(PORT_OPTIONS:MX11)
BROKEN=		OPENGL requires X11 support. Run 'make config' again!
.endif

VIDEODIR=	${PREFIX}/lib/xorg/modules/drivers
INPUTDIR=	${PREFIX}/lib/xorg/modules/input

VBOX_BIN=	${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/additions
VBOX_SBINS=	VBoxControl \
		VBoxService \
		mount_vboxvfs

BUILD_WRKSRC=	${VBOX_BIN}/src

KMK_BUILDTYPE=	release
KMK_CONFIG=	VBOX_LIBPATH_X11=${LOCALBASE} VBOX_FREEBSD_SRC=${SRC_BASE}/sys
KMK_FLAGS=

.if ${PORT_OPTIONS:MDEBUG}
KMK_FLAGS+=	BUILD_TYPE=debug
KMK_BUILDTYPE=	debug
MAKE_ARGS+=	DEBUG_FLAGS="-O1 -g"
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_XORG=	xcomposite xdamage xfixes
USE_GL=		gl
VBOX_LIBS=	VBoxEGL.so \
		VBoxOGL.so \
		VBoxOGLarrayspu.so \
		VBoxOGLcrutil.so \
		VBoxOGLerrorspu.so \
		VBoxOGLfeedbackspu.so \
		VBoxOGLpackspu.so \
		VBoxOGLpassthroughspu.so
.endif

.if ${PORT_OPTIONS:MX11}
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/xorg-server.pc:x11-servers/xorg-server
RUN_DEPENDS+=	xrandr:x11/xrandr
USE_XORG+=	xorgproto x11 xcursor xext xmu xorg-server xrandr xt
USES+=		pkgconfig
VBOX_WITH_X11=	1
XORG_DRV_ABI=	pkgconf --modversion xorg-server | \
		${SED} -E -e 's/\.[0-9]+$$//' -e 's/\.//'
.else
VBOX_WITH_X11=
.endif

.if ${ARCH} == i386
KMK_ARCH=	freebsd.x86
.else
KMK_ARCH=	freebsd.${ARCH}
.endif

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-Config.kmk \
		${PATCHDIR}/extrapatch-src-VBox-Additions-x11-vboxvideo-Makefile.kmk \
		${PATCHDIR}/extrapatch-src-VBox-Additions-x11-x11include-xorg-server-1.17.1-compiler.h
.if ${COMPILER_FEATURES:Mlibc++}
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-src-VBox-Additions-x11-VBoxClient-Makefile.kmk
.endif
.endif

post-patch:
	@${ECHO} 'VBOX_ONLY_ADDITIONS = 1' > ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_DRAG_AND_DROP = ${VBOX_WITH_X11}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_DRAG_AND_DROP_GH = ${VBOX_WITH_X11}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_X11_ADDITIONS = ${VBOX_WITH_X11}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_GCC_std = -std=c++11' >> ${WRKSRC}/LocalConfig.kmk
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e 's| -finline-limit=8000||' \
	    -e 's| -fno-merge-constants||' \
	    -e 's| -mpreferred-stack-boundary=2||' ${WRKSRC}/Config.kmk
.endif
	@${REINPLACE_CMD} -e 's|/usr/X11|${LOCALBASE}|g' \
	    ${WRKSRC}/src/VBox/Additions/x11/VBoxClient/display.cpp
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
	    ${WRKSRC}/Config.kmk ${WRKSRC}/configure \
	    ${WRKSRC}/kBuild/header.kmk ${WRKSRC}/kBuild/units/qt4.kmk \
	    ${WRKSRC}/kBuild/units/qt5.kmk ${WRKSRC}/kBuild/sdks/LIBSDL.kmk \
	    ${WRKSRC}/src/VBox/Additions/common/crOpenGL/load.c \
	    ${WRKSRC}/src/VBox/Additions/x11/Installer/98vboxadd-xclient \
	    ${WRKSRC}/src/VBox/Additions/x11/Installer/vboxclient.desktop
	@${REINPLACE_CMD} \
	    -e 's|\$$KBUILDDIR_BIN/kmk_sed|${LOCALBASE}/bin/kmk_sed|g' \
	    ${WRKSRC}/configure
.if empty(ICONV_LIB)
	@${REINPLACE_CMD} -e 's|iconv||' ${WRKSRC}/Config.kmk \
	    ${WRKSRC}/src/VBox/Runtime/Makefile.kmk \
	    ${WRKSRC}/src/VBox/Additions/x11/VBoxClient/Makefile.kmk
	@${ECHO} 'VBOX_ICONV_DEFS = LIBICONV_PLUG' >> ${WRKSRC}/LocalConfig.kmk
.endif

pre-build:
	cd ${WRKSRC} && ${SH} -c \
	    '. env.sh && ${KMK_CONFIG} ${LOCALBASE}/bin/kmk ${KMK_FLAGS}'

do-install:
	${MKDIR} ${STAGEDIR}${KMODDIR}
	${INSTALL_KLD} ${VBOX_BIN}/src/vboxguest/vboxguest.ko \
	    ${STAGEDIR}${KMODDIR}
	${INSTALL_KLD} ${VBOX_BIN}/vboxvfs.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_LIB} ${VBOX_BIN}/pam_vbox.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${VBOX_SBINS:S|^|${VBOX_BIN}/|} \
	    ${STAGEDIR}${PREFIX}/sbin/

do-install-DEBUG-on:
	${INSTALL_KLD} ${VBOX_BIN}/src/vboxguest/vboxguest.ko.symbols \
	    ${STAGEDIR}${KMODDIR}

do-install-X11-on:
	${INSTALL_PROGRAM} ${VBOX_BIN}/VBoxClient ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} \
	    ${WRKSRC}/src/VBox/Additions/x11/Installer/98vboxadd-xclient \
	    ${STAGEDIR}${PREFIX}/bin/VBoxClient-all
	# X11 autostart
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/autostart/
	${INSTALL_DATA} \
	    ${WRKSRC}/src/VBox/Additions/x11/Installer/vboxclient.desktop \
	    ${STAGEDIR}${PREFIX}/etc/xdg/autostart/
	# KDE autostart
	${MKDIR} ${STAGEDIR}${PREFIX}/share/autostart/
	${INSTALL_DATA} \
	    ${WRKSRC}/src/VBox/Additions/x11/Installer/vboxclient.desktop \
	    ${STAGEDIR}${PREFIX}/share/autostart/
	${MKDIR} ${STAGEDIR}${VIDEODIR}
	${INSTALL_DATA} ${VBOX_BIN}/vboxvideo_drv_$$(${XORG_DRV_ABI}).so \
	    ${STAGEDIR}${VIDEODIR}/vboxvideo_drv.so
	${MKDIR} ${STAGEDIR}${INPUTDIR}
	${INSTALL_DATA} ${VBOX_BIN}/vboxmouse_drv_$$(${XORG_DRV_ABI}).so \
	    ${STAGEDIR}${INPUTDIR}/vboxmouse_drv.so

do-install-OPENGL-on:
	${INSTALL_DATA} ${FILESDIR}/vboxvideo.conf \
	    ${STAGEDIR}${PREFIX}/etc/libmap.d/
	${INSTALL_DATA} ${VBOX_LIBS:S|^|${VBOX_BIN}/|} \
	    ${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.post.mk>
