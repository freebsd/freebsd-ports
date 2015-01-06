# Created by: bsam
# $FreeBSD$

PORTNAME=		libmng
PORTVERSION=		1.0.9
PORTREVISION=	1
CATEGORIES=		graphics linux
MASTER_SITES=		LOCAL/ehaupt/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		RPM of libmng (Linux Fedora 10)

CONFLICTS=		linux-libmng-[0-9]* linux-f8-libmng-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	f10
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	jpeg

RPMVERSION=	7
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libmng.so.1 usr/lib/libmng.so.1.0.0

.include <bsd.port.mk>
