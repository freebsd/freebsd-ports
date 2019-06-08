# $FreeBSD$

PORTNAME=	wayland
PORTVERSION=	1.15.0
DISTVERSIONSUFFIX=	-1.el7
CATEGORIES=	graphics linux
LIB_DISTNAMES=	libwayland-client-${DISTVERSIONFULL} \
		libwayland-cursor-${DISTVERSIONFULL} \
		libwayland-egl-${DISTVERSIONFULL} \
		libwayland-server-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Wayland compositor libraries (Linux CentOS ${LINUX_DIST_VER})

DESCR=		${.CURDIR}/../wayland/pkg-descr
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

.include <bsd.port.mk>
