# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	virtualbox-ose
PORTVERSION=	5.0.26
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://download.virtualbox.org/virtualbox/${PORTVERSION}/
DISTFILES=	VirtualBox-${PORTVERSION}${EXTRACT_SUFX} ${GUESTADDITIONS}
EXTRACT_ONLY=	VirtualBox-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER?=	vbox@FreeBSD.org
COMMENT=	General-purpose full virtualizer for x86 hardware

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	yasm:devel/yasm \
		xsltproc:textproc/libxslt \
		kmk:devel/kBuild \
		gtar:archivers/gtar \
		cdrecord:sysutils/cdrtools
LIB_DEPENDS=	libpng.so:graphics/png \
		libxslt.so:textproc/libxslt \
		libcurl.so:ftp/curl
RUN_DEPENDS=	${LOCALBASE}/etc/rc.d/vboxnet:emulators/virtualbox-ose-kmod \
		cdrecord:sysutils/cdrtools

CPE_VENDOR=	oracle
CPE_PRODUCT=	vm_virtualbox

WRKSRC=		${WRKDIR}/VirtualBox-${PORTVERSION}
ONLY_FOR_ARCHS=	i386 amd64
USES=		compiler cpe iconv pkgconfig ssl tar:bzip2
USE_GNOME=	libidl libxml2

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-java --passive-mesa
CONFIGURE_ARGS+=	--with-gcc="${CC}" --with-g++="${CXX}"

CONFLICTS_INSTALL=	virtualbox-ose-additions-[4,5]* \
			virtualbox-ose-additions-devel-4* \
			virtualbox-ose-devel-4* \
			virtualbox-ose-legacy-4*

.if defined(LITE)
CONFIGURE_ARGS+=	--disable-alsa --disable-dbus --disable-docs \
			--disable-pulse --disable-qt4 --disable-libvpx \
			--build-headless
CONFLICTS_INSTALL+=	${PORTNAME}-[4,5]*
PKGNAMESUFFIX=		-lite
PLIST_SUB=		GUESTADDITIONS="@comment " MANUAL="@comment " \
			NLS="@comment " QT4="@comment " X11="@comment "
.else
CONFLICTS_INSTALL+=	${PORTNAME}-lite-[4,5]*
.endif

VBOXUSER?=	vboxusers
VBOXWSUSER?=	vboxusers
VBOXGROUP?=	vboxusers
USERS=		${VBOXUSER}
GROUPS=		${VBOXGROUP}
VBOX_DIR=	${PREFIX}/lib/virtualbox
VBOX_LINKS=	VBoxVRDP
VBOX_PROGS=	VBoxAutostart VBoxBalloonCtrl VBoxHeadless VBoxManage
VBOX_UTILS=	VBoxExtPackHelperApp VBoxNetAdpCtl VBoxNetDHCP VBoxNetNAT \
		VBoxSVC VBoxXPCOMIPCD

OPTIONS_DEFINE=		PYTHON R0LOGGING UDPTUNNEL VDE VNC WEBSERVICE
OPTIONS_DEFAULT=	UDPTUNNEL VNC
.if !defined(LITE)
OPTIONS_DEFINE+=	ALSA DBUS DEBUG GUESTADDITIONS MANUAL NLS PULSEAUDIO
OPTIONS_DEFINE+=	QT4 VPX X11
OPTIONS_DEFAULT+=	DBUS PYTHON QT4 WEBSERVICE X11
.endif
OPTIONS_SUB=	yes

DEBUG_DESC=	Debug symbols, additional logs and assertions
GUESTADDITIONS_DESC=	Build with Guest Additions
MANUAL_DESC=	Build with user manual
QT4_DESC=	Build with QT4 Frontend
R0LOGGING_DESC=	Enable R0 logging
UDPTUNNEL_DESC=	Build with UDP tunnel support
VDE_DESC=	Build with VDE support
VNC_DESC=	Build with VNC support
VPX_DESC=	Use vpx for video capturing
WEBSERVICE_DESC=	Build Webservice

