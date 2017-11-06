# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	kore
PORTVERSION=	2.0.0
DISTVERSIONSUFFIX=	-release
PORTREVISION=	2
CATEGORIES=	devel www

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Web application framework for writing web APIs in C

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to compile: cc1: error: -Werror=c11-extensions: No option -Wc11-extensions

USES=		compiler gmake

USE_GITHUB=	yes
GH_ACCOUNT=	jorisvink

CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_clang=	-Wno-error=c11-extensions # 12.0 + -pedantic

OPTIONS_DEFINE=	DEBUG EXAMPLES HTTP JSONRPC PGSQL TASKS TLS
OPTIONS_DEFAULT=	HTTP JSONRPC PGSQL TASKS TLS
OPTIONS_SUB=	yes

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

KORE_BIN=	kore${PKGNAMESUFFIX}
PLIST_SUB=	KORE_BIN="${KORE_BIN}"

post-patch:
# Disable kore's own optimizations flags, make sure the correct paths
# are set when LOCALBASE is not /usr/local
	@${REINPLACE_CMD} -e 's|CFLAGS+=-O|#|g' \
		-e 's|/usr/local/|${LOCALBASE}/|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|"kore"|"${PREFIX}/bin/${KORE_BIN}"|g' \
		-e 's|%%KORE_BIN%%|${KORE_BIN}|g' \
		${WRKSRC}/src/cli.c ${WRKSRC}/src/utils.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kore ${STAGEDIR}${PREFIX}/bin/${KORE_BIN}
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${KORE_BIN}/kore
	@cd ${WRKSRC}/includes && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${KORE_BIN}/kore

do-install-EXAMPLES-on:
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/conf && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
