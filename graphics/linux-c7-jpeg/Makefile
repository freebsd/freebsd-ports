PORTNAME=	jpeg
PORTVERSION=	1.2.90
DISTVERSIONSUFFIX=	-8.el7
PORTREVISION=	4
CATEGORIES=	graphics linux
DISTNAME=	libjpeg-turbo-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	SIMD-accelerated JPEG codec (Linux CentOS ${LINUX_DIST_VER})

USES=		cpe linux:c7
CPE_PRODUCT=	libjpeg-turbo
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}-turbo/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/libjpeg-turbo-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
