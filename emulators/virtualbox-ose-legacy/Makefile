# New ports collection makefile for:	virtualbox-ose-legacy
# Date created:		2009-05-02
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	virtualbox-ose
DISTVERSION=	4.0.16
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://tmp.chruetertee.ch/ \
		http://freebsd.unixfreunde.de/sources/ \
		http://disasterarea.chruetertee.ch/ \
		http://download.virtualbox.org/virtualbox/${VBOX_GUEST_VER}/:guestadditions
PKGNAMESUFFIX=	-legacy
DISTFILES=	VirtualBox-${DISTVERSION}${EXTRACT_SUFX} ${GADISTFILES}
EXTRACT_ONLY=	VirtualBox-${DISTVERSION}${EXTRACT_SUFX}

#for discussion please use emulation@FreeBSD.org
MAINTAINER=	vbox@FreeBSD.org
COMMENT=	A general-purpose full virtualizer for x86 hardware

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		as86:${PORTSDIR}/devel/dev86 \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		kmk:${PORTSDIR}/devel/kBuild
LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		xslt.2:${PORTSDIR}/textproc/libxslt \
		curl.6:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	/boot/modules/vboxdrv.ko:${PORTSDIR}/emulators/virtualbox-ose-kmod-legacy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/VirtualBox-${PORTVERSION}_OSE
ONLY_FOR_ARCHS=	i386 amd64
USE_CDRTOOLS=	yes
USE_GNOME=	libidl
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	vboxapi
PYDISTUTILS_PKGVERSION=	1.0
PYDISTUTILS_NOEGGINFO=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gcc="${CC}" --with-g++="${CXX}" --passive-mesa
USE_LDCONFIG=	${PREFIX}/lib/virtualbox

CONFLICTS=	bcc-[0-9]*
CONFLICTS_BUILD=	kBuild-devel-[0-9]*
CONFLICTS_INSTALL=	virtualbox-ose-[3,4]* virtualbox-ose-devel-[3,4]* virtualbox-ose-additions-[3,4]* virtualbox-ose-additions-devel-[3,4]*

VBOXUSER?=	vboxusers
VBOXWSUSER?=	vboxusers
VBOXGROUP?=	vboxusers
USERS=		${VBOXUSER}
GROUPS=		${VBOXGROUP}
VBOX_FRONTENDS=	VBoxHeadless
VBOX_GUEST_VER=	${PORTVERSION}

OPTIONS_DEFINE=	QT4 DEBUG GUESTADDITIONS DBUS PULSEAUDIO UDPTUNNEL VDE VNC WEBSERVICE NLS X11
OPTIONS_DEFAULT=	QT4 DBUS X11 UDPTUNNEL
QT4_DESC=	Build with QT4 Frontend
GUESTADDITIONS_DESC=	Build with Guest Additions
UDPTUNNEL_DESC=	Build with UDP tunnel support
VDE_DESC=	Build with VDE support
VNC_DESC=	Build with VNC support
WEBSERVICE_DESC=	Build Webservice

.include <bsd.port.options.mk>

PLIST_SUB+=	PYTHON_VER=${PYTHON_VER} \
		PYTHON_VERU=${PYTHON_VER:S/./_/} \
		GUEST_VER=${VBOX_GUEST_VER}

SUB_LIST+=	VBOXUSER=${VBOXUSER}
USE_RC_SUBR+=	vboxheadless

KMK_BUILDTYPE=	release
KMK_CONFIG=	VBOX_LIBPATH_X11=${LOCALBASE} VBOX_FREEBSD_SRC=${SRC_BASE}/sys
KMK_FLAGS=

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
PLIST_SUB+=	X11=""
.else
CONFIGURE_ARGS+=--build-headless
PLIST_SUB+=	X11="@comment "
.endif

