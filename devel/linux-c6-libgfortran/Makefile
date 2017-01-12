# $FreeBSD$

PORTNAME=	libgfortran
PORTVERSION=	4.4.7
PORTREVISION=	4
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of runtime libs for gfortran (Linux Centos ${LINUX_DIST_VER})

USES=		linux:c6
USE_LINUX_RPM=	yes

RPMVERSION=	17.el6
USE_LDCONFIG=	yes
SRC_DISTFILES=	gcc-${DISTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

.include <bsd.port.mk>
