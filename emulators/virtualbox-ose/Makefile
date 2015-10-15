# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	virtualbox-ose
DISTVERSION=	4.3.30
CATEGORIES=	emulators
MASTER_SITES=	http://download.virtualbox.org/virtualbox/${DISTVERSION}/ \
		http://tmp.chruetertee.ch/ \
		http://disasterarea.chruetertee.ch/ \
		http://download.virtualbox.org/virtualbox/${VBOX_GUEST_VER}/:guestadditions
DISTFILES=	VirtualBox-${DISTVERSION}${EXTRACT_SUFX} ${GADISTFILES}
EXTRACT_ONLY=	VirtualBox-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	General-purpose full virtualizer for x86 hardware

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		kmk:${PORTSDIR}/devel/kBuild \
		gtar:${PORTSDIR}/archivers/gtar \
		cdrecord:${PORTSDIR}/sysutils/cdrtools
LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libxslt.so:${PORTSDIR}/textproc/libxslt \
		libcurl.so:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	${LOCALBASE}/etc/rc.d/vboxnet:${PORTSDIR}/emulators/virtualbox-ose-kmod \
		cdrecord:${PORTSDIR}/sysutils/cdrtools

CPE_VENDOR=	oracle
CPE_PRODUCT=	vm_virtualbox

WRKSRC=		${WRKDIR}/VirtualBox-${PORTVERSION}
ONLY_FOR_ARCHS=	i386 amd64
USES=		compiler cpe iconv pkgconfig tar:bzip2
USE_GNOME=	libidl
USE_LDCONFIG=	${VBOX_DIR}
USE_OPENSSL=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-java --passive-mesa
CONFIGURE_ARGS+=	--with-gcc="${CC}" --with-g++="${CXX}"

CONFLICTS_INSTALL=	virtualbox-ose-additions-4* \
			virtualbox-ose-additions-devel-4* \
			virtualbox-ose-devel-4* \
			virtualbox-ose-legacy-4*

VBOXUSER?=	vboxusers
VBOXWSUSER?=	vboxusers
VBOXGROUP?=	vboxusers
USERS=		${VBOXUSER}
GROUPS=		${VBOXGROUP}
VBOX_DIR=	${PREFIX}/lib/virtualbox
VBOX_LINKS=	VBoxVRDP
VBOX_PROGS=	VBoxAutostart VBoxBalloonCtrl VBoxHeadless VBoxManage
VBOX_UTILS=	VBoxExtPackHelperApp VBoxNetAdpCtl VBoxNetDHCP VBoxSVC \
		VBoxXPCOMIPCD

VBOX_GUEST_VER=	${PORTVERSION}

OPTIONS_DEFINE=	DBUS DEBUG GUESTADDITIONS MANUAL NLS PULSEAUDIO PYTHON \
		QT4 UDPTUNNEL VDE VNC VPX WEBSERVICE X11
OPTIONS_DEFAULT=	DBUS PYTHON QT4 UDPTUNNEL VNC WEBSERVICE X11
OPTIONS_SUB=	yes

DEBUG_DESC=	Debug symbols, additional logs and assertions
GUESTADDITIONS_DESC=	Build with Guest Additions
MANUAL_DESC=	Build with user manual
QT4_DESC=	Build with QT4 Frontend
UDPTUNNEL_DESC=	Build with UDP tunnel support
VDE_DESC=	Build with VDE support
VNC_DESC=	Build with VNC support
VPX_DESC=	Use vpx for video capturing
WEBSERVICE_DESC=	Build Webservice

DBUS_LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
VNC_LIB_DEPENDS=	libvncserver.so:${PORTSDIR}/net/libvncserver
VPX_LIB_DEPENDS=	libvpx.so:${PORTSDIR}/multimedia/libvpx

VDE_RUN_DEPENDS=	vde_switch:${PORTSDIR}/net/vde2

