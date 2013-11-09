# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	virtualbox-ose
DISTVERSION=	4.2.18
CATEGORIES=	emulators
MASTER_SITES=	http://download.virtualbox.org/virtualbox/${DISTVERSION}/ \
		http://tmp.chruetertee.ch/ \
		http://disasterarea.chruetertee.ch/
PKGNAMESUFFIX=	-kmod
DISTNAME=	VirtualBox-${DISTVERSION}

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	VirtualBox kernel module for FreeBSD

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		as86:${PORTSDIR}/devel/dev86 \
		kmk:${PORTSDIR}/devel/kBuild

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}
WRKSRC=		${WRKDIR}/VirtualBox-${PORTVERSION}
USE_RC_SUBR=	vboxnet
ONLY_FOR_ARCHS=	i386 amd64
FETCH_ARGS=	-pRr
USE_BZIP2=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gcc="${CC}" --with-g++="${CXX}" --nofatal \
		--disable-xpcom --disable-sdl-ttf --disable-pulse \
		--disable-alsa --disable-dbus --disable-python \
		--build-headless

CONFLICTS=	bcc-[0-9]*
CONFLICTS_INSTALL=	virtualbox-ose-kmod-devel-[3,4]* virtualbox-ose-kmod-legacy-[3,4]*

OPTIONS_DEFINE=	DEBUG VIMAGE
DEBUG_DESC=	Debug symbols, additional logs and assertions
VIMAGE_DESC=	VIMAGE virtual networking support

NO_STAGE=	yes

USES=		kmod
.include <bsd.port.options.mk>

VBOX_BIN=	${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/src

KMK_BUILDTYPE=	release
KMK_CONFIG=	VBOX_LIBPATH_X11=${LOCALBASE} VBOX_FREEBSD_SRC=${SRC_BASE}/sys
KMK_FLAGS=	HostDrivers-scripts vboxdrv-mod VBoxNetFlt-src VBoxNetAdp-src

MAKE_FLAGS=	SYSDIR=${SRC_BASE}/sys

.if ${PORT_OPTIONS:MDEBUG}
KMK_FLAGS+=	BUILD_TYPE=debug
KMK_BUILDTYPE=	debug
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-Config.kmk ${FILESDIR}/extrapatch-src-VBox-HostDrivers-Support-freebsd-Makefile
MAKE_FLAGS+=	DEBUG_FLAGS="-O1 -g"
PLIST_SUB+=	WITH_DEBUG=""
.else
PLIST_SUB+=	WITH_DEBUG="@comment "
.endif

.if ${ARCH} == i386
KMK_ARCH=	freebsd.x86
.else
KMK_ARCH=	freebsd.${ARCH}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 802000
BROKEN=		Does not compile on FreeBSD < 8.2
.endif

.if ${OSVERSION} < 800500 && !empty(PORT_OPTIONS:MVIMAGE)
IGNORE=		newer kernel is required to build with VIMAGE
.endif

post-patch:
	@${ECHO} 'VBOX_WITH_VBOXDRV = 1' > ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_NETFLT = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_NETADP = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_ADDITIONS =' >> ${WRKSRC}/LocalConfig.kmk
.if ${PORT_OPTIONS:MVIMAGE}
	@${ECHO} 'VBOX_WITH_NETFLT_VIMAGE = 1' >> ${WRKSRC}/LocalConfig.kmk
.endif
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Config.kmk \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\$$KBUILDDIR_BIN/kmk_sed|${LOCALBASE}/bin/kmk_sed|g' ${WRKSRC}/configure

pre-build:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/env.sh

do-build:
	cd ${WRKSRC} && ${SH} env.sh && cd ${WRKSRC}/src/VBox/HostDrivers && ${KMK_CONFIG} ${LOCALBASE}/bin/kmk ${KMK_FLAGS}
	cd ${VBOX_BIN} && make ${MAKE_FLAGS}

do-install:
	${INSTALL_KLD} ${VBOX_BIN}/vboxdrv/vboxdrv.ko ${KMODDIR}
	${INSTALL_KLD} ${VBOX_BIN}/vboxnetadp/vboxnetadp.ko ${KMODDIR}
	${INSTALL_KLD} ${VBOX_BIN}/vboxnetflt/vboxnetflt.ko ${KMODDIR}
.if ${PORT_OPTIONS:MDEBUG}
	${INSTALL_KLD} ${VBOX_BIN}/vboxdrv/vboxdrv.ko.symbols ${KMODDIR}
	${INSTALL_KLD} ${VBOX_BIN}/vboxnetadp/vboxnetadp.ko.symbols ${KMODDIR}
	${INSTALL_KLD} ${VBOX_BIN}/vboxnetflt/vboxnetflt.ko.symbols ${KMODDIR}
.endif

.include <bsd.port.post.mk>
