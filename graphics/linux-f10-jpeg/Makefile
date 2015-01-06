# Created by: bsam
# $FreeBSD$

PORTNAME=	jpeg
PORTVERSION=	6b
CATEGORIES=	graphics linux
MASTER_SITES=	LOCAL/ehaupt/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
DISTNAME=	lib${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of the JPEG lib (Linux Fedora 10)

CONFLICTS=	linux-jpeg-[0-9]* linux-f8-jpeg-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	f10
USE_LINUX_RPM=	yes
LINUX_NAME=	lib${PORTNAME}

RPMVERSION=	43.fc10
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
