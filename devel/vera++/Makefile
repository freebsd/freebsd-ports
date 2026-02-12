PORTNAME=	vera++
PORTVERSION=	1.3.0
PORTREVISION=	21
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/verateam/vera/downloads/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-doc${EXTRACT_SUFX}

MAINTAINER=	cristianorolim@outlook.com
COMMENT=	Tool for verification of C++ source code
WWW=		https://bitbucket.org/verateam/vera/wiki/Home

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs

USES=		compiler:c++11-lang cmake tk
USE_CXXSTD=	c++14

CMAKE_ARGS+=	-DTCL_INCLUDE_PATH=${TCL_INCLUDEDIR} \
		-DTK_INCLUDE_PATH=${TK_INCLUDEDIR} \
		-DVERA_USE_SYSTEM_BOOST:BOOL=ON \
		-DVERA_PYTHON:BOOL=OFF

DATADIR=	${PREFIX}/lib/${PORTNAME}

PLIST_FILES=	bin/vera++ share/man/man1/vera++.1.gz
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS LUA
OPTIONS_DEFAULT=	LUA

LUA_LIB_DEPENDS=	libluabind.so:devel/luabind
LUA_USES=		lua:51
LUA_CMAKE_ON=		-DVERA_LUA:BOOL=ON
LUA_CMAKE_OFF=		-DVERA_LUA:BOOL=OFF

post-patch:
	@${REINPLACE_CMD} -e '/^add_subdirectory(doc/d' \
			  -e '/VERSION/ s/2.8.6/3.5/g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/FILES/ s|share/vera++/doc|share/doc/vera++|g' \
		${WRKSRC}/doc/CMakeLists.txt
	@${REINPLACE_CMD} -e '/boostLibs/ s/ system/ /g' \
		${WRKSRC}/src/boost.cmake
	@${REINPLACE_CMD} -e '/boost::filesystem/ s/normalize/lexically_normal/g' \
		${WRKSRC}/src/executable_path.cpp

post-install:
	${INSTALL_MAN} ${WRKDIR}/vera++.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/vera++.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