DBUS_CONFIGURE_OFF=	--disable-dbus
DEBUG_CONFIGURE_ON=	--build-debug
MANUAL_CONFIGURE_OFF=	--disable-docs
PULSEAUDIO_CONFIGURE_OFF=	--disable-pulse
PYTHON_CONFIGURE_OFF=	--disable-python
QT4_CONFIGURE_OFF=	--disable-qt4
UDPTUNNEL_CONFIGURE_OFF=	--disable-udptunnel
VDE_CONFIGURE_ON=	--enable-vde
VNC_CONFIGURE_ON=	--enable-vnc
VPX_CONFIGURE_OFF=	--disable-libvpx
X11_CONFIGURE_OFF=	--build-headless

# bmake doesn't know about unsetenv=true
.if defined(.PARSEDIR)
ENV=
.export ENV
.else
.SHELL:		path="/bin/sh" unsetenv=true
.endif

PLIST_SUB+=	GUEST_VER=${VBOX_GUEST_VER} \
		PYTHON_VER=${PYTHON_VER} \
		PYTHON_VERU=${PYTHON_VER:S/./_/} \
		VBOXGROUP=${VBOXGROUP}
SUB_LIST+=	VBOXDIR=${VBOX_DIR} \
		VBOXGROUP=${VBOXGROUP} \
		VBOXUSER=${VBOXUSER} \
		VBOXWSUSER=${VBOXWSUSER}
USE_RC_SUBR+=	vboxheadless vboxwatchdog

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MQT4) && !empty(PORT_OPTIONS:MNLS)
BROKEN=		NLS support requires QT4 frontend. Run 'make config' again!
.endif

.if empty(PORT_OPTIONS:MX11) && !empty(PORT_OPTIONS:MQT4)
BROKEN=		QT4 frontend requires X11 support. Run 'make config' again!
.endif

.if ${PORT_OPTIONS:MDEBUG}
KMK_BUILDTYPE=	debug
.else
KMK_BUILDTYPE=	release
.endif

.if ${PORT_OPTIONS:MGUESTADDITIONS}
GUESTADDITIONS=	VBoxGuestAdditions_${VBOX_GUEST_VER}.iso
GADISTFILES=	${GUESTADDITIONS}:guestadditions
RESTRICTED=	for personal use only
RESTRICTED_FILES=	${GUESTADDITIONS}
.endif

.if ${PORT_OPTIONS:MMANUAL}
USE_TEX=	dvipsk:build formats:build
.endif

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python:2
USE_PYTHON=	distutils noegginfo
PYDISTUTILS_PKGNAME=	vboxapi
PYDISTUTILS_PKGVERSION=	1.0
.else
USES+=		python:build
.endif

.if ${PORT_OPTIONS:MQT4}
QT_NONSTANDARD=	yes
USE_QT4=	linguist_build moc_build rcc_build uic_build
USE_QT4+=	gui network opengl
INSTALLS_ICONS=	yes
VBOX_PROGS+=	VirtualBox
VBOX_UTILS+=	VBoxTestOGL
VBOX_WITH_QT4=	1
.else
VBOX_WITH_QT4=
.endif

.if ${PORT_OPTIONS:MWEBSERVICE}
BUILD_DEPENDS+=	soapcpp2:${PORTSDIR}/devel/gsoap
USE_RC_SUBR+=	vboxwebsrv
VBOX_LINKS+=	vboxwebsrv
VBOX_UTILS+=	vboxwebsrv webtest
.endif

.if ${PORT_OPTIONS:MX11}
USE_SDL=	sdl
USE_XORG=	xcursor xmu inputproto xinerama
VBOX_PROGS+=	VBoxSDL
.endif

.if ${PORT_OPTIONS:MPYTHON} || ${PORT_OPTIONS:MWEBSERVICE}
PLIST_SUB+=	SDK=""
.else
PLIST_SUB+=	SDK="@comment "
.endif

.if ${ARCH} == i386
KMK_ARCH=	freebsd.x86
PLIST_SUB+=	I386=""
.else
KMK_ARCH=	freebsd.${ARCH}
PLIST_SUB+=	I386="@comment "
.endif

PLIST_SUB+=	ARCH="${KMK_ARCH}"

