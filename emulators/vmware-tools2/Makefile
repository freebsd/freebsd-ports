# New ports collection makefile for:	VMware tools for FreeBSD
# Date created:		10 Aug 2000
# Whom:			matusita@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vmware-tools
PORTVERSION=	${VMWARE_VER}.${BUILD_VER}
CATEGORIES=	emulators
MASTER_SITES=	http://vmware-svca.www.conxion.com/software/ \
		http://vmware-chil.www.conxion.com/software/ \
		http://vmware-heva.www.conxion.com/software/ \
		http://vmware.wespe.de/software/ \
		ftp://vmware.wespe.de/pub/software/
DISTNAME=	tools-for-freebsd-${BUILD_VER}

MAINTAINER=	matusita@FreeBSD.org
COMMENT=VMware tools for guest OS (for VMware 2.x, FreeBSD version)

WRKSRC=		${WRKDIR}/vmware-freebsd-tools

ONLY_FOR_ARCHS=	i386
USE_X_PREFIX=	yes
NO_BUILD=	yes
NO_LATEST_LINK=	yes

RESTRICTED=	"Not sure if we can redistribute this."
NO_PACKAGE=	${RESTRICTED}

VMWARE_VER=	2.0.4
BUILD_VER=	307

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/XF86_VMware ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XF86Config.dist ${PREFIX}/etc/XF86Config_VMware
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
