# New ports collection makefile for:	virtualbox
# Date created:		2009-05-02
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	virtualbox
DISTVERSION=	2.2.51.r20457
PORTREVISION=	3
CATEGORIES=	emulators kld
MASTER_SITES=	http://tmp.chruetertee.ch/ \
		http://freebsd.unixfreunde.de/sources/ \
		http://disasterarea.chruetertee.ch/ \
		http://mirror.4bit.ws/ \
		http://dlc.sun.com/virtualbox/${VBOX_GUEST_VER}/:guestadditions
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${GADISTFILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

#for discussion please use emulation@FreeBSD.org
MAINTAINER=	vbox@FreeBSD.org
COMMENT=	A general-purpose full virtualizer for x86 hardware

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		as86:${PORTSDIR}/devel/dev86 \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		kmk:${PORTSDIR}/devel/kBuild
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		curl.5:${PORTSDIR}/ftp/curl

ONLY_FOR_ARCHS=	i386 amd64
USE_XORG=	xcursor xmu
USE_GNOME=	libidl
USE_SDL=	sdl
USE_CDRTOOLS=	yes
USE_PYTHON=	yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-2.2.51r20457

HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/virtualbox

CONFLICTS=	bcc-[0-9]*

VBOXGROUP?=	vboxusers
VBOXGID?=	920
VBOX_FRONTENDS=	VBoxBFE VBoxHeadless VBoxSDL
VBOX_GUEST_VER=	2.2.4

SUB_FILES=	pkg-install

SUB_LIST=	PREFIX=${PREFIX} \
		VBOXGROUP=${VBOXGROUP} \
		VBOXGID=${VBOXGID}

OPTIONS=	QT4 "Build with QT4 Frontend" on \
		DEBUG "Build with debugging symbols" off \
		GUESTADDITIONS "Build with Guest Additions" off \
		DBUS "Build with D-Bus and HAL support" on \
		PULSEAUDIO "Build with PulseAudio" off

.include <bsd.port.options.mk>

KMODDIR=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR:C,^/,,}
KMK_BUILDTYPE=	release
KMK_CONFIG=	VBOX_LIBPATH_X11=${LOCALBASE} VBOX_FREEBSD_SRC=${SRC_BASE}/sys
KMK_FLAGS=

.if !defined(WITHOUT_QT4)
USE_QT_VER=	4
QT_NONSTANDARD=	yes
QT_COMPONENTS=	gui network moc_build uic_build rcc_build linguist
INSTALLS_ICONS=	yes
VBOX_FRONTENDS+=	VirtualBox
PLIST_SUB+=	QT4=""
.else
CONFIGURE_ARGS+=--disable-qt4
PLIST_SUB+=	QT4="@comment "
.endif

.if defined(WITH_GUESTADDITIONS)
GUESTADDITIONS=	VBoxGuestAdditions_${VBOX_GUEST_VER}.iso
GADISTFILES=	${GUESTADDITIONS}:guestadditions
RESTRICTED=	for personal use only
RESTRICTED_FILES=	${GUESTADDITIONS}
FETCH_ARGS=	-pRr
PLIST_SUB+=	GUESTADDITIONS=""
.else
PLIST_SUB+=	GUESTADDITIONS="@comment "
.endif

.if defined(WITH_DEBUG)
KMK_FLAGS+=	BUILD_TYPE=debug
KMK_BUILDTYPE=	debug
.endif

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
.else
CONFIGURE_ARGS+=--disable-dbus
.endif

.if !defined(WITH_PULSEAUDIO)
CONFIGURE_ARGS+=--disable-pulse
.endif

.if !exists(${SRC_BASE}/sys/kern/bus_if.m)
IGNORE=		requires kernel sources for the kernel module
.endif

.if ${OSVERSION} < 700000
BROKEN=	Does not compile on FreeBSD 6.X
.endif

