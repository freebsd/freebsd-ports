# Created by: Leo Vandewoestijne <freebsd@dns.company>
# $FreeBSD$

PORTNAME=	cqueues
DISTVERSIONPREFIX=	rel-
DISTVERSION=	20200726
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	freebsd@dns.company
COMMENT=	Continuation queues module for Lua

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake lua:51-54,module ssl

USE_GITHUB=	yes
GH_ACCOUNT=	wahern

MAKE_ENV+=	LUA_APIS="${LUA_VER}"
CPPFLAGS+=	-I${LUA_INCDIR} -I${OPENSSLINC}

DOCSDIR=	${LUA_DOCSDIR}
EXAMPLESDIR=	${LUA_EXAMPLESDIR}
PORTDOCS=	cqueues.pdf
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

EXAMPLES_USES=	shebangfix
EXAMPLES_VARS=	shebang_files="examples/*"

# Some of the shebangs in examples/* are formatted like this.
lua_OLD_CMD+=	/usr/local/lua[0-9]*/bin/lua

post-install:
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/_${PORTNAME}.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${BUILD_WRKSRC}/doc/cqueues.pdf ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${BUILD_WRKSRC}/examples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
