PORTNAME=	sjasmplus
PORTVERSION=	1.20.1
CATEGORIES=	devel

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Command-line cross-compiler of assembly language for Z80 CPU

LICENSE=	BSD3CLAUSE

USES=		compiler:c++14-lang gmake

USE_GITHUB=	yes
GH_ACCOUNT=	z00m128
GH_PROJECT=	sjasmplus
GH_TAGNAME=	v1.20.1

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	BUNDLED_LUA
OPTIONS_SINGLE=		SJLUA
OPTIONS_SINGLE_SJLUA=	BUNDLED_LUA LUA NOLUA
OPTIONS_SUB=		yes

BUNDLED_LUA_DESC=	Use bundled LUA 5.4
NOLUA_DESC=		Do not use LUA
SJLUA_DESC=		Which LUA version to use

BUNDLED_LUA_GH_TUPLE=	${_LUA_GH_TUPLE}
BUNDLED_LUA_MAKE_ARGS=	USE_BUNDLED_LUA=1
DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt
LUA_USES=		lua:54
LUA_GH_TUPLE=		${_LUA_GH_TUPLE}
LUA_MAKE_ARGS=		USE_BUNDLED_LUA=0
LUA_CPPFLAGS=		-I${LUA_INCDIR}
LUA_LDFLAGS=		-L${LUA_LIBDIR} -llua-5.4
NOLUA_MAKE_ARGS=	USE_LUA=0

_LUA_GH_TUPLE=	vinniefalco:LuaBridge:c882d32b:sjasmplus/LuaBridge

post-build-DOCS-on:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} docs)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sjasmplus ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/documentation.html ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sjasmplus

.include <bsd.port.mk>
