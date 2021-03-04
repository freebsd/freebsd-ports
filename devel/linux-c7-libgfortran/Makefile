# Created by: Piotr Kubaj <emulation@FreeBSD.org$
# $FreeBSD$

PORTNAME=	libgfortran
PORTVERSION=	4.8.5
DISTVERSIONSUFFIX=	-44.el7
PORTREVISION=	6
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Runtime libraries for gfortran (Linux Centos ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

SRC_DISTFILES=	gcc-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

.include <bsd.port.mk>
