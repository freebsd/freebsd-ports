PORTNAME=	wayland
PORTVERSION=	1.21.0
DISTVERSIONSUFFIX=	-1.el9
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Wayland compositor libraries (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://wayland.freedesktop.org/

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	libwayland-client-${DISTVERSIONFULL} \
		libwayland-cursor-${DISTVERSIONFULL} \
		libwayland-egl-${DISTVERSIONFULL} \
		libwayland-server-${DISTVERSIONFULL}

DESCR=		${.CURDIR}/../wayland/pkg-descr

.include <bsd.port.mk>
