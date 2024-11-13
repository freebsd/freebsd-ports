PORTNAME=	brotli
PORTVERSION=	1.0.9
DISTVERSIONSUFFIX=	-6.el9
PORTREVISION=	1
CATEGORIES=	archivers linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Generic-purpose lossless compression algorithm (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://github.com/google/brotli

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

LIB_DISTNAMES=	libbrotli-${PORTVERSION}${DISTVERSIONSUFFIX}

DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr

.include <bsd.port.mk>
