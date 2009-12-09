# New ports collection makefile for:	virtualbox
# Date created:		2009-05-02
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	virtualbox
DISTVERSION=	3.0.51r22902
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
		xslt.2:${PORTSDIR}/textproc/libxslt \
		curl.5:${PORTSDIR}/ftp/curl

ONLY_FOR_ARCHS=	i386 amd64
USE_GNOME=	libidl
USE_CDRTOOLS=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	vboxapi
PYDISTUTILS_PKGVERSION=	1.0
PYDISTUTILS_NOEGGINFO=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gcc="${CC}" --with-g++="${CXX}"
USE_LDCONFIG=	${PREFIX}/lib/virtualbox

CONFLICTS=	bcc-[0-9]*

VBOXGROUP?=	vboxusers
VBOXGID?=	920
VBOX_FRONTENDS=	VBoxHeadless
VBOX_GUEST_VER=	3.0.6

SUB_FILES=	pkg-install

SUB_LIST=	PREFIX=${PREFIX} \
		VBOXGROUP=${VBOXGROUP} \
		VBOXGID=${VBOXGID}

OPTIONS=	QT4 "Build with QT4 Frontend" on \
		DEBUG "Build with debugging symbols" off \
		GUESTADDITIONS "Build with Guest Additions" off \
		DBUS "Build with D-Bus and HAL support" on \
		PULSEAUDIO "Build with PulseAudio" off \
		X11 "Build with X11 support" on \
		NLS "Native language support" on

.include <bsd.port.options.mk>

PLIST_SUB+=	KMODDIR=${KMODDIR:C,^/,,} \
		PYTHON_VER=${PYTHON_VER} \
		PYTHON_VERU=${PYTHON_VER:S/./_/} \
		GUEST_VER=${VBOX_GUEST_VER}

KMODDIR=	/boot/modules
KMK_BUILDTYPE=	release
KMK_CONFIG=	VBOX_LIBPATH_X11=${LOCALBASE} VBOX_FREEBSD_SRC=${SRC_BASE}/sys
KMK_FLAGS=

.if defined(WITHOUT_QT4) && !defined(WITHOUT_NLS)
BROKEN=		NLS support requires QT4 frontend. Run 'make config' again!
.endif

.if defined(WITHOUT_X11) && !defined(WITHOUT_QT4)
BROKEN=		QT4 frontend requires X11 support. Run 'make config' again!
.endif

.if !defined(WITHOUT_X11)
USE_SDL=	sdl
USE_XORG=	xcursor xmu
VBOX_FRONTENDS+=VBoxBFE VBoxSDL VBoxTestOGL
PLIST_SUB+=	X11=""
.else
CONFIGURE_ARGS+=--build-headless
PLIST_SUB+=	X11="@comment "
.endif

.if !defined(WITHOUT_QT4)
USE_QT_VER=	4
QT_NONSTANDARD=	yes
QT_COMPONENTS=	gui network moc_build uic_build rcc_build linguist
INSTALLS_ICONS=	yes
VBOX_FRONTENDS+=VirtualBox
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

.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
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
KMK_ARCH=	freebsd.${ARCH}
PLIST_SUB+=	I386="@comment "
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
	@${ECHO} 'VBOX_PATH_APP_PRIVATE_ARCH = ${PREFIX}/lib/virtualbox' > ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_SHARED_LIBS = ${PREFIX}/lib/virtualbox' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_RUNPATH = ${PREFIX}/lib/virtualbox' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_APP_PRIVATE = ${DATADIR}' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_APP_DOCS = ${DOCSDIR}' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_INSTALLER = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_TESTCASES=' >> ${WRKSRC}/LocalConfig.kmk
.if defined(WITHOUT_X11)
	@${ECHO} 'VBOX_WITH_X11_ADDITIONS=' >> ${WRKSRC}/LocalConfig.kmk
.endif
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Config.kmk ${WRKSRC}/configure \
		${WRKSRC}/kBuild/units/qt3.kmk ${WRKSRC}/kBuild/units/qt4.kmk \
		${WRKSRC}/kBuild/sdks/LIBSDL.kmk \
		${WRKSRC}/src/libs/xpcom18a4/python/gen_python_deps.py
	@${REINPLACE_CMD} -e 's|\$$KBUILDDIR_BIN/kmk_sed|${PREFIX}/bin/kmk_sed|g' ${WRKSRC}/configure

