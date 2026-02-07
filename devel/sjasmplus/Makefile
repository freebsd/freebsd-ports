PORTNAME=	sjasmplus
DISTVERSION=	1.20.3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/z00m128/sjasmplus/releases/download/v${DISTVERSION}/
EXTRACT_SUFX=	.tar.xz
DISTFILES=	${PORTNAME}-${DISTVERSION}-src${EXTRACT_SUFX}

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Command-line cross-compiler of assembly language for Z80 CPU
WWW=		https://github.com/z00m128/sjasmplus

LICENSE=	BSD3CLAUSE

USES=		compiler:c++14-lang gmake tar:xz

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	BUNDLED_LUA
OPTIONS_SINGLE=		SJLUA
OPTIONS_SINGLE_SJLUA=	BUNDLED_LUA LUA NOLUA
OPTIONS_SUB=		yes

BUNDLED_LUA_DESC=	Use bundled LUA 5.4
NOLUA_DESC=		Do not use LUA
SJLUA_DESC=		Which LUA version to use

BUNDLED_LUA_MAKE_ARGS=	USE_BUNDLED_LUA=1 \
			USE_LUA=1
DOCS_BUILD_DEPENDS=	docbook-xsl-ns>0:textproc/docbook-xsl-ns \
			xsltproc:textproc/libxslt
LUA_USES=		lua:54
LUA_MAKE_ARGS=		INCDIR_LUA=${LUA_INCDIR} \
			LUA_VER=${LUA_VER} \
			USE_BUNDLED_LUA=0 \
			USE_LUA=1
LUA_LDFLAGS=		-L${LUA_LIBDIR}
NOLUA_MAKE_ARGS=	USE_BUNDLED_LUA=0 \
			USE_LUA=0

.include <bsd.port.pre.mk>

.if !${PORT_OPTIONS:MNOLUA}
USE_GITHUB=	nodefault
GH_TUPLE=	vinniefalco:LuaBridge:6580b187:sjasmplus/LuaBridge
.endif

post-patch-DOCS-on:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		${WRKSRC}/docs/docbook-xsl-ns-html-customization-freebsd.xsl

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

.include <bsd.port.post.mk>
