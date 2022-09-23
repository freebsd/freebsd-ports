PORTNAME=	libdrm
PORTVERSION=	2.4.97
DISTVERSIONSUFFIX=	-2.el7
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Interface to kernel Direct Rendering Module (Linux CentOS ${LINUX_DIST_VER})
WWW=		https://dri.freedesktop.org/

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	libpciaccess
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
