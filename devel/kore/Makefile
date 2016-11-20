# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	kore
PORTVERSION=	2.0.0
DISTVERSIONSUFFIX=	-release
PORTREVISION=	1
CATEGORIES=	devel www

MAINTAINER=	t@tobik.me
COMMENT=	Web application framework for writing web APIs in C

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	gmake

USE_GITHUB=	yes
GH_ACCOUNT=	jorisvink

MAKE_ARGS=	INSTALL_DIR="${STAGEDIR}${PREFIX}/bin" \
		INCLUDE_DIR="${STAGEDIR}${PREFIX}/include/kore"

OPTIONS_DEFINE=	DEBUG HTTP JSONRPC PGSQL TASKS TLS
OPTIONS_DEFAULT=	HTTP JSONRPC PGSQL TASKS TLS

HTTP_DESC=	Build with HTTP support
JSONRPC_DESC=	Build with JSON-RPC support
TASKS_DESC=	Build with tasks support

TASKS_VARS=	MAKE_ARGS+=TASKS=1

PGSQL_IMPLIES=	HTTP
PGSQL_VARS=	MAKE_ARGS+=PGSQL=1
PGSQL_USES=	pgsql

TLS_VARS_OFF=	MAKE_ARGS+=NOTLS=1
TLS_USES=	ssl

HTTP_VARS_OFF=	MAKE_ARGS+=NOHTTP=1
# If TLS=off and HTTP=on kore will still link with libcrypto, so add
# an OpenSSL dependency here.
HTTP_USES=	ssl

JSONRPC_IMPLIES=	HTTP
JSONRPC_VARS=	MAKE_ARGS+=JSONRPC=1
JSONRPC_LIB_DEPENDS=	libyajl.so:devel/yajl

DEBUG_VARS=	MAKE_ARGS+=DEBUG=1

BROKEN_FreeBSD_9=	does not build

post-patch:
# Disable kore's own optimizations flags, make sure the correct flags
# are set when LOCALBASE is not /usr/local, and allow __generic on
# FreeBSD 12.0-CURRENT after r308264
	@${REINPLACE_CMD} -e 's|CFLAGS+=-O|#|g' \
		-e 's|/usr/local/|${LOCALBASE}/|g' \
		-e 's|-pedantic|-pedantic -Wno-error=c11-extensions|g' \
		${WRKSRC}/Makefile

pre-install:
	${STRIP_CMD} ${WRKSRC}/kore

post-install:
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/conf && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
