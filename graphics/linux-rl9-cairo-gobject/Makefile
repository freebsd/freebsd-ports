PORTNAME=	cairo
PORTVERSION=	1.17.4
DISTVERSIONSUFFIX=	-7.el9
CATEGORIES=	graphics linux
PKGNAMESUFFIX=	-gobject

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Vector graphics library Cairo (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.cairographics.org/

USES=		cpe linux:rl9
USE_LINUX=	cairo dri fontconfig freetype pixman png xorglibs
USE_LINUX_RPM=	yes
CPE_VENDOR=	cairographics

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
