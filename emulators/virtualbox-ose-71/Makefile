PORTNAME=	virtualbox-ose
DISTVERSION=	7.1.10
PORTREVISION?=	2
CATEGORIES=	emulators
MASTER_SITES=	https://download.virtualbox.org/virtualbox/${DISTVERSION}/:src \
		LOCAL/vvd:docs
PKGNAMESUFFIX?=	-71
DISTFILES=	VirtualBox-${DISTVERSION}${EXTRACT_SUFX}:src \
		VirtualBox-docs-${DISTVERSION}${EXTRACT_SUFX}:docs
EXTRACT_ONLY=	VirtualBox-${DISTVERSION}${EXTRACT_SUFX} \
		VirtualBox-docs-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	General-purpose full virtualizer for x86 hardware
WWW=		https://www.virtualbox.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	gtar:archivers/gtar \
		kmk:devel/kBuild \
		yasm:devel/yasm \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libpng.so:graphics/png \
		libcurl.so:ftp/curl
RUN_DEPENDS=	${LOCALBASE}/etc/rc.d/vboxnet:emulators/virtualbox-ose-kmod-71

USES=		compiler:c++17-lang cpe gnome iconv pkgconfig qt:6 ssl tar:bzip2
CPE_VENDOR=	oracle
CPE_PRODUCT=	vm_virtualbox
USE_BINUTILS=	yes
USE_GNOME=	libxml2
USE_QT=		tools:build
USE_RC_SUBR=	vboxheadless vboxwatchdog

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--disable-java --passive-mesa --disable-docs
CONFIGURE_ARGS+=	--with-gcc="${CC}" --with-g++="${CXX}"

CONFLICTS_INSTALL=	virtualbox-ose-legacy \
			virtualbox-ose-nox11-legacy \
			virtualbox-ose \
			virtualbox-ose-nox11 \
			virtualbox-ose-70 \
			virtualbox-ose-nox11-70

PORTSCOUT=	limit:^7\.1\.
SUB_FILES=	pkg-message
SUB_LIST=	VBOXDIR=${VBOX_DIR} \
		VBOX_ETC=${VBOX_ETC} \
		VBOXGROUP=${VBOXGROUP} \
		VBOXUSER=${VBOXUSER} \
		VBOXWSUSER=${VBOXWSUSER}

WRKSRC=		${WRKDIR}/VirtualBox-${DISTVERSION}

VBOXUSER?=	vboxusers
VBOXWSUSER?=	vboxusers
VBOXGROUP?=	vboxusers
USERS=		${VBOXUSER}
GROUPS=		${VBOXGROUP}
VBOX_DIR=	${PREFIX}/${VBOX_DIR_REL}
VBOX_DIR_REL=	lib/virtualbox
VBOX_ETC=	${PREFIX}/etc/vbox
VBOX_LINKS=	VBoxVRDP
VBOX_PROGS=	VBoxAutostart VBoxBalloonCtrl VBoxBugReport VBoxHeadless \
		VBoxManage
VBOX_UTILS=	VBoxExtPackHelperApp VBoxNetAdpCtl VBoxNetDHCP VBoxNetNAT \
		VBoxSVC

PLIST_SUB=	GUEST_VER=${DISTVERSION} \
		PYTHON_VERU=${PYTHON_VER:S/./_/}${PYTHON_ABIVER} \
		VBOXGROUP=${VBOXGROUP}

SLAVE_PORT?=	no

OPTIONS_DEFINE=		AIO ALSA DBUS DEBUG DOCS GUESTADDITIONS NLS OGG PULSEAUDIO \
			PYTHON QT6 R0LOGGING UDPTUNNEL VBOXIMG VDE VNC VORBIS VPX \
			WEBSERVICE X11
OPTIONS_DEFAULT=	AIO DBUS QT6 UDPTUNNEL VNC WEBSERVICE X11
.if ${SLAVE_PORT} == no
OPTIONS_DEFAULT+=	PYTHON
.endif
# Since version 6.1.24 pulseaudio is broken at runtime, preventing
# virtual machines from starting if configured to use it.
OPTIONS_EXCLUDE+=	PULSEAUDIO
OPTIONS_SUB=		yes

