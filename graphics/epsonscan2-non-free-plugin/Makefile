PORTNAME=	epsonscan2-non-free-plugin
DISTVERSION=	6.6.40.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://download2.ebz.epson.net/${EPSONSCAN2}/common/rpm/x64/:amd64 \
		https://download2.ebz.epson.net/${EPSONSCAN2}/common/deb/arm/:armv7 \
		https://download2.ebz.epson.net/${EPSONSCAN2}/common/deb/arm/:armv7rasb \
		https://download2.ebz.epson.net/${EPSONSCAN2}/common/rpm/x86/:i386
DISTNAME=	${EPSONSCAN2}-bundle-${DISTVERSION}
DISTFILES_amd64=	${DISTNAME}.${DIST_SUFX}${EXTRACT_SUFX}:amd64
DISTFILES_armv7=	${DISTNAME}.${DIST_SUFX}${EXTRACT_SUFX}:armv7
DISTFILES_armv7rasb=	${DISTNAME:S,bundle,bundle-raspbian,}.${DIST_SUFX}${EXTRACT_SUFX}:armv7rasb
DISTFILES_i386=		${DISTNAME}.${DIST_SUFX}${EXTRACT_SUFX}:i386

MAINTAINER=	fbsd@opal.com
COMMENT=	Epson Scan 2 network interface non-free-plugin
WWW=		https://support.epson.net/linux/en/epsonscan2.php

LICENSE=	EPSON
LICENSE_NAME=	EPSON END USER SOFTWARE LICENSE AGREEMENT
LICENSE_FILE=	${WRKDIR}/usr/share/doc/${PORTNAME}-${EPSON_VERSION}-1/COPYING.EPSON
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

LEGAL_TEXT=	License does not permit public sharing or revenue earning, and restricts exports

ONLY_FOR_ARCHS=	amd64 armv7 armv7rasb i386

RUN_DEPENDS=	epsonscan2:graphics/epsonscan2 \
		linux_libusb-${LINUX_DEFAULT}>=13.1.0:devel/linux_libusb

USES=		linux
USE_LDCONFIG=	${LINUXBASE}/usr/${LINUX_LIB}/epsonscan2/libexec \
		${LINUXBASE}/usr/${LINUX_LIB}/epsonscan2/non-free-exec

EPSON_VERSION=	1.0.0.5
EPSONSCAN2=	${PORTNAME:S,-non-free-plugin,,}

LINUX_WRAPPERS=	ddeplugin \
		dtrplugin \
		es2intif \
		es2netif \
		fitplugin

NO_BUILD=	true

SUB_FILES=	pkg-message \
		${LINUX_WRAPPERS}

SUB_LIST+=	LINUXBASE=${LINUXBASE} \
		LINUX_LIB=${LINUX_LIB}

PLIST_SUB+=	LINUX_LIB=${LINUX_LIB} \
		LINUX_LIB_EXTRA=${LINUX_LIB_EXTRA}

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
DIST_FMT=	rpm
DIST_SUFX=	x86_64.${DIST_FMT}
LINUX_ARCH=	x86_64
LINUX_FMT=	rpm
LINUX_LIB=	lib64
LINUX_LIB_EXTRA=	"@comment "
.elif ${ARCH} == armv7 || ${ARCH} == armv7rasb
DIST_FMT=	deb
DIST_SUFX=	armv7l.${DIST_FMT}
LINUX_ARCH=	armhf
LINUX_FMT=	deb
LINUX_LIB=	lib/arm-linux-gnueabihf
LINUX_LIB_EXTRA=	""
.elif ${ARCH} == i386
DIST_FMT=	rpm
DIST_SUFX=	i686.${DIST_FMT}
LINUX_ARCH=	i686
LINUX_FMT=	rpm
LINUX_LIB=	lib
LINUX_LIB_EXTRA=	"@comment "
.endif

post-extract:
.	if ${ARCH} == amd64 || ${ARCH} == i386
		cd ${WRKDIR}; ${TAR} xf ${DISTNAME}.${DIST_SUFX}/plugins/${PORTNAME}-${EPSON_VERSION}-1.${LINUX_ARCH}.${DIST_FMT} && ${RM} -r ${DISTNAME}.${DIST_SUFX}
.	elif ${ARCH} == armv7 || ${ARCH} == armv7rasb
		cd ${WRKDIR}; ${TAR} xf ${DISTNAME}.${DIST_SUFX}/plugins/${PORTNAME}_${EPSON_VERSION}-1_${LINUX_ARCH}.${DIST_FMT} data.tar.xz && ${RM} -r ${DISTNAME}.${DIST_SUFX}
		cd ${WRKDIR}; ${TAR} xf data.tar.xz && ${RM} data.tar.xz
.	endif

do-install:
		${MKDIR} ${STAGEDIR}${LINUXBASE}
		cd ${WRKDIR}/usr; ${COPYTREE_SHARE} . ${STAGEDIR}${LINUXBASE}/usr "! -path *-ocr* -a ! -path *.build-id*"
		cd ${WRKDIR}/usr/${LINUX_LIB}/${EPSONSCAN2}/non-free-exec; ${INSTALL_KLD} ${LINUX_WRAPPERS} ${STAGEDIR}${LINUXBASE}/usr/${LINUX_LIB}/${EPSONSCAN2}/non-free-exec
		${MKDIR} ${STAGEDIR}${PREFIX}/lib/${EPSONSCAN2}/non-free-exec
		cd ${WRKDIR}; ${INSTALL_SCRIPT} ${LINUX_WRAPPERS} ${STAGEDIR}${PREFIX}/lib/${EPSONSCAN2}/non-free-exec
		cd ${WRKDIR}/usr/share/doc/${PORTNAME}-${EPSON_VERSION}-1; ${CP} -pr . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
