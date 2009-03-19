# New ports collection makefile for: linux-tiff
# Date created:		2001.02.08
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tiff
PORTVERSION=	3.7.1
CATEGORIES=	graphics linux
DISTNAME=	libtiff-${PORTVERSION}-6.fc4.2

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	TIFF library, Linux/i386 binary

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	jpeg
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
BRANDELF_DIRS=	usr/bin
PLIST=		pkg-plist.${LINUX_RPM_ARCH}
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
