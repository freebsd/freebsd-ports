# New ports collection makefile for:	virtualbox-ose-kmod
# Date created:		2009-09-21
# Whom:			Bernhard Froehlich <decke@bluelife.at>
#
# $FreeBSD$
#

PORTNAME=	virtualbox-ose
DISTVERSION=	3.2.6
CATEGORIES=	emulators kld
MASTER_SITES=	http://tmp.chruetertee.ch/ \
		http://freebsd.unixfreunde.de/sources/ \
		http://disasterarea.chruetertee.ch/ \
		http://mirror.4bit.ws/
PKGNAMESUFFIX=	-kmod
DISTNAME=	VirtualBox-${DISTVERSION}-OSE

MAINTAINER=	vbox@FreeBSD.org
COMMENT=	VirtualBox kernel module for FreeBSD

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		as86:${PORTSDIR}/devel/dev86 \
		kmk:${PORTSDIR}/devel/kBuild

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}
WRKSRC=		${WRKDIR}/VirtualBox-${PORTVERSION}_OSE
USE_RC_SUBR=	vboxnet
ONLY_FOR_ARCHS=	i386 amd64
USE_BZIP2=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gcc="${CC}" --with-g++="${CXX}" --nofatal \
		--disable-xpcom --disable-sdl-ttf --disable-pulse \
		--disable-alsa --disable-dbus --disable-python \
		--build-headless

CONFLICTS=	bcc-[0-9]* virtualbox-ose-kmod-devel-3*

OPTIONS=	DEBUG "Build with debugging symbols" off

.include <bsd.port.options.mk>

PLIST_SUB+=	KMODDIR=${KMODDIR:C,^/,,}

KMODDIR=	/boot/modules
SRC_BASE?=	/usr/src

VBOX_BIN=	${WRKSRC}/out/${KMK_ARCH}/${KMK_BUILDTYPE}/bin/src

KMK_BUILDTYPE=	release
KMK_CONFIG=	VBOX_LIBPATH_X11=${LOCALBASE} VBOX_FREEBSD_SRC=${SRC_BASE}/sys
KMK_FLAGS=	HostDrivers-src vboxdrv-mod VBoxNetFlt-src VBoxNetAdp-src

.if defined(WITH_DEBUG)
KMK_FLAGS+=	BUILD_TYPE=debug
KMK_BUILDTYPE=	debug
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

post-patch:
	@${ECHO} 'VBOX_WITH_VBOXDRV = 1' > ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_NETFLT = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_NETADP = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_ADDITIONS =' >> ${WRKSRC}/LocalConfig.kmk
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Config.kmk \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\$$KBUILDDIR_BIN/kmk_sed|${PREFIX}/bin/kmk_sed|g' ${WRKSRC}/configure

pre-build:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/env.sh

do-build:
	cd ${WRKSRC} && ${SH} env.sh && cd ${WRKSRC}/src/VBox/HostDrivers && ${KMK_CONFIG} ${LOCALBASE}/bin/kmk ${KMK_FLAGS}
	cd ${VBOX_BIN} && make SYSDIR=${SRC_BASE}/sys

do-install:
	${MKDIR} ${KMODDIR}
	${INSTALL_KLD} ${VBOX_BIN}/vboxdrv/vboxdrv.ko ${KMODDIR}
	${INSTALL_KLD} ${VBOX_BIN}/vboxnetadp/vboxnetadp.ko ${KMODDIR}
	${INSTALL_KLD} ${VBOX_BIN}/vboxnetflt/vboxnetflt.ko ${KMODDIR}
	@/usr/sbin/kldxref ${KMODDIR}

.include <bsd.port.post.mk>
