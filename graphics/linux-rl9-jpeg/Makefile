PORTNAME=	jpeg
PORTVERSION=	2.0.90
DISTVERSIONSUFFIX=	-7.el9
PORTREVISION=	1
CATEGORIES=	graphics linux
DISTNAME=	libjpeg-turbo-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	SIMD-accelerated JPEG codec (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://libjpeg-turbo.org/

USES=		cpe linux:rl9
CPE_PRODUCT=	libjpeg-turbo
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}-turbo/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/libjpeg-turbo-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
