# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	tiff
PORTVERSION=	3.9.4
PORTREVISION=	1
CATEGORIES=	graphics linux
DISTNAME=	lib${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	TIFF library (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-tiff-[0-9]* linux-f10-tiff-[0-9]*

ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX=	c6
USE_LINUX_APPS=	jpeg
USE_LINUX_RPM=	yes
RPMVERSION=	10.el6_5
LINUX_NAME=	lib${PORTNAME}
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
