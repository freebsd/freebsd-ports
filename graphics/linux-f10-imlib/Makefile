# Created by: bsam
# $FreeBSD$

PORTNAME=	imlib
PORTVERSION=	1.9.15
PORTREVISION=	1
CATEGORIES=	graphics linux
MASTER_SITES=	LOCAL/ehaupt/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of imlib (Linux Fedora 10)

CONFLICTS=	linux-imlib-[0-9]* linux-f8-imlib-[0-9]*

USE_LINUX=	f10
USE_LINUX_RPM=	yes

RPMVERSION=	9.fc10
BRANDELF_FILES=	usr/bin/imlib_config
USE_LDCONFIG=	yes
PLIST=		${PKGDIR}/pkg-plist.${LINUX_RPM_ARCH}

.include <bsd.port.mk>
