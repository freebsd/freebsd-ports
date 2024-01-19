PORTNAME=	lutok
DISTVERSION=	0.4
PORTREVISION=	9
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Lightweight C++ API for Lua
WWW=		https://github.com/jmmv/lutok/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	atf>=0.21:devel/atf
RUN_DEPENDS=	atf>=0.21:devel/atf

USES=		autoreconf libtool lua pathfix pkgconfig
USE_CXXSTD=	gnu++11
USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_TAGNAME=	${PORTNAME}-${DISTVERSION}
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
#TEST_CONFIGURE_WITH=	atf
# Force the use of the lua version we have chosen via USE_LUA.  If we allow
# lutok's configure script search for one using pkgconfig files, it might pick
# a different version.
CONFIGURE_ARGS+=	LUA_CFLAGS="-I${LUA_INCDIR}"
CONFIGURE_ARGS+=	LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER} -lm"

MAKE_FLAGS+=	examplesdir=${EXAMPLESDIR}
#		pkgconfigdir=${PREFIX}/libdata/pkgconfig

INSTALL_TARGET=	install-strip

PORTDOCS=	AUTHORS COPYING NEWS README html/*

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	doxygen>0:devel/doxygen
DOCS_CONFIGURE_ON=	--docdir=${DOCSDIR} --htmldir=${DOCSDIR}/html
DOCS_CONFIGURE_OFF=	--without-doxygen
DOCS_MAKE_ARGS_OFF=	doc_DATA=
EXAMPLES_MAKE_ARGS_OFF=	dist_examples_DATA=

pre-install-DOCS-off:
	@${RM} -r ${WRKSRC}/api-docs

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/api-docs && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
