# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	png
PORTVERSION=	1.2.49
PORTREVISION=	4
CATEGORIES=	graphics linux
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of the PNG lib (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-png-[0-9]* linux-f8-png-[0-9]* linux-f10-png-[0-9]*

LINUX_NAME=	libpng
RPMVERSION=	2.el6_7
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	CHANGES LICENSE README TODO example.c libpng-1.2.49.txt CMakeLists.txt
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
