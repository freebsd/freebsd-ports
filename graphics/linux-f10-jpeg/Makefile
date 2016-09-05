# Created by: bsam
# $FreeBSD$

PORTNAME=	jpeg
PORTVERSION=	6b
CATEGORIES=	graphics linux
DISTNAME=	lib${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of the JPEG lib (Linux Fedora 10)

CONFLICTS=	linux-jpeg-[0-9]* linux-f8-jpeg-[0-9]*

USES=		linux:f10
USE_LINUX_RPM=	yes

RPMVERSION=	43.fc10
USE_LDCONFIG=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
