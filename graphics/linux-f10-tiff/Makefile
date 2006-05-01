# New ports collection makefile for: linux-tiff
# Date created:		2001.02.08
# Whom:                 taoka@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tiff
PORTVERSION=	3.6.1
PORTREVISION=	6
CATEGORIES=	graphics linux
DISTNAME=	libtiff-${PORTVERSION}-10.fc3

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	TIFF library, Linux/i386 binary

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	3
INSTALLS_SHLIB=	yes
BRANDELF_DIRS=	usr/bin
PLIST=		pkg-plist.${LINUX_RPM_ARCH}

.include <bsd.port.mk>