pre-build:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/env.sh

do-build:
	cd ${WRKSRC} && ${SH} env.sh && ${KMK_CONFIG} ${LOCALBASE}/bin/kmk ${KMK_FLAGS}

do-install:
	${MKDIR} ${KMODDIR}
.for f in vboxdrv.ko vboxnetadp.ko vboxnetflt.ko
	${INSTALL_KLD} ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/${f} ${KMODDIR}
.endfor

	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/sdk/bindings/xpcom && ${COPYTREE_SHARE} "idl samples" ${DATADIR})

	${MKDIR} ${PREFIX}/include/virtualbox
	(cd ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/sdk/bindings/xpcom/include && ${COPYTREE_SHARE} "*" ${PREFIX}/include/virtualbox)

	${MKDIR} ${PREFIX}/lib/virtualbox
	(cd ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin && ${COPYTREE_SHARE} "*.so *.gc *.r0 components" ${PREFIX}/lib/virtualbox)

.if !defined(WITHOUT_NLS)
	${MKDIR} ${DATADIR}/nls
	(cd ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/obj/VirtualBox/qtnls && ${COPYTREE_SHARE} "*.qm" ${DATADIR}/nls)
.endif

	${MKDIR} ${PREFIX}/bin
.for f in VBoxManage VBoxNetAdpCtl VBoxNetDHCP VBoxSVC VBoxXPCOMIPCD ${VBOX_FRONTENDS}
	${INSTALL_PROGRAM} ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/${f} ${PREFIX}/lib/virtualbox/
	${LN} -sf ${PREFIX}/lib/virtualbox/${f} ${PREFIX}/bin/
.endfor

.for f in VBoxNetAdpCtl VBoxNetDHCP ${VBOX_FRONTENDS}
	${CHMOD} 4511 ${PREFIX}/lib/virtualbox/${f}
.endfor

.for f in VBoxManage VBoxSVC VBoxXPCOMIPCD
	${CHMOD} 0711 ${PREFIX}/lib/virtualbox/${f}
.endfor

.if defined(WITH_GUESTADDITIONS)
	${MKDIR} ${PREFIX}/lib/virtualbox/additions
	${INSTALL_DATA} ${DISTDIR}/${GUESTADDITIONS} ${PREFIX}/lib/virtualbox/additions/
	${LN} -sf ${PREFIX}/lib/virtualbox/additions/${GUESTADDITIONS} ${PREFIX}/lib/virtualbox/additions/VBoxGuestAdditions.iso
.endif

	cd ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/sdk/installer && \
	VBOX_INSTALL_PATH="${PREFIX}/lib/virtualbox" ${PYTHON_CMD} vboxapisetup.py install

	@${MKDIR} ${PYTHON_SITELIBDIR}
	(cd ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/sdk/bindings/xpcom/python && ${COPYTREE_SHARE} "*" ${PYTHON_SITELIBDIR})
	${PYTHON_CMD} -mcompileall ${PYTHON_SITELIBDIR}/xpcom/

post-install:
	@${SETENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.for f in VBoxManage VBoxNetDHCP VBoxSVC VBoxXPCOMIPCD ${VBOX_FRONTENDS}
	${CHOWN} root:${VBOXGROUP} ${PREFIX}/lib/virtualbox/${f}
.endfor

	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${FIND} ${PREFIX}/include/virtualbox -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${FIND} ${PREFIX}/lib/virtualbox -type d -print0 | ${XARGS} -0 ${CHMOD} 755

.if !defined(WITHOUT_QT4)
	${MKDIR} ${PREFIX}/share/icons/hicolor/48x48/apps/
	${INSTALL_DATA} ${WRKSRC}/src/VBox/Frontends/VirtualBox/images/OSE/VirtualBox_48px.png ${PREFIX}/share/icons/hicolor/48x48/apps/VBox.png
	${MKDIR} ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/src/VBox/Installer/solaris/virtualbox.desktop ${PREFIX}/share/applications/virtualbox.desktop
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
