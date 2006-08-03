# New ports collection makefile for: linux-libmng
# Date created:		01/09/18
# Whom:                 mranner@inode.at
#
# $FreeBSD$
#

PORTNAME=		libmng
PORTVERSION=		1.0.9
CATEGORIES=		graphics linux
DISTNAME=		${PORTNAME}-${PORTVERSION}-1

MAINTAINER=		mranner@inode.at
COMMENT=		RPM of libmng

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
INSTALLS_SHLIB=	yes
ONLY_FOR_ARCHS=	i386 amd64

PLIST?=		${PKGDIR}/pkg-plist.${LINUX_RPM_ARCH}

.include <bsd.port.mk>
