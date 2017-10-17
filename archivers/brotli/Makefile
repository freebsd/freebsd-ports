# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	brotli
PORTVERSION=	0.6.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	archivers devel

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Generic-purpose lossless compression algorithm

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	google

USES=		cmake compiler:c++0x pkgconfig
USE_LDCONFIG=	yes

CMAKE_ARGS=		-DBUILD_TESTING:BOOL=OFF

post-install:
	@${LN} -s libbrotlicommon.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libbrotlicommon.so.0
	@${LN} -s libbrotlidec.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libbrotlidec.so.0
	@${LN} -s libbrotlienc.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libbrotlienc.so.0

.include <bsd.port.mk>