MANUAL_BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.4/docbookx.dtd:textproc/docbook-xml
PYTHON_CONFIGURE_OFF=	--disable-python
UDPTUNNEL_CONFIGURE_OFF=	--disable-udptunnel
VDE_CONFIGURE_ON=	--enable-vde
VDE_RUN_DEPENDS=	vde_switch:net/vde2
VNC_CONFIGURE_ON=	--enable-vnc
VNC_LIB_DEPENDS=	libvncserver.so:net/libvncserver

.if !defined(LITE)
ALSA_CONFIGURE_OFF=	--disable-alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
DBUS_CONFIGURE_OFF=	--disable-dbus
DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DEBUG_CONFIGURE_ON=	--build-debug
MANUAL_CONFIGURE_OFF=	--disable-docs
PULSEAUDIO_CONFIGURE_OFF=	--disable-pulse
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
QT4_CONFIGURE_OFF=	--disable-qt4
VPX_CONFIGURE_OFF=	--disable-libvpx
VPX_LIB_DEPENDS=	libvpx.so:multimedia/libvpx
X11_CONFIGURE_OFF=	--build-headless
.endif

# bmake doesn't know about unsetenv=true
.if defined(.PARSEDIR)
ENV=
.export ENV
.else
.SHELL:		path="/bin/sh" unsetenv=true
.endif

PLIST_SUB+=	GUEST_VER=${PORTVERSION} \
		PYTHON_VER=${PYTHON_VER} \
		PYTHON_VERU=${PYTHON_VER:S/./_/} \
		VBOXGROUP=${VBOXGROUP}
SUB_LIST+=	VBOXDIR=${VBOX_DIR} \
		VBOXGROUP=${VBOXGROUP} \
		VBOXUSER=${VBOXUSER} \
		VBOXWSUSER=${VBOXWSUSER}
USE_RC_SUBR+=	vboxheadless vboxwatchdog

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS} && empty(PORT_OPTIONS:MQT4) && !defined(LITE)
BROKEN=		NLS support requires QT4 frontend. Run 'make config' again!
.endif

.if ${PORT_OPTIONS:MQT4} && empty(PORT_OPTIONS:MX11)
BROKEN=		QT4 frontend requires X11 support. Run 'make config' again!
.endif

.if ${PORT_OPTIONS:MDEBUG}
KMK_BUILDTYPE=	debug
KMK_FLAGS+=	BUILD_TYPE=debug
.else
KMK_BUILDTYPE=	release
.endif

.if ${PORT_OPTIONS:MR0LOGGING} && empty(PORT_OPTIONS:MDEBUG)
BROKEN=		R0 logging requires debug build
.endif

.if ${PORT_OPTIONS:MGUESTADDITIONS}
GUESTADDITIONS=	VBoxGuestAdditions_${PORTVERSION}.iso
RESTRICTED=	for personal use only
RESTRICTED_FILES=	${GUESTADDITIONS}
.endif

.if ${PORT_OPTIONS:MMANUAL}
DBKXMLDIR=	${LOCALBASE}/share/xml/docbook/4.4
DBKXSLDIR=	${LOCALBASE}/share/xsl/docbook
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
USE_GL=		gl
USE_QT4=	corelib gui linguist_build moc_build network
USE_QT4+=	opengl rcc_build uic_build
INSTALLS_ICONS=	yes
VBOX_PROGS+=	VirtualBox
VBOX_UTILS+=	VBoxTestOGL
VBOX_WITH_QT4=	1
.else
VBOX_WITH_QT4=
.endif

.if ${PORT_OPTIONS:MWEBSERVICE}
BUILD_DEPENDS+=	soapcpp2:devel/gsoap
USE_RC_SUBR+=	vboxwebsrv
VBOX_LINKS+=	vboxwebsrv
VBOX_UTILS+=	vboxwebsrv webtest
.endif

