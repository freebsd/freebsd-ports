# New ports collection makefile for:	virtualbox-ose-additions
# Date created:		2009-09-21
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	virtualbox-ose
DISTVERSION=	3.2.2
CATEGORIES=	emulators kld
MASTER_SITES=	http://tmp.chruetertee.ch/ \
		http://freebsd.unixfreunde.de/sources/ \
		http://disasterarea.chruetertee.ch/ \
		http://mirror.4bit.ws/
PKGNAMESUFFIX=	-additions
DISTNAME=	VirtualBox-${DISTVERSION}-OSE

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	VirtualBox additions for FreeBSD guests

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		as86:${PORTSDIR}/devel/dev86 \
		kmk:${PORTSDIR}/devel/kBuild

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}
WRKSRC=		${WRKDIR}/VirtualBox-${PORTVERSION}_OSE
USE_RC_SUBR=	vboxguest
ONLY_FOR_ARCHS=	i386 amd64
USE_BZIP2=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gcc="${CC}" --with-g++="${CXX}" --nofatal \
		--disable-xpcom --disable-sdl-ttf --disable-pulse \
		--disable-alsa --disable-dbus --disable-python \
		--build-headless

CONFLICTS=	bcc-[0-9]* virtualbox-ose-3.*

OPTIONS=	DEBUG "Build with debugging symbols" off \
		X11 "Build with X11 support" on \
		HAL "Install HAL policy file for additions" on \
		OPENGL "Build with OpenGL support" off

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

.if defined(WITH_DEBUG)
KMK_FLAGS+=	BUILD_TYPE=debug
KMK_BUILDTYPE=	debug
.endif

.if !defined(WITHOUT_X11)
VBOX_WITH_X11=	1
USE_XORG=	xcursor xmu inputproto xrandr
PLIST_SUB+=	X11=""
.else
.if !defined(WITHOUT_HAL)
BROKEN=		HAL requires X11 support. Run 'make config' again!
.endif
VBOX_WITH_X11=
PLIST_SUB+=	X11="@comment "
.endif

.if !defined(WITHOUT_HAL)
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
PLIST_SUB+=	HAL=""
.else
PLIST_SUB+=	HAL="@comment "
.endif

.if defined(WITHOUT_OPENGL)
CONFIGURE_ARGS+=--disable-opengl
.else
USE_GL=		gl
.endif

.if ${OSVERSION} < 700000
BROKEN=	Does not compile on FreeBSD 6.X
.endif

.if ${ARCH} == i386
KMK_ARCH=	freebsd.x86
.else
KMK_ARCH=	freebsd.${ARCH}
.endif

.if !exists(${SRC_BASE}/sys/kern/bus_if.m)
IGNORE=		requires kernel sources
.endif

.include <bsd.port.pre.mk>

pre-everything::
.if ${ARCH} == "amd64"
.if !exists(/usr/lib32)
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
		${WRKSRC}/kBuild/sdks/LIBSDL.kmk
	@${REINPLACE_CMD} -e 's|\$$KBUILDDIR_BIN/kmk_sed|${PREFIX}/bin/kmk_sed|g' ${WRKSRC}/configure

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

.if !defined(WITHOUT_X11)
	${INSTALL_PROGRAM} ${VBOX_BIN}/VBoxClient ${PREFIX}/sbin/

	${MKDIR} ${VIDEODIR}
	${INSTALL_DATA} ${VBOX_BIN}/vboxvideo_drv_17.so ${VIDEODIR}/vboxvideo_drv.so

	${MKDIR} ${INPUTDIR}
	${INSTALL_DATA} ${VBOX_BIN}/vboxmouse_drv_17.so ${INPUTDIR}/vboxmouse_drv.so
.endif

.if !defined(WITHOUT_HAL)
	${INSTALL_DATA} ${WRKSRC}/src/VBox/Additions/linux/installer/90-vboxguest.fdi \
		${PREFIX}/share/hal/fdi/policy/10osvendor/
.endif

.include <bsd.port.post.mk>