KMK_BUILDDIR=	${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}
KMK_CONFIG=	VBOX_LIBPATH_X11=${LOCALBASE} VBOX_FREEBSD_SRC=${SRC_BASE}/sys
KMK_FLAGS=	-j${MAKE_JOBS_NUMBER}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
PATCH_DEPENDS+=	${LOCALBASE}/share/kBuild/tools/GXX3.kmk:${PORTSDIR}/devel/kBuild
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-Config.kmk \
		${PATCHDIR}/extrapatch-src-VBox-Devices-PC-ipxe-Makefile.kmk \
		${PATCHDIR}/extrapatch-src-recompiler-Makefile.kmk
.endif

.if !defined(WITH_OPENSSL_BASE)
CONFIGURE_ARGS+=	--with-openssl-dir="${OPENSSLBASE}"
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
	@${ECHO} 'VBOX_PATH_APP_PRIVATE_ARCH = ${VBOX_DIR}' > \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_SHARED_LIBS = ${VBOX_DIR}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_RUNPATH = ${VBOX_DIR}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_APP_PRIVATE = ${DATADIR}' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_APP_DOCS = ${DOCSDIR}' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_INSTALLER = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_VBOXDRV =' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_TESTCASES =' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'SDK_VBOX_LIBPNG_INCS = ${PREFIX}/include/libpng' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'SDK_VBOX_LIBPNG_LIBS = png' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_ADDITIONS =' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_DRAG_AND_DROP = ${VBOX_WITH_QT4}' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_X11_ADDITIONS =' >> ${WRKSRC}/LocalConfig.kmk
.if ${PORT_OPTIONS:MWEBSERVICE}
	@${ECHO} 'VBOX_WITH_WEBSERVICES = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_GSOAP_INSTALLED = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_GSOAP = ${PREFIX}/lib/gsoap' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_GSOAP_BIN = ${PREFIX}/bin' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_GSOAP_IMPORT = ${PREFIX}/share/gsoap/import' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_GCC_PEDANTIC_CXX = -Wshadow $(VBOX_GCC_WARN) -Wno-long-long' >> ${WRKSRC}/LocalConfig.kmk
.endif
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e 's| -finline-limit=8000||' \
	    -e 's| -mpreferred-stack-boundary=2||' ${WRKSRC}/Config.kmk
	@${REINPLACE_CMD} -e 's| -fpermissive||' ${WRKSRC}/Config.kmk ${WRKSRC}/src/VBox/Main/webservice/Makefile.kmk
	@${ECHO} 'VBOX_GCC_Wno-unused-parameter = -Wno-unused-parameter' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'TOOL_VBoxGccFreeBSD_LD = ${CXX}' >> ${WRKSRC}/LocalConfig.kmk
	@${SED} -e 's|GXX3|VBoxGccFreeBSD|g' ${LOCALBASE}/share/kBuild/tools/GXX3.kmk > ${WRKSRC}/tools/kBuildTools/VBoxGccFreeBSD.kmk
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
	@${REINPLACE_CMD} -e 's|/usr/local/lib/virtualbox|${VBOX_DIR}|' \
	    -e 's|/usr/local|${PREFIX}|' \
	    ${WRKSRC}/src/VBox/Installer/freebsd/VBox.sh

do-build:
	cd ${WRKSRC} && \
	    ${SH} -c '. env.sh && ${KMK_CONFIG} ${LOCALBASE}/bin/kmk ${KMK_FLAGS}'
.if ${PORT_OPTIONS:MPYTHON}
	${PYTHON_CMD} -mcompileall ${KMK_BUILDDIR}/bin/sdk/bindings/xpcom/python/xpcom
.endif

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${KMK_BUILDDIR}/bin/sdk/bindings/xpcom && ${COPYTREE_SHARE} "idl samples" ${STAGEDIR}${DATADIR}

	${MKDIR} ${STAGEDIR}${PREFIX}/include/virtualbox
	cd ${KMK_BUILDDIR}/bin/sdk/bindings/xpcom/include && ${COPYTREE_SHARE} "*" ${STAGEDIR}${PREFIX}/include/virtualbox

	${MKDIR} ${STAGEDIR}${VBOX_DIR}
	cd ${KMK_BUILDDIR}/bin && ${COPYTREE_SHARE} \
	    "*.so *.gc *.r0 *.fd components" ${STAGEDIR}${VBOX_DIR}
	${LN} -sf ${DATADIR}/sdk ${STAGEDIR}${VBOX_DIR}

	${INSTALL_SCRIPT} ${WRKSRC}/src/VBox/Installer/freebsd/VBox.sh \
	    ${STAGEDIR}${VBOX_DIR}