AIO_DESC=		Enable Asyncronous IO support (check pkg-message)
DEBUG_DESC=		Debug symbols, additional logs and assertions
GUESTADDITIONS_DESC=	Build with Guest Additions
NLS_DESC=		Native language support (requires QT6)
OGG_DESC=		Use libogg from audio/libogg instead of bundled one
QT6_DESC=		Build with QT6 frontend (requires X11)
R0LOGGING_DESC=		Enable R0 logging (requires DEBUG)
UDPTUNNEL_DESC=		Build with UDP tunnel support
VBOXIMG_DESC=		Build vboximg-mount (requires fuse-libs)
VDE_DESC=		Build with VDE support
VNC_DESC=		Build with VNC support
VORBIS_DESC=		Use libvorbis from audio/libvorbis instead of bundled one
VPX_DESC=		Use libvpx for video recording
WEBSERVICE_DESC=	Build Webservice

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_OFF=	--disable-alsa
DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CONFIGURE_OFF=	--disable-dbus
DEBUG_CONFIGURE_ON=	--build-debug
NLS_IMPLIES=		QT6
OGG_LIB_DEPENDS=	libogg.so:audio/libogg
OGG_CONFIGURE_ON=	--enable-libogg
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=	--disable-pulse
PYTHON_USES=		python
PYTHON_USES_OFF=	python:build
PYTHON_USE=		PYTHON=distutils,noegginfo,noflavors
PYTHON_CONFIGURE_OFF=	--disable-python
PYTHON_VARS=		pydistutils_pkgname=vboxapi pydistutils_pkgversion=1.0
QT6_IMPLIES=		X11
QT6_USES=		gl qmake:no_env qt:6 xorg
QT6_USE=		QT=base,scxml,tools,translations \
			XORG=xcb GL=gl
QT6_CONFIGURE_OFF=	--disable-qt
R0LOGGING_IMPLIES=	DEBUG
UDPTUNNEL_CONFIGURE_OFF=	--disable-udptunnel
VBOXIMG_LIB_DEPENDS=	libfuse.so.2:filesystems/fusefs-libs
VDE_RUN_DEPENDS=	vde_switch:net/vde2
VDE_CONFIGURE_ON=	--enable-vde
VNC_LIB_DEPENDS=	libvncserver.so:net/libvncserver
VNC_CONFIGURE_ON=	--enable-vnc
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libvorbisenc.so:audio/libvorbis
VORBIS_CONFIGURE_ON=	--enable-libvorbis
VPX_LIB_DEPENDS=	libvpx.so:multimedia/libvpx
VPX_CONFIGURE_OFF=	--disable-libvpx
WEBSERVICE_BUILD_DEPENDS=	soapcpp2:devel/gsoap
X11_USES=		sdl xorg
X11_USE=		SDL=sdl XORG=x11,xcursor,xext,xinerama,xmu,xorgproto,xt
X11_CONFIGURE_OFF=	--build-headless

ENV=
.export ENV

.include <bsd.port.options.mk>

.if ${SLAVE_PORT} == no
CONFLICTS_INSTALL+=	virtualbox-ose-nox11-71
.else
CONFLICTS_INSTALL+=	virtualbox-ose-71
.endif

.if ${PORT_OPTIONS:MDEBUG}
KMK_BUILDTYPE=	debug
KMK_FLAGS+=	BUILD_TYPE=debug
.else
KMK_BUILDTYPE=	release
.endif

.if ${PORT_OPTIONS:MGUESTADDITIONS}
GUESTADDITIONS=			VBoxGuestAdditions_${DISTVERSION}.iso
DISTFILES+=			${GUESTADDITIONS}:src
LICENSE+=			Additions
LICENSE_COMB=			multi
LICENSE_NAME_Additions=		Guest Additions
LICENSE_PERMS_Additions=	auto-accept
LICENSE_DISTFILES_Additions=	${GUESTADDITIONS}
.endif

.if ${PORT_OPTIONS:MQT6}
PLIST_SUB+=	QT=""
VBOX_PROGS+=	VirtualBox VirtualBoxVM
VBOX_WITH_QT=	1
.else
PLIST_SUB+=	QT="@comment "
.endif

.if ${PORT_OPTIONS:MWEBSERVICE}
USE_RC_SUBR+=	vboxinit vboxwebsrv
VBOX_LINKS+=	vboxwebsrv
VBOX_UTILS+=	vboxwebsrv webtest
.endif

.if ${PORT_OPTIONS:MX11}
#VBOX_PROGS+=	VBoxSDL
.endif

.if ${PORT_OPTIONS:MPYTHON} || ${PORT_OPTIONS:MWEBSERVICE}
PLIST_SUB+=	SDK=""
.else
PLIST_SUB+=	SDK="@comment "
.endif

.if ${PORT_OPTIONS:MVBOXIMG}
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-vboximg-Config.kmk
VBOX_UTILS+=	vboximg-mount
PLIST_SUB+=	VBOXIMG=""
.else
PLIST_SUB+=	VBOXIMG="@comment "
.endif

