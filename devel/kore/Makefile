# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	kore
PORTVERSION=	3.2.2
CATEGORIES=	devel www
MASTER_SITES=	https://kore.io/releases/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Web application framework for writing web APIs in C

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	default notls
notls_PKGNAMESUFFIX=	-notls

USES=		compiler:c11 gmake ssl

CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}} -I${OPENSSLINC}
CFLAGS_clang=	-Wno-error=c11-extensions # 12.0 + -pedantic
LDFLAGS+=	-L${OPENSSLLIB}

DATADIR=	${PREFIX}/share/kore${PKGNAMESUFFIX}
EXAMPLESDIR=	${PREFIX}/share/examples/kore${PKGNAMESUFFIX}
PLIST_SUB=	SUFFIX=${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DEBUG EXAMPLES HTTP JSONRPC PGSQL PYTHON TASKS TLS
OPTIONS_DEFAULT=	HTTP JSONRPC PGSQL PYTHON TASKS TLS
.if ${FLAVOR:U} == notls
OPTIONS_EXCLUDE=	TLS
.endif
OPTIONS_SUB=	yes

HTTP_DESC=	Build with HTTP support
JSONRPC_DESC=	Build with JSON-RPC support
TASKS_DESC=	Build with tasks support

DEBUG_MAKE_ARGS=	DEBUG=1

PORTEXAMPLES=		*

JSONRPC_IMPLIES=	HTTP
JSONRPC_LIB_DEPENDS=	libyajl.so:devel/yajl
JSONRPC_MAKE_ARGS=	JSONRPC=1

HTTP_MAKE_ARGS_OFF=	NOHTTP=1

PGSQL_IMPLIES=		HTTP
PGSQL_MAKE_ARGS=	PGSQL=1
PGSQL_USES=		pgsql

PYTHON_BINARY_ALIAS=	python3-config=${PYTHON_CMD}-config
PYTHON_MAKE_ARGS=	PYTHON=1
PYTHON_USES=		gettext-runtime python:3.6+

TASKS_MAKE_ARGS=	TASKS=1

TLS_MAKE_ARGS_OFF=	NOTLS=1

post-patch:
# Disable kore's own optimizations flags, make sure the correct paths
# are set when LOCALBASE is not /usr/local
	@${REINPLACE_CMD} -e 's|CFLAGS+=-O|#|g' \
		-e 's|/usr/local/|${LOCALBASE}/|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|%%SUFFIX%%|${PKGNAMESUFFIX}|g' \
		-e 's|%%OPENSSLINC%%|${OPENSSLINC}|g' \
		${WRKSRC}/src/cli.c ${WRKSRC}/src/utils.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kore ${STAGEDIR}${PREFIX}/bin/kore${PKGNAMESUFFIX}
	${INSTALL_PROGRAM} ${WRKSRC}/kodev/kodev ${STAGEDIR}${PREFIX}/bin/kodev${PKGNAMESUFFIX}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/kore.features ${STAGEDIR}${DATADIR}/features
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/kore${PKGNAMESUFFIX}
	@cd ${WRKSRC}/include && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/include/kore${PKGNAMESUFFIX}
	@${MKDIR} ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/share/man/kodev.1 \
		${STAGEDIR}${PREFIX}/man/man1/kodev${PKGNAMESUFFIX}.1

do-install-EXAMPLES-on:
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/conf && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