.if ${PORT_OPTIONS:MX11}
USE_SDL=	sdl
USE_XORG=	inputproto x11 xcursor xext xinerama xmu xt
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
KMK_FLAGS+=	-j${MAKE_JOBS_NUMBER}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
PATCH_DEPENDS+=	${LOCALBASE}/share/kBuild/tools/GXX3.kmk:devel/kBuild
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-Config.kmk \
		${PATCHDIR}/extrapatch-src-VBox-Devices-PC-ipxe-Makefile.kmk \
		${PATCHDIR}/extrapatch-src-recompiler-Makefile.kmk
.endif

.if ${SSL_DEFAULT} != base
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
	@${ECHO} 'TOOL_QT4_BIN_SUFF = -qt4' > ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_APP_PRIVATE_ARCH = ${VBOX_DIR}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_DOCBOOK = ${DBKXSLDIR}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_DOCBOOK_DTD = ${DBKXMLDIR}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_SHARED_LIBS = ${VBOX_DIR}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_RUNPATH = ${VBOX_DIR}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_APP_PRIVATE = ${DATADIR}' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_APP_DOCS = ${DOCSDIR}' >> ${WRKSRC}/LocalConfig.kmk
.if ${SSL_DEFAULT} != base
	@${ECHO} 'VBOX_WITH_ALT_HASH_CODE = 1' >> ${WRKSRC}/LocalConfig.kmk
.endif
	@${ECHO} 'VBOX_WITH_EXTPACK_VBOXDTRACE =' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_INSTALLER = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_VBOXDRV =' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_TESTCASES =' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'SDK_VBOX_LIBPNG_INCS = ${PREFIX}/include/libpng' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'SDK_VBOX_LIBPNG_LIBS = png' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_ADDITIONS =' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_DRAG_AND_DROP = ${VBOX_WITH_QT4}' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_DRAG_AND_DROP_GH = ${VBOX_WITH_QT4}' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_VALIDATIONKIT =' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_X11_ADDITIONS =' >> ${WRKSRC}/LocalConfig.kmk
.if ${PORT_OPTIONS:MWEBSERVICE}
	@${ECHO} 'VBOX_WITH_WEBSERVICES = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_GSOAP_INSTALLED = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_GSOAP = ${PREFIX}/lib/gsoap' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_GSOAP_BIN = ${PREFIX}/bin' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_GSOAP_IMPORT = ${PREFIX}/share/gsoap/import' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_GCC_PEDANTIC_CXX = -Wshadow $$(VBOX_GCC_WARN) -Wno-long-long' >> ${WRKSRC}/LocalConfig.kmk
.endif
.if ${PORT_OPTIONS:MR0LOGGING}
	@${ECHO} 'VBOX_WITH_R0_LOGGING = 1' >> ${WRKSRC}/LocalConfig.kmk
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
	@${REINPLACE_CMD} -e 's|iconv||' ${WRKSRC}/Config.kmk \
	    ${WRKSRC}/src/VBox/Runtime/Makefile.kmk
	@${ECHO} 'VBOX_ICONV_DEFS = LIBICONV_PLUG' >> ${WRKSRC}/LocalConfig.kmk
.endif
	@${REINPLACE_CMD} -e 's|/usr/local/lib/virtualbox|${VBOX_DIR}|' \
	    -e 's|/usr/local|${PREFIX}|' \
	    ${WRKSRC}/src/VBox/Installer/freebsd/VBox.sh

do-build:
	cd ${WRKSRC} && \
	    ${SH} -c '. ${WRKSRC}/env.sh && ${KMK_CONFIG} ${LOCALBASE}/bin/kmk ${KMK_FLAGS}'
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
	    "*.fd *.r0 *.rc *.so components" ${STAGEDIR}${VBOX_DIR}
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

.if ${PORT_OPTIONS:MNLS} && !defined(LITE)
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