KMK_ARCH=	freebsd.${ARCH}
PLIST_SUB+=	ARCH="${KMK_ARCH}"

KMK_BUILDDIR=	${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}
KMK_CONFIG=	VBOX_LIBPATH_X11=${LOCALBASE} VBOX_FREEBSD_SRC=${SRC_BASE}/sys VBOX_WITHOUT_DOCS=1 VBOX_GCC_std=-std=c++17
KMK_FLAGS+=	-j${MAKE_JOBS_NUMBER}

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
PATCH_DEPENDS+=	${LOCALBASE}/share/kBuild/tools/GXX3.kmk:devel/kBuild
.endif

.if ${PYTHON_MAJOR_VER} >= 3
PLIST_SUB+=	PYTHON_PYCDIR=/__pycache__/ \
		PYTHON_PYCEXT=.cpython-${PYTHON_SUFFIX}.pyc
.else
PLIST_SUB+=	PYTHON_PYCDIR=/ \
		PYTHON_PYCEXT=.pyc
.endif

.if ${SSL_DEFAULT} != base
CONFIGURE_ARGS+=	--with-openssl-dir="${OPENSSLBASE}"
.endif

post-patch:
	@${ECHO_CMD} 'VBOX_PATH_APP_PRIVATE_ARCH = ${VBOX_DIR}' > \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_PATH_DOCBOOK = ${DBKXSLDIR}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_PATH_DOCBOOK_DTD = ${DBKXMLDIR}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_PATH_SHARED_LIBS = ${VBOX_DIR}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	# Please keep this even if using Clang to avoid repeated regressions.
	# PR 245048
	@${ECHO_CMD} "VBOX_WITH_RUNPATH = ${_GCC_RUNTIME:D${_GCC_RUNTIME}\:}${VBOX_DIR}" >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_PATH_APP_PRIVATE = ${DATADIR}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_PATH_APP_DOCS = ${DOCSDIR}' >> ${WRKSRC}/LocalConfig.kmk
.if ${SSL_DEFAULT} != base
	@${ECHO_CMD} 'VBOX_WITH_ALT_HASH_CODE = 1' >> ${WRKSRC}/LocalConfig.kmk
.endif
	@${ECHO_CMD} 'VBOX_WITH_EXTPACK_VBOXDTRACE =' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_WITH_INSTALLER = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_WITH_VBOXDRV =' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_WITH_TESTCASES =' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'SDK_VBOX_LIBPNG_INCS = ${PREFIX}/include/libpng' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'SDK_VBOX_LIBPNG_LIBS = png' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_WITH_ADDITIONS =' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_WITH_DRAG_AND_DROP = ${VBOX_WITH_QT}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_WITH_DRAG_AND_DROP_GH = ${VBOX_WITH_QT}' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_WITH_VALIDATIONKIT =' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_WITH_X11_ADDITIONS =' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_BLD_PYTHON = ${LOCALBASE}/bin/${PYTHON_VERSION}' >> \
	    ${WRKSRC}/LocalConfig.kmk
.if ${PORT_OPTIONS:MR0LOGGING}
	@${ECHO_CMD} 'VBOX_WITH_R0_LOGGING = 1' >> ${WRKSRC}/LocalConfig.kmk
.endif
.if ${PORT_OPTIONS:MWEBSERVICE}
	@${ECHO_CMD} 'VBOX_WITH_WEBSERVICES = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_GSOAP_INSTALLED = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_PATH_GSOAP = ${PREFIX}/lib/gsoap' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_PATH_GSOAP_BIN = ${PREFIX}/bin' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_PATH_GSOAP_IMPORT = ${PREFIX}/share/gsoap/import' >> \
	    ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_GCC_PEDANTIC_CXX = -Wshadow $$(VBOX_GCC_WARN) -Wno-long-long' >> \
	    ${WRKSRC}/LocalConfig.kmk
.endif
.if empty(PORT_OPTIONS:MX11)
	@${ECHO} 'VBOX_WITH_VMSVGA3D =' >> ${WRKSRC}/LocalConfig.kmk
