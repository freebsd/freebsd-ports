PORTNAME=	libdrm
PORTVERSION=	2.4.117
DISTVERSIONSUFFIX=	-1.el9
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Interface to kernel Direct Rendering Module (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://dri.freedesktop.org/

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libpciaccess
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
