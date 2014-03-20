# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	virtualbox-ose
DISTVERSION=	4.2.22
CATEGORIES=	emulators
MASTER_SITES=	http://download.virtualbox.org/virtualbox/${DISTVERSION}/ \
		http://tmp.chruetertee.ch/ \
		http://disasterarea.chruetertee.ch/ \
		http://download.virtualbox.org/virtualbox/${VBOX_GUEST_VER}/:guestadditions
PKGNAMESUFFIX=	-legacy
DISTFILES=	VirtualBox-${DISTVERSION}${EXTRACT_SUFX} ${GADISTFILES}
EXTRACT_ONLY=	VirtualBox-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	A general-purpose full virtualizer for x86 hardware

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		kmk:${PORTSDIR}/devel/kBuild \
		gtar:${PORTSDIR}/archivers/gtar \
		cdrecord:${PORTSDIR}/sysutils/cdrtools \
		python:${PORTSDIR}/lang/python
LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libxslt.so:${PORTSDIR}/textproc/libxslt \
		libcurl.so:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	${KMODDIR}/vboxdrv.ko:${PORTSDIR}/emulators/virtualbox-ose-kmod-legacy \
		cdrecord:${PORTSDIR}/sysutils/cdrtools

WRKSRC=		${WRKDIR}/VirtualBox-${PORTVERSION}
ONLY_FOR_ARCHS=	i386 amd64
USES=		iconv pkgconfig tar:bzip2
USE_GCC=	any
USE_GNOME=	libidl
USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	vboxapi
PYDISTUTILS_PKGVERSION=	1.0
PYDISTUTILS_NOEGGINFO=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gcc="${CC}" --with-g++="${CXX}" --passive-mesa
USE_LDCONFIG=	${PREFIX}/lib/virtualbox

CONFLICTS_INSTALL=	virtualbox-ose-4* virtualbox-ose-devel-4* virtualbox-ose-additions-4* virtualbox-ose-additions-devel-4*

VBOXUSER?=	vboxusers
VBOXWSUSER?=	vboxusers
VBOXGROUP?=	vboxusers
USERS=		${VBOXUSER}
GROUPS=		${VBOXGROUP}
VBOX_FRONTENDS=	VBoxAutostart VBoxHeadless
VBOX_GUEST_VER=	${PORTVERSION}

OPTIONS_DEFINE=	QT4 DEBUG GUESTADDITIONS DBUS PULSEAUDIO UDPTUNNEL VDE VNC WEBSERVICE NLS X11
OPTIONS_DEFAULT=	QT4 DBUS X11 UDPTUNNEL VNC
OPTIONS_SUB=	X11 QT4 GUESTADDITIONS VNC NLS WEBSERVICE
DEBUG_DESC=	Debug symbols, additional logs and assertions
QT4_DESC=	Build with QT4 Frontend
GUESTADDITIONS_DESC=	Build with Guest Additions
UDPTUNNEL_DESC=	Build with UDP tunnel support
VDE_DESC=	Build with VDE support
VNC_DESC=	Build with VNC support
WEBSERVICE_DESC=	Build Webservice

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=	--disable-pulse

DBUS_LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus
DBUS_CONFIGURE_OFF=	--disable-dbus

VNC_LIB_DEPENDS=	libvncserver.so:${PORTSDIR}/net/libvncserver
VNC_CONFIGURE_ON=	--enable-vnc

VDE_RUN_DEPENDS=	vde_switch:${PORTSDIR}/net/vde2
VDE_CONFIGURE_ON=	--enable-vde

# bmake doesn't know about unsetenv=true
.if defined(.PARSEDIR)
ENV=
.export ENV
.else
.SHELL:		path="/bin/sh" unsetenv=true
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

KMODDIR=	/boot/modules

PLIST_SUB+=	PYTHON_VER=${PYTHON_VER} \
		PYTHON_VERU=${PYTHON_VER:S/./_/} \
		GUEST_VER=${VBOX_GUEST_VER}

SUB_LIST+=	VBOXUSER=${VBOXUSER} \
		VBOXWSUSER=${VBOXWSUSER}
USE_RC_SUBR+=	vboxheadless vboxwatchdog

KMK_BUILDTYPE=	release
KMK_CONFIG=	VBOX_LIBPATH_X11=${LOCALBASE} VBOX_FREEBSD_SRC=${SRC_BASE}/sys
KMK_FLAGS=	-j 1