.for f in ${VBOX_PROGS} ${VBOX_UTILS}
	${INSTALL_PROGRAM} ${KMK_BUILDDIR}/bin/${f} ${STAGEDIR}${VBOX_DIR}
.endfor
.for f in ${VBOX_PROGS} ${VBOX_LINKS}
	${LN} -sf ${VBOX_DIR}/VBox.sh ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
.for f in ${VBOX_PROGS}
	${LN} -sf ${VBOX_DIR}/VBox.sh ${STAGEDIR}${PREFIX}/bin/${f:tl}
.endfor

.if ${PORT_OPTIONS:MGUESTADDITIONS}
	${MKDIR} ${STAGEDIR}${VBOX_DIR}/additions
	${INSTALL_DATA} ${DISTDIR}/${GUESTADDITIONS} \
	    ${STAGEDIR}${VBOX_DIR}/additions/
	${LN} -sf ${VBOX_DIR}/additions/${GUESTADDITIONS} \
	    ${STAGEDIR}${VBOX_DIR}/additions/VBoxGuestAdditions.iso
.endif

.if ${PORT_OPTIONS:MMANUAL}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${KMK_BUILDDIR}/bin/UserManual*.pdf ${STAGEDIR}${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MNLS}
	cd ${KMK_BUILDDIR}/obj/VirtualBox/qtnls && ${COPYTREE_SHARE} "*.qm" ${STAGEDIR}${DATADIR}/nls
.endif

.if ${PORT_OPTIONS:MPYTHON}
	cd ${KMK_BUILDDIR}/bin/sdk/installer && \
	    ${SETENV} VBOX_INSTALL_PATH="${VBOX_DIR}" \
	    ${PYTHON_CMD} vboxapisetup.py install --root=${STAGEDIR}

	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/xpcom
	cd ${KMK_BUILDDIR}/bin/sdk/bindings/xpcom/python/xpcom && \
	    ${COPYTREE_SHARE} "*" ${STAGEDIR}${PYTHON_SITELIBDIR}/xpcom
	@${MKDIR} ${STAGEDIR}${DATADIR}/sdk/bindings/xpcom/python
	${LN} -sf ${PYTHON_SITELIBDIR}/xpcom \
	    ${STAGEDIR}${DATADIR}/sdk/bindings/xpcom/python
.endif

.if ${PORT_OPTIONS:MQT4}
	${INSTALL_DATA} ${WRKSRC}/src/VBox/Frontends/VirtualBox/images/OSE/VirtualBox_48px.png ${STAGEDIR}${PREFIX}/share/pixmaps/VBox.png
	${INSTALL_DATA} ${WRKSRC}/src/VBox/Installer/freebsd/virtualbox.desktop ${STAGEDIR}${PREFIX}/share/applications/virtualbox.desktop
.endif

.if ${PORT_OPTIONS:MVNC}
	${MKDIR} ${STAGEDIR}${VBOX_DIR}/ExtensionPacks/VNC/${KMK_ARCH}
	${INSTALL_DATA} ${KMK_BUILDDIR}/bin/ExtensionPacks/VNC/ExtPack* \
	    ${STAGEDIR}${VBOX_DIR}/ExtensionPacks/VNC/
	${INSTALL_LIB} ${KMK_BUILDDIR}/bin/ExtensionPacks/VNC/${KMK_ARCH}/* \
	    ${STAGEDIR}${VBOX_DIR}/ExtensionPacks/VNC/${KMK_ARCH}/
.endif

.if ${PORT_OPTIONS:MWEBSERVICE}
	${MKDIR} ${STAGEDIR}${DATADIR}/sdk/bindings/webservice
	${INSTALL_DATA} ${KMK_BUILDDIR}/obj/webservice/vboxweb.wsdl \
	    ${STAGEDIR}${DATADIR}/sdk/bindings/webservice/
.endif

.include <bsd.port.post.mk>
