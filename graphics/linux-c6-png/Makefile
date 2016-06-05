# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	png
PORTVERSION=	1.2.49
PORTREVISION=	3
CATEGORIES=	graphics linux
DISTNAME=	lib${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of the PNG lib (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-png-[0-9]* linux-f8-png-[0-9]* linux-f10-png-[0-9]*

LINUX_NAME=	libpng
ONLY_FOR_ARCHS=	i386 amd64
RPMVERSION=	2.el6_7
USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/libpng-${PORTVERSION}
PORTDOCS=	CHANGES LICENSE README TODO example.c libpng-1.2.49.txt CMakeLists.txt
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
