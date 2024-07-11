PORTNAME=	libgfortran
PORTVERSION=	11.4.1
DISTVERSIONSUFFIX=	-3.el9
PORTREVISION=	1
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Runtime libraries for gfortran (Linux Centos ${LINUX_DIST_VER})
WWW=		https://www.centos.org

USES=		cpe linux:rl9
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

SRC_DISTFILES=	gcc-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE

CONFLICTS=	linux-c7-${PORTNAME}

.include <bsd.port.mk>
