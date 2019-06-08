# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	jpeg
PORTVERSION=	1.2.1
DISTVERSIONSUFFIX=	-3.el6_5
PORTREVISION=	3
CATEGORIES=	graphics linux
DISTNAME=	libjpeg-turbo-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	SIMD-accelerated JPEG codec (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}-turbo/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/libjpeg-turbo-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
