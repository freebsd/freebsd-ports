# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	tinycbor
PORTVERSION=	0.5.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Concise Binary Object Representation (CBOR) library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcjson.so:devel/libcjson

USES=		gmake localbase pathfix

INSTALL_TARGET=	install-strip
MAKE_ARGS=	SOVERSION=${PORTVERSION:R:R}

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	intel
GH_PROJECT=	tinycbor
USE_GITHUB=	yes

do-configure:
	@cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} configure

post-install:
	${LN} -fs libtinycbor.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libtinycbor.so
	${LN} -fs libtinycbor.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libtinycbor.so.${PORTVERSION:R:R}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtinycbor.so

.include <bsd.port.mk>
