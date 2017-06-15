# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	luabind
PORTVERSION=	0.9.1
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library that helps you create bindings between C++ and Lua

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_python.so:devel/boost-python-libs

USES=		lua:51
USE_LDCONFIG=	yes

CPPFLAGS+=	-I.. -I${LUA_INCDIR} -I${LOCALBASE}/include
LDFLAGS+=	-L${LUA_LIBDIR}
CXXFLAGS+=	-fPIC

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

# If you manage to make boost_build build luabind with correct
# includes/libraries/compiler/flags, please send a patch;
# until then, custom build is used
do-build:
	@cd ${WRKSRC}/src && ${ECHO_CMD} *.cpp | \
		${XARGS} -n1 -t ${_MAKE_JOBS:C/j/P/} \
		${CXX} ${CXXFLAGS} ${CPPFLAGS} -c
	cd ${WRKSRC}/src && ${CXX} -shared ${LDFLAGS} -llua-${LUA_VER} -o libluabind.so *.o
	cd ${WRKSRC}/src && ${AR} -rcs libluabind.a *.o

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libluabind.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/libluabind.so ${STAGEDIR}${PREFIX}/lib
	@cd ${WRKSRC} && ${COPYTREE_SHARE} luabind ${STAGEDIR}${PREFIX}/include

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
