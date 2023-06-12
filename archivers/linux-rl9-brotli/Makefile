PORTNAME=	brotli
PORTVERSION=	1.0.9
DISTVERSIONSUFFIX=	-6.el9
CATEGORIES=	archivers linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Generic-purpose lossless compression algorithm (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://github.com/google/brotli

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	libbrotli-${PORTVERSION}${DISTVERSIONSUFFIX}

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