.if empty(PORT_OPTIONS:MQT4) && !empty(PORT_OPTIONS:MNLS)
BROKEN=		NLS support requires QT4 frontend. Run 'make config' again!
.endif

.if empty(PORT_OPTIONS:MX11) && !empty(PORT_OPTIONS:MQT4)
BROKEN=		QT4 frontend requires X11 support. Run 'make config' again!
.endif

.if ${PORT_OPTIONS:MX11}
USE_SDL=	sdl
USE_XORG=	xcursor xmu inputproto xinerama
VBOX_FRONTENDS+=VBoxBFE VBoxSDL
.else
CONFIGURE_ARGS+=--build-headless
.endif

.if ${PORT_OPTIONS:MQT4}
QT_NONSTANDARD=	yes
USE_QT4=	gui network moc_build opengl uic_build rcc_build linguist
INSTALLS_ICONS=	yes
VBOX_FRONTENDS+=VirtualBox VBoxTestOGL
.else
CONFIGURE_ARGS+=--disable-qt4
.endif

.if ${PORT_OPTIONS:MGUESTADDITIONS}
GUESTADDITIONS=	VBoxGuestAdditions_${VBOX_GUEST_VER}.iso
GADISTFILES=	${GUESTADDITIONS}:guestadditions
RESTRICTED=	for personal use only
RESTRICTED_FILES=	${GUESTADDITIONS}
.endif

.if ${PORT_OPTIONS:MDEBUG}
KMK_BUILDTYPE=	debug
KMK_FLAGS+=	BUILD_TYPE=debug
.endif

.if ${PORT_OPTIONS:MWEBSERVICE}
BUILD_DEPENDS+=	soapcpp2:${PORTSDIR}/devel/gsoap
VBOX_WEB=	vboxwebsrv webtest
USE_RC_SUBR+=	vboxwebsrv
.endif

.if ${ARCH} == i386
KMK_ARCH=	freebsd.x86
PLIST_SUB+=	I386=""
.else
KMK_ARCH=	freebsd.${ARCH}
PLIST_SUB+=	I386="@comment "
.endif

PLIST_SUB+=	ARCH="${KMK_ARCH}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900000 && ${OSVERSION} > 801500
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-src-VBox-Devices-PC-vbox.dsl
.endif

pre-everything::
.if ${ARCH} == "amd64"
.if !exists(/usr/lib32/libc.so)
	@${ECHO} 'Requires 32-bit libraries installed under /usr/lib32.'
	@${ECHO} 'Do: cd /usr/src; make build32 install32; /etc/rc.d/ldconfig restart'
	@${FALSE}
.endif
.endif

post-patch:
	@${ECHO} 'VBOX_PATH_APP_PRIVATE_ARCH = ${PREFIX}/lib/virtualbox' > ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_SHARED_LIBS = ${PREFIX}/lib/virtualbox' >> ${WRKSRC}/LocalConfig.kmk
	@var=${_GCC_RUNTIME}; ${ECHO} "VBOX_WITH_RUNPATH = $${var:+$${var}:}${PREFIX}/lib/virtualbox" >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_APP_PRIVATE = ${DATADIR}' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_APP_DOCS = ${DOCSDIR}' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_INSTALLER = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_VBOXDRV = ' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_VIDEOHWACCEL = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_NETFLT = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_NETADP = ' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_TESTCASES=' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'SDK_VBOX_LIBPNG_INCS = ${PREFIX}/include/libpng' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'SDK_VBOX_LIBPNG_LIBS = png' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_ADDITIONS=' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_X11_ADDITIONS=' >> ${WRKSRC}/LocalConfig.kmk
.if ${PORT_OPTIONS:MVNC}
	@${ECHO} 'VBOX_WITH_EXTPACK_VNC = 1' >> ${WRKSRC}/LocalConfig.kmk
.endif
.if ${PORT_OPTIONS:MUDPTUNNEL}
	@${ECHO} 'VBOX_WITH_UDPTUNNEL = 1' >> ${WRKSRC}/LocalConfig.kmk
.endif
.if ${PORT_OPTIONS:MWEBSERVICE}
	@${ECHO} 'VBOX_WITH_WEBSERVICES = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_GSOAP_INSTALLED = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_GSOAP = ${PREFIX}/lib/gsoap' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_GSOAP_BIN = ${PREFIX}/bin' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_GSOAP_IMPORT = ${PREFIX}/share/gsoap/import' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_GCC_PEDANTIC_CXX = -Wshadow $(VBOX_GCC_WARN) -Wno-long-long' >> ${WRKSRC}/LocalConfig.kmk
