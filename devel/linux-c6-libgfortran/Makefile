# $FreeBSD$

PORTNAME=	libgfortran
PORTVERSION=	4.4.7
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of runtime libs for gfortran (Linux Centos ${LINUX_DIST_VER})

USE_LINUX=	c6
USE_LINUX_RPM=	yes

RPMVERSION=	11.el6
USE_LDCONFIG=	yes
SRC_DISTFILES=	gcc-${DISTVERSION}${SRC_SUFX}

PLIST_FILES=	usr/lib/libgfortran.so.3.0.0 usr/lib/libgfortran.so.3

.include <bsd.port.mk>
