# New ports collection makefile for:	luabind
# Date created:		06 Jun 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	luabind
PORTVERSION=	0.9
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library that helps you create bindings between C++ and Lua

LIB_DEPENDS=	boost_python.4:${PORTSDIR}/devel/boost-python-libs

USE_LUA=	5.1+
USE_LDCONFIG=	yes

CPPFLAGS=	-I.. -I${LUA_INCDIR} -I${LOCALBASE}/include
LDFLAGS=	-L${LUA_LIBDIR}
CXXFLAGS+=	-fPIC

PORTDOCS=	*

# If you manage to make boost_build build luabind with correct
# includes/libraries/compiler/flags, please send a patch
do-build:
	@cd ${WRKSRC}/src && ${ECHO_CMD} *.cpp | \
		${XARGS} -n1 -t ${_MAKE_JOBS:C/j/P/} \
		${CXX} ${CXXFLAGS} ${CPPFLAGS} -c
	cd ${WRKSRC}/src && ${CXX} -shared ${LDFLAGS} -llua -o libluabind.so *.o
	cd ${WRKSRC}/src && ${AR} -rcs libluabind.a *.o

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libluabind.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/libluabind.so ${PREFIX}/lib
	cd ${WRKSRC} && ${COPYTREE_SHARE} luabind ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR}
.endif

.include <bsd.port.mk>