.if ${ARCH} == i386
KMK_ARCH=	freebsd.x86
PLIST_SUB+=	I386=""
.else
.if !exists(/usr/lib32)
IGNORE=		requires 32-bit libraries installed under /usr/lib32
.endif
KMK_ARCH=	freebsd.${ARCH}
PLIST_SUB+=	I386="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|#VBOX_PATH_APP_PRIVATE_ARCH  = /usr/lib/virtualbox|VBOX_PATH_APP_PRIVATE_ARCH = ${PREFIX}/lib/virtualbox|'\
		${WRKSRC}/Config.kmk
	@${REINPLACE_CMD} -e 's|#VBOX_PATH_SHARED_LIBS       = /usr/lib|VBOX_PATH_SHARED_LIBS = ${PREFIX}/lib/virtualbox|' \
		${WRKSRC}/Config.kmk
	@${REINPLACE_CMD} -e 's|#VBOX_WITH_RUNPATH = /usr/lib/virtualbox|VBOX_WITH_RUNPATH = ${PREFIX}/lib/virtualbox|' \
		${WRKSRC}/Config.kmk
	@${REINPLACE_CMD} -e 's|#VBOX_PATH_APP_PRIVATE       = /usr/lib/virtualbox|VBOX_PATH_APP_PRIVATE = ${DATADIR}|' \
		${WRKSRC}/Config.kmk
	@${REINPLACE_CMD} -e 's|#VBOX_PATH_APP_DOCS         = /usr/share/doc/virtualbox|VBOX_PATH_APP_DOCS = ${DOCSDIR}|' \
		${WRKSRC}/Config.kmk
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Config.kmk ${WRKSRC}/configure \
		${WRKSRC}/kBuild/units/qt3.kmk ${WRKSRC}/kBuild/units/qt4.kmk \
		${WRKSRC}/kBuild/sdks/LIBSDL.kmk
	@${REINPLACE_CMD} -e 's|\$$KBUILDDIR_BIN/kmk_sed|${PREFIX}/bin/kmk_sed|g' ${WRKSRC}/configure

pre-build:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/env.sh

do-build:
	cd ${WRKSRC} && ${SH} env.sh && ${KMK_CONFIG} ${LOCALBASE}/bin/kmk ${KMK_FLAGS}

do-install:
	${MKDIR} ${KMODDIR}
	${INSTALL_KLD} ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/vboxdrv.ko ${KMODDIR}

	${MKDIR} ${PREFIX}/lib/virtualbox
	(cd ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin && ${COPYTREE_SHARE} "*.so *.gc *.r0 components" ${PREFIX}/lib/virtualbox)

	${MKDIR} ${PREFIX}/bin
.for f in VBoxManage VBoxNetDHCP VBoxSVC VBoxXPCOMIPCD ${VBOX_FRONTENDS} VBoxTestOGL
	${INSTALL_PROGRAM} ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/$f ${PREFIX}/lib/virtualbox/
	${LN} -sf ${PREFIX}/lib/virtualbox/${f} ${PREFIX}/bin/
.endfor

.for f in VBoxNetDHCP ${VBOX_FRONTENDS}
	${CHMOD} 4511 ${PREFIX}/lib/virtualbox/${f}
.endfor

.for f in VBoxManage VBoxSVC VBoxXPCOMIPCD
	${CHMOD} 0711 ${PREFIX}/lib/virtualbox/${f}
.endfor

.if defined(WITH_GUESTADDITIONS)
	${INSTALL_DATA} ${DISTDIR}/${GUESTADDITIONS} ${PREFIX}/lib/virtualbox/
	${LN} -sf ${PREFIX}/lib/virtualbox/${GUESTADDITIONS} ${PREFIX}/lib/virtualbox/VBoxGuestAdditions.iso
.endif

post-install:
	@${SETENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.for f in VBoxManage VBoxNetDHCP VBoxSVC VBoxXPCOMIPCD ${VBOX_FRONTENDS}
	${CHOWN} root:${VBOXGROUP} ${PREFIX}/lib/virtualbox/${f}
.endfor

.if !defined(WITHOUT_QT4)
	${MKDIR} ${PREFIX}/share/icons/hicolor/48x48/apps/
	${INSTALL_DATA} ${WRKSRC}/src/VBox/Frontends/VirtualBox/images/OSE/VirtualBox_48px.png ${PREFIX}/share/icons/hicolor/48x48/apps/VBox.png
	${MKDIR} ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/src/VBox/Installer/solaris/virtualbox.desktop ${PREFIX}/share/applications/virtualbox.desktop
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
