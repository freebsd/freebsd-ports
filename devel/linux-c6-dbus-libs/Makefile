# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	dbus
PORTVERSION=	1.2.24
DISTVERSIONSUFFIX=	-9.el6
PORTREVISION=	7
CATEGORIES=	devel linux
PKGNAMESUFFIX=	-libs
LIB_DISTNAMES=	${LINUXNAME}-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Libraries for accessing D-BUS (Linux CentOS ${LINUX_DIST_VER})

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
LINUXNAME=	${PORTNAME}${PKGNAMESUFFIX}
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

.include <bsd.port.mk>