.endif
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Config.kmk ${WRKSRC}/configure \
		${WRKSRC}/kBuild/units/qt3.kmk ${WRKSRC}/kBuild/units/qt4.kmk \
		${WRKSRC}/kBuild/sdks/LIBSDL.kmk \
		${WRKSRC}/src/libs/xpcom18a4/python/gen_python_deps.py
	@${REINPLACE_CMD} -e 's|\$$KBUILDDIR_BIN/kmk_sed|${LOCALBASE}/bin/kmk_sed|g' ${WRKSRC}/configure
.if empty(ICONV_LIB)
	@${REINPLACE_CMD} -e 's|iconv||' ${WRKSRC}/Config.kmk ${WRKSRC}/src/VBox/Runtime/Makefile.kmk
	@${ECHO} 'VBOX_ICONV_DEFS = LIBICONV_PLUG' >> ${WRKSRC}/LocalConfig.kmk
.endif

pre-build:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/env.sh

do-build:
	cd ${WRKSRC} && ${SH} env.sh && ${KMK_CONFIG} ${LOCALBASE}/bin/kmk ${KMK_FLAGS}

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/sdk/bindings/xpcom && ${COPYTREE_SHARE} "idl samples" ${DATADIR})

	${MKDIR} ${PREFIX}/include/virtualbox
	(cd ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/sdk/bindings/xpcom/include && ${COPYTREE_SHARE} "*" ${PREFIX}/include/virtualbox)

	${MKDIR} ${PREFIX}/lib/virtualbox
	(cd ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin && ${COPYTREE_SHARE} "*.so *.gc *.r0 *.fd components VBoxExtPackHelperApp" ${PREFIX}/lib/virtualbox)

.if ${PORT_OPTIONS:MNLS}
	${MKDIR} ${DATADIR}/nls
	(cd ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/obj/VirtualBox/qtnls && ${COPYTREE_SHARE} "*.qm" ${DATADIR}/nls)
.endif

	${MKDIR} ${PREFIX}/bin
.for f in VBoxManage VBoxNetAdpCtl VBoxNetDHCP VBoxSVC VBoxXPCOMIPCD VBoxBalloonCtrl ${VBOX_FRONTENDS} ${VBOX_WEB}
	${INSTALL_PROGRAM} ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/${f} ${PREFIX}/lib/virtualbox/
	${LN} -sf ${PREFIX}/lib/virtualbox/${f} ${PREFIX}/bin/
.endfor

.for f in VBoxNetAdpCtl VBoxNetDHCP ${VBOX_FRONTENDS}
	${CHMOD} 4511 ${PREFIX}/lib/virtualbox/${f}
.endfor

.for f in VBoxManage VBoxSVC VBoxXPCOMIPCD VBoxExtPackHelperApp VBoxBalloonCtrl
	${CHMOD} 0711 ${PREFIX}/lib/virtualbox/${f}
.endfor

.if ${PORT_OPTIONS:MVNC}
	${MKDIR} ${PREFIX}/lib/virtualbox/ExtensionPacks
	${CP} -a ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/ExtensionPacks/VNC ${PREFIX}/lib/virtualbox/ExtensionPacks
.endif

.if ${PORT_OPTIONS:MWEBSERVICE}
	${MKDIR} ${DATADIR}/sdk/bindings/webservice
.for f in vboxweb.wsdl vboxwebService.wsdl
	${INSTALL_DATA} ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/sdk/bindings/webservice/${f} ${DATADIR}/sdk/bindings/webservice/
.endfor
.endif

.if ${PORT_OPTIONS:MGUESTADDITIONS}
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
.for f in VBoxManage VBoxNetDHCP VBoxSVC VBoxXPCOMIPCD VBoxExtPackHelperApp VBoxBalloonCtrl ${VBOX_FRONTENDS}
	${CHOWN} root:${VBOXGROUP} ${PREFIX}/lib/virtualbox/${f}
.endfor

	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${FIND} ${PREFIX}/include/virtualbox -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${FIND} ${PREFIX}/lib/virtualbox -type d -print0 | ${XARGS} -0 ${CHMOD} 755

.if ${PORT_OPTIONS:MQT4}
	${MKDIR} ${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/src/VBox/Frontends/VirtualBox/images/OSE/VirtualBox_48px.png ${PREFIX}/share/pixmaps/VBox.png
	${MKDIR} ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/src/VBox/Installer/freebsd/virtualbox.desktop ${PREFIX}/share/applications/virtualbox.desktop
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
