PORTNAME=	virtualbox-ose
DISTVERSION=	7.1.12
CATEGORIES=	emulators
MASTER_SITES=	https://download.virtualbox.org/virtualbox/${DISTVERSION}/
PKGNAMESUFFIX=	-kmod-71
DISTNAME=	VirtualBox-${DISTVERSION}

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	VirtualBox kernel module for FreeBSD
WWW=		https://www.virtualbox.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	kmk:devel/kBuild

USES=		cpe compiler:c++17-lang kmod tar:bzip2
CPE_VENDOR=	oracle
CPE_PRODUCT=	vm_virtualbox
USE_RC_SUBR=	vboxnet

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--build-headless
CONFIGURE_ARGS+=	--disable-alsa \
			--disable-dbus \
			--disable-docs \
			--disable-libvpx \
			--disable-pulse \
			--disable-python \
			--disable-sdl-ttf \
			--disable-xpcom
CONFIGURE_ARGS+=	--nofatal --with-gcc="${CC}" --with-g++="${CXX}"

CONFLICTS_INSTALL=	virtualbox-ose-kmod-legacy \
			virtualbox-ose-kmod \
			virtualbox-ose-kmod-70

PATCHDIR=		${.CURDIR}/../${PORTNAME}-71/files
PORTSCOUT=		limit:^7\.1\.
SUB_FILES=		pkg-message
SUB_LIST=		OPSYS=${OPSYS} OSREL=${OSREL}

WRKSRC=		${WRKDIR}/VirtualBox-${DISTVERSION}

OPTIONS_DEFINE=		DEBUG INVARIANTS VIMAGE
OPTIONS_DEFAULT=	VIMAGE
OPTIONS_SUB=		yes
DEBUG_DESC=		Debug symbols, additional logs and assertions
INVARIANTS_DESC=	Use if kernel is compiled with INVARIANTS option
VIMAGE_DESC=		VIMAGE virtual networking support
INVARIANTS_CFLAGS=	-DINVARIANTS

.include <bsd.port.options.mk>

VBOX_BIN=	${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/src
VBOX_KMODS=	vboxdrv \
		vboxnetadp \
		vboxnetflt

BUILD_WRKSRC=	${VBOX_BIN}

KMK_BUILDTYPE=	release
KMK_CONFIG=	VBOX_LIBPATH_X11=${LOCALBASE} VBOX_FREEBSD_SRC=${SRC_BASE}/sys
KMK_FLAGS=	HostDrivers-scripts vboxdrv-src VBoxNetFlt-src VBoxNetAdp-src

.if ${PORT_OPTIONS:MDEBUG}
KMK_FLAGS+=	BUILD_TYPE=debug
KMK_BUILDTYPE=	debug
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-Config.kmk \
		${PATCHDIR}/extrapatch-src-VBox-HostDrivers-Support-freebsd-Makefile
MAKE_ARGS+=	DEBUG_FLAGS="-O1 -g"
.endif

.if ${ARCH} == i386
KMK_ARCH=	freebsd.x86
.else
KMK_ARCH=	freebsd.${ARCH}
.endif

.include <bsd.port.pre.mk>

SYMBOLSUFFIX=	debug
PLIST_SUB+=	SYMBOLSUFFIX=${SYMBOLSUFFIX}

post-patch:
	@${ECHO_CMD} 'VBOX_WITH_VBOXDRV = 1' > ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_WITH_NETFLT = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_WITH_NETADP = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO_CMD} 'VBOX_WITH_ADDITIONS =' >> ${WRKSRC}/LocalConfig.kmk
.if ${PORT_OPTIONS:MVIMAGE}
	@${ECHO_CMD} 'VBOX_WITH_NETFLT_VIMAGE = 1' >> ${WRKSRC}/LocalConfig.kmk
.endif
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g; s|which \$$\*|which \$$1|g' \
	    ${WRKSRC}/Config.kmk ${WRKSRC}/configure
	@${REINPLACE_CMD} \
	    -e 's|\$$KBUILDDIR_BIN/kmk_sed|${LOCALBASE}/bin/kmk_sed|g' \
	    ${WRKSRC}/configure

pre-build:
	cd ${WRKSRC}/src/VBox/HostDrivers && ${SH} -c \
	    '. ${WRKSRC}/env.sh && ${KMK_CONFIG} ${LOCALBASE}/bin/kmk ${KMK_FLAGS}'

do-install:
	${MKDIR} ${STAGEDIR}${KMODDIR}
.for i in ${VBOX_KMODS}
	${INSTALL_KLD} ${VBOX_BIN}/${i}/${i}.ko ${STAGEDIR}${KMODDIR}
.if ${PORT_OPTIONS:MDEBUG}
	${INSTALL_KLD} ${VBOX_BIN}/${i}/${i}.ko.${SYMBOLSUFFIX} ${STAGEDIR}${KMODDIR}
.endif
.endfor

.include <bsd.port.post.mk>
