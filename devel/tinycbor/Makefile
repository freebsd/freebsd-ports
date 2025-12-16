PORTNAME=	tinycbor
PORTVERSION=	0.6.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

PATCH_SITES=	https://github.com/intel/tinycbor/commit/
PATCHFILES=	628dee0d65f857d62ab1a6e1af9b9224d7df8fad.diff:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Concise Binary Object Representation (CBOR) library
WWW=		https://github.com/intel/tinycbor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcjson.so:devel/libcjson

USES=		gmake localbase:ldflags

INSTALL_TARGET=	install-strip
MAKE_ARGS=	SOVERSION=${PORTVERSION:R:R}

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	intel
USE_GITHUB=	yes

post-patch:
	@${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/VERSION

do-configure:
	@cd ${WRKSRC}/ && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtinycbor.so

.include <bsd.port.mk>
