# Created by: Piotr Kubaj <emulation@FreeBSD.org$
# $FreeBSD$

PORTNAME=	libgfortran
PORTVERSION=	4.8.5
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of runtime libs for gfortran (Linux Centos ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

RPMVERSION=	4.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

SRC_DISTFILES=	gcc-${DISTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

.include <bsd.port.mk>
