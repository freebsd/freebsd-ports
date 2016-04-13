# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	jpeg
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	graphics linux
DISTNAME=	lib${PORTNAME}-turbo-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of the JPEG lib (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-jpeg-[0-9]* linux-f10-jpeg-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_RPM=	yes
RPMVERSION=	3.el6_5
LINUX_NAME=	lib${PORTNAME}
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../jpeg/pkg-descr

.include <bsd.port.mk>
