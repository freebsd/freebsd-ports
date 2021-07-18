PORTNAME=	kore
PORTVERSION=	4.1.0
CATEGORIES=	devel www
MASTER_SITES=	https://kore.io/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web application framework for writing web APIs in C

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 gmake ssl

MAKE_ARGS=	OPENSSL_PATH=${OPENSSLBASE}
CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
# 12.0 + -pedantic
CFLAGS_clang=	-Wno-error=c11-extensions

PORTEXAMPLES=	*

OPTIONS_DEFINE=		ACME CURL DEBUG EXAMPLES HTTP JSONRPC PGSQL PYTHON \
			TASKS TLS
OPTIONS_DEFAULT=	ACME CURL HTTP JSONRPC PGSQL PYTHON TASKS TLS
OPTIONS_SUB=		yes

ACME_DESC=	Build with ACME support
HTTP_DESC=	Build with HTTP support
JSONRPC_DESC=	Build with JSON-RPC support
TASKS_DESC=	Build with tasks support

ACME_MAKE_ARGS=		ACME=1
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_MAKE_ARGS=		CURL=1
DEBUG_MAKE_ARGS=	DEBUG=1
HTTP_MAKE_ARGS_OFF=	NOHTTP=1
JSONRPC_IMPLIES=	HTTP
JSONRPC_LIB_DEPENDS=	libyajl.so:devel/yajl
JSONRPC_MAKE_ARGS=	JSONRPC=1
PGSQL_IMPLIES=		HTTP
PGSQL_USES=		pgsql
PGSQL_MAKE_ARGS=	PGSQL=1
PYTHON_USES=		gettext-runtime python:3.6+
PYTHON_MAKE_ARGS=	PYTHON=1
PYTHON_BINARY_ALIAS=	python3-config=${PYTHON_CMD}-config
TASKS_MAKE_ARGS=	TASKS=1
TLS_MAKE_ARGS_OFF=	NOTLS=1

.include <bsd.port.options.mk>

post-patch:
.if ${LOCALBASE} != /usr/local
	@${REINPLACE_CMD} 's|/usr/local/|${LOCALBASE}/|g' \
		${WRKSRC}/Makefile
.endif
	@${REINPLACE_CMD} 's|%%OPENSSLINC%%|${OPENSSLINC}|g' \
		${WRKSRC}/src/cli.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/kodev \
		${STAGEDIR}${PREFIX}/bin/kore

post-install-EXAMPLES-on:
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/conf && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
