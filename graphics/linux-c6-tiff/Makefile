# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	libtiff
PORTVERSION=	3.9.4
DISTVERSIONSUFFIX=	-21.el6_8
PORTREVISION=	5
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Tools and library routines for working with TIFF images (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	BSD3CLAUSE

USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	jpeg
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../tiff/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
