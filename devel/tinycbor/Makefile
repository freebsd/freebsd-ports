# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tinycbor
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Concise Binary Object Representation (CBOR) library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcjson.so:devel/libcjson

INSTALL_TARGET=	install-strip
MAKE_ARGS=	SOVERSION=${PORTVERSION:R:R}
USES=		gmake localbase pathfix

GH_ACCOUNT=	intel
GH_PROJECT=	tinycbor
USE_GITHUB=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/tinycbor-version.h ${STAGEDIR}${PREFIX}/include/tinycbor/tinycbor-version.h
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtinycbor.so.${PORTVERSION}
	${LN} -fs libtinycbor.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libtinycbor.so
	${LN} -fs libtinycbor.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libtinycbor.so.${PORTVERSION:R:R}

.include <bsd.port.mk>
