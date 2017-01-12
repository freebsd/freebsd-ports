# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	jpeg
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	graphics linux
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of the JPEG lib (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-jpeg-[0-9]* linux-f10-jpeg-[0-9]*

LINUX_NAME=	libjpeg-turbo
RPMVERSION=	3.el6_5
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../jpeg/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}

.include <bsd.port.mk>