.if ${PORT_OPTIONS:MQT4}
QT_NONSTANDARD=	yes
USE_QT4=	gui network moc_build uic_build rcc_build linguist
INSTALLS_ICONS=	yes
VBOX_FRONTENDS+=VirtualBox VBoxTestOGL
PLIST_SUB+=	QT4=""
.else
CONFIGURE_ARGS+=--disable-qt4
PLIST_SUB+=	QT4="@comment "
.endif

.if ${PORT_OPTIONS:MGUESTADDITIONS}
GUESTADDITIONS=	VBoxGuestAdditions_${VBOX_GUEST_VER}.iso
GADISTFILES=	${GUESTADDITIONS}:guestadditions
RESTRICTED=	for personal use only
RESTRICTED_FILES=	${GUESTADDITIONS}
FETCH_ARGS=	-pRr
PLIST_SUB+=	GUESTADDITIONS=""
.else
PLIST_SUB+=	GUESTADDITIONS="@comment "
.endif

.if ${PORT_OPTIONS:MDEBUG}
KMK_FLAGS+=	BUILD_TYPE=debug
KMK_BUILDTYPE=	debug
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
.else
CONFIGURE_ARGS+=--disable-dbus
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=--disable-pulse
.endif

.if ${PORT_OPTIONS:MVNC}
LIB_DEPENDS+=	vncserver.0:${PORTSDIR}/net/libvncserver
.endif

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MVDE}
RUN_DEPENDS+=	vde_switch:${PORTSDIR}/net/vde2
CONFIGURE_ARGS+=--enable-vde
.endif

.if ${PORT_OPTIONS:MWEBSERVICE}
BUILD_DEPENDS+=	soapcpp2:${PORTSDIR}/devel/gsoap
VBOX_WEB=	vboxwebsrv webtest
USE_RC_SUBR+=	vboxwebsrv
SUB_LIST+=	VBOXWSUSER=${VBOXWSUSER}
PLIST_SUB+=	WEB=""
.else
PLIST_SUB+=	WEB="@comment "
.endif

.if ${ARCH} == i386
KMK_ARCH=	freebsd.x86
PLIST_SUB+=	I386=""
.else
KMK_ARCH=	freebsd.${ARCH}
PLIST_SUB+=	I386="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900012
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-include-iprt-string.h
.endif

.if ${OSVERSION} > 900020 || ${OSVERSION} < 900000 && ${OSVERSION} > 801500
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
	@${ECHO} 'VBOX_WITH_RUNPATH = ${PREFIX}/lib/virtualbox' >> ${WRKSRC}/LocalConfig.kmk
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
	@${ECHO} 'VBOX_WITH_VNC = 1' >> ${WRKSRC}/LocalConfig.kmk
.endif
.if ${OSVERSION} < 800069
	@${ECHO} 'VBOX_WITH_USB=' >> ${WRKSRC}/LocalConfig.kmk
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
.for f in VBoxManage VBoxNetAdpCtl VBoxNetDHCP VBoxSVC VBoxXPCOMIPCD ${VBOX_FRONTENDS} ${VBOX_WEB}
	${INSTALL_PROGRAM} ${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/${f} ${PREFIX}/lib/virtualbox/
	${LN} -sf ${PREFIX}/lib/virtualbox/${f} ${PREFIX}/bin/
.endfor

.for f in VBoxNetAdpCtl VBoxNetDHCP ${VBOX_FRONTENDS}
	${CHMOD} 4511 ${PREFIX}/lib/virtualbox/${f}
.endfor

.for f in VBoxManage VBoxSVC VBoxXPCOMIPCD VBoxExtPackHelperApp 
	${CHMOD} 0711 ${PREFIX}/lib/virtualbox/${f}
.endfor

.if ${PORT_OPTIONS:MWEBSERVICE}
	${MKDIR} -p ${DATADIR}/sdk/bindings/webservice
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
.for f in VBoxManage VBoxNetDHCP VBoxSVC VBoxXPCOMIPCD VBoxExtPackHelperApp ${VBOX_FRONTENDS}
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
