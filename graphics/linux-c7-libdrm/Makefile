# $FreeBSD$

PORTNAME=	libdrm
PORTVERSION=	2.4.91
DISTVERSIONSUFFIX=	-3.el7
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Interface to kernel Direct Rendering Module (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	libpciaccess
USE_LINUX_RPM=	yes

LINUX_DIST_VER=	7.6.1810

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