.endif
.if ${CHOSEN_COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e 's| -finline-limit=8000||' \
	    -e 's| -mpreferred-stack-boundary=2||' ${WRKSRC}/Config.kmk
	@${REINPLACE_CMD} -e 's| -fpermissive||' ${WRKSRC}/Config.kmk \
	    ${WRKSRC}/src/VBox/Main/webservice/Makefile.kmk
	@${ECHO_CMD} 'TOOL_VBoxGccFreeBSD_LD = ${CXX}' >> ${WRKSRC}/LocalConfig.kmk
	@${SED} -e 's|GXX3|VBoxGccFreeBSD|g' \
	    ${LOCALBASE}/share/kBuild/tools/GXX3.kmk > \
	    ${WRKSRC}/tools/kBuildTools/VBoxGccFreeBSD.kmk
.endif
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1500013
	@${ECHO_CMD} 'VBoxSVC_LDFLAGS.freebsd = -lsys' >> ${WRKSRC}/LocalConfig.kmk
.endif
	# Causes a "reinplace" QA warning with default LOCALBASE
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
	    ${WRKSRC}/Config.kmk ${WRKSRC}/configure \
	    ${WRKSRC}/kBuild/header.kmk ${WRKSRC}/kBuild/units/qt4.kmk \
	    ${WRKSRC}/kBuild/units/qt5.kmk ${WRKSRC}/kBuild/units/qt6.kmk ${WRKSRC}/kBuild/sdks/LIBSDL.kmk \
	    ${WRKSRC}/src/libs/xpcom18a4/python/gen_python_deps.py
	@${REINPLACE_CMD} \
	    -e 's|\$$KBUILDDIR_BIN/kmk_sed|${LOCALBASE}/bin/kmk_sed|g' \
	    -e 's|SUPPYTHONLIBS=.*|SUPPYTHONLIBS="${PYTHON_VERSION}${PYTHON_ABIVER}"|' \
	    ${WRKSRC}/configure
.if empty(ICONV_LIB)
	@${REINPLACE_CMD} -e 's|iconv||' ${WRKSRC}/Config.kmk \
	    ${WRKSRC}/src/VBox/Runtime/Makefile.kmk
	@${ECHO_CMD} 'VBOX_ICONV_DEFS = LIBICONV_PLUG' >> ${WRKSRC}/LocalConfig.kmk
.endif
	@${REINPLACE_CMD} -e 's|%%VBOX_DIR%%|${VBOX_DIR}|g' \
	    -e 's|%%VBOX_ETC%%|${VBOX_ETC}|g' \
	    -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    ${WRKSRC}/src/VBox/Installer/freebsd/VBox.sh
	@${REINPLACE_CMD} -e 's|%%VBOX_ETC%%|${VBOX_ETC}|g' \
	    ${WRKSRC}/src/VBox/HostDrivers/adpctl/VBoxNetAdpCtl.cpp
	@${REINPLACE_CMD} \
	    -e 's|^versions =.*|versions = ["${PYTHON_VER}${PYTHON_ABIVER}"]|' \
	    ${WRKSRC}/src/libs/xpcom18a4/python/gen_python_deps.py

post-patch-AIO-off:
	@${REINPLACE_CMD} 's|r3/freebsd/fileaio-freebsd.cpp|r3/posix/fileaio-posix.cpp|' \
		${WRKSRC}/src/VBox/Runtime/Makefile.kmk

do-build:
	cd ${WRKSRC} && ${SH} -c '. ${WRKSRC}/env.sh && \
	    ${SETENV} ${MAKE_ENV} ${KMK_CONFIG} ${LOCALBASE}/bin/kmk ${KMK_FLAGS}'
.if ${PORT_OPTIONS:MPYTHON}
	${PYTHON_CMD} -mcompileall \
	    ${KMK_BUILDDIR}/bin/sdk/bindings/xpcom/python/xpcom
.endif

do-install:
.if ${PORT_OPTIONS:MPYTHON} || ${PORT_OPTIONS:MWEBSERVICE}
	${MKDIR} ${STAGEDIR}${DATADIR}/sdk
.endif
	cd ${KMK_BUILDDIR}/bin/sdk/bindings/xpcom && \
	    ${COPYTREE_SHARE} "idl samples" ${STAGEDIR}${DATADIR}

	${MKDIR} ${STAGEDIR}${PREFIX}/include/virtualbox
	cd ${KMK_BUILDDIR}/bin/sdk/bindings/xpcom/include && \
	    ${COPYTREE_SHARE} "*" ${STAGEDIR}${PREFIX}/include/virtualbox

	${MKDIR} ${STAGEDIR}${VBOX_DIR}
	cd ${KMK_BUILDDIR}/bin && ${COPYTREE_SHARE} \
	    "*.fd *.r0 *.so components" ${STAGEDIR}${VBOX_DIR}
.if ${PORT_OPTIONS:MPYTHON} || ${PORT_OPTIONS:MWEBSERVICE}
	${RLN} ${STAGEDIR}${DATADIR}/sdk ${STAGEDIR}${VBOX_DIR}
.endif

	${INSTALL_SCRIPT} ${WRKSRC}/src/VBox/Installer/freebsd/VBox.sh \
	    ${STAGEDIR}${VBOX_DIR}
.for f in ${VBOX_PROGS} ${VBOX_UTILS}
	${INSTALL_PROGRAM} ${KMK_BUILDDIR}/bin/${f} ${STAGEDIR}${VBOX_DIR}
.endfor
.for f in ${VBOX_PROGS} ${VBOX_LINKS}
	${LN} -fs ../${VBOX_DIR_REL}/VBox.sh ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
.for f in ${VBOX_PROGS}
	${LN} -fs ../${VBOX_DIR_REL}/VBox.sh ${STAGEDIR}${PREFIX}/bin/${f:tl}
.endfor

.if ${PORT_OPTIONS:MGUESTADDITIONS}
	${MKDIR} ${STAGEDIR}${VBOX_DIR}/additions
	${INSTALL_DATA} ${DISTDIR}/${GUESTADDITIONS} \
	    ${STAGEDIR}${VBOX_DIR}/additions/
	${RLN} ${STAGEDIR}${VBOX_DIR}/additions/${GUESTADDITIONS} \
	    ${STAGEDIR}${VBOX_DIR}/additions/VBoxGuestAdditions.iso
.endif

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/VirtualBox-docs-${DISTVERSION}/UserManual.pdf \
	    ${STAGEDIR}${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MNLS}
	cd ${KMK_BUILDDIR}/obj/VirtualBox/qtnls && \
	    ${COPYTREE_SHARE} "*.qm" ${STAGEDIR}${DATADIR}/nls
.endif

.if ${PORT_OPTIONS:MPYTHON}
	cd ${KMK_BUILDDIR}/bin/sdk/installer/python && \
	    ${SETENV} VBOX_INSTALL_PATH="${VBOX_DIR}" \
	    ${PYTHON_CMD} vboxapisetup.py install --root=${STAGEDIR}

	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/xpcom
	cd ${KMK_BUILDDIR}/bin/sdk/bindings/xpcom/python/xpcom && \
	    ${COPYTREE_SHARE} "*" ${STAGEDIR}${PYTHON_SITELIBDIR}/xpcom
	@${MKDIR} ${STAGEDIR}${DATADIR}/sdk/bindings/xpcom/python
	${RLN} ${STAGEDIR}${PYTHON_SITELIBDIR}/xpcom \
	    ${STAGEDIR}${DATADIR}/sdk/bindings/xpcom/python
.endif

.if ${PORT_OPTIONS:MQT6}
	${INSTALL_DATA} \
	    ${WRKSRC}/src/VBox/Frontends/VirtualBox/images/OSE/VirtualBox_48px.png \
	    ${STAGEDIR}${PREFIX}/share/pixmaps/VBox.png
	${INSTALL_DATA} \
	    ${FILESDIR}/virtualbox.desktop \
	    ${STAGEDIR}${PREFIX}/share/applications/virtualbox.desktop
.endif

.if ${PORT_OPTIONS:MVNC}
	${MKDIR} ${STAGEDIR}${VBOX_DIR}/ExtensionPacks/VNC/${KMK_ARCH}
	${INSTALL_DATA} ${KMK_BUILDDIR}/bin/ExtensionPacks/VNC/ExtPack* \
	    ${STAGEDIR}${VBOX_DIR}/ExtensionPacks/VNC/
	${INSTALL_LIB} ${KMK_BUILDDIR}/bin/ExtensionPacks/VNC/${KMK_ARCH}/* \
	    ${STAGEDIR}${VBOX_DIR}/ExtensionPacks/VNC/${KMK_ARCH}/
.endif

.if ${PORT_OPTIONS:MVBOXIMG}
	${LN} -fs ../${VBOX_DIR_REL}/vboximg-mount ${STAGEDIR}${PREFIX}/bin/
.endif

.if ${PORT_OPTIONS:MWEBSERVICE}
	${MKDIR} ${STAGEDIR}${DATADIR}/sdk/bindings/webservice
	${INSTALL_DATA} ${KMK_BUILDDIR}/obj/webservice/vboxweb.wsdl \
	    ${STAGEDIR}${DATADIR}/sdk/bindings/webservice/
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/virtualbox/*.so \
		${STAGEDIR}${PREFIX}/lib/virtualbox/components/*.so

.include <bsd.port.post.mk>
