PORTNAME=	glx-utils
PORTVERSION=	8.4.0
DISTVERSIONSUFFIX=	-12.20210504git0f9e7d9.el9.0.1
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	List GLX capabilities and simple renderer (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.mesa3d.org/

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	dri
USE_LINUX_RPM=	yes

DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr

BIN_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}
SRC_DISTFILES=	mesa-demos-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE \

.include <bsd.port.mk>
