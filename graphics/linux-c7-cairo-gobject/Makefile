# $FreeBSD$

PORTNAME=	cairo
PORTVERSION=	1.15.12
DISTVERSIONSUFFIX=	-4.el7
PORTREVISION=	1
CATEGORIES=	graphics linux
PKGNAMESUFFIX=	-gobject

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Vector graphics library Cairo (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LINUX=	cairo dri fontconfig freetype pixman png xorglibs
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
