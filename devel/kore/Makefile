# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	kore
PORTVERSION=	2.0.0
DISTVERSIONSUFFIX=	-release
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

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_9=	Base OpenSSL on FreeBSD 9.x is too old
.endif

post-patch:
# Disable kore's own optimizations flags
	@${REINPLACE_CMD} 's|CFLAGS+=-O|#|g' ${WRKSRC}/Makefile
# Make sure the correct flags are set when LOCALBASE is not /usr/local
	@${REINPLACE_CMD} 's|/usr/local/|${LOCALBASE}/|g' ${WRKSRC}/Makefile

pre-install:
	${STRIP_CMD} ${WRKSRC}/kore

post-install:
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/conf && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
