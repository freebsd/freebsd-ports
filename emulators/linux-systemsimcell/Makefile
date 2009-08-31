# New ports collection makefile for:    emulators/linux-systemsimcell
# Date created:                         20 January 2009
# Whom:                                 Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$
#

PORTNAME=	systemsimcell
PORTVERSION=	3.1.25
CATEGORIES=	emulators linux
MASTER_SITES=	http://www.bsc.es/projects/deepcomputing/linuxoncell/cellsimulator/sdk3.1//CellSDK-Open-Fedora/x86/ \
		http://www.stasyan.com/devel/distfiles/
PKGNAMEPREFIX=	linux-
EXTRACT_SUFX=
DISTFILES=	systemsim-cell-3.1-25.f9.${ARCH}.rpm \
		sysroot_image-3.1-1.noarch.rpm

MAINTAINER=	stast@bsdportal.ru
COMMENT=	System simulator for the Cell Broadband Processor

NO_BUILD=	yes
RESTRICTED=	Redistribution of pre-compiled binaries is not permitted

SRC_DISTFILES=
DIST_SUBDIR=	rpm
ONLY_FOR_ARCHS=	i386
USE_LINUX_APPS=	tcl84 tk84 blt
USE_LINUX_RPM=	yes
NOFETCHFILES=	systemsim-cell-3.1-25.f9.${ARCH}.rpm

.include <bsd.port.pre.mk>

DOWNLOAD_URL=	http://www.alphaworks.ibm.com/tech/cellsystemsim/download

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${NOFETCHFILES})
IGNORE=	distfile can only be fetched if you accept the license. Go to ${DOWNLOAD_URL} and put ${NOFETCHFILES} into ${DISTDIR}/${DIST_SUBDIR}.
.endif

pre-fetch:
.if ${OSVERSION}<700055
IGNORE=	you need FreeBSD>=7.0 RELEASE with Linux emulation 2.6.x.
.elif ${OSVERSION}<800076 && ! defined (OVERRIDE_LINUX_NONBASE_PORTS)
IGNORE=	you need to use non-default linux ports (define OVERRIDE_LINUX_BASE_PORT=f10 and OVERRIDE_LINUX_NONBASE_PORTS=f10).
.endif

.include <bsd.port.post.mk>
