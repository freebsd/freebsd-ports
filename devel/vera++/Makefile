PORTNAME=	vera++
PORTVERSION=	1.3.0
PORTREVISION=	15
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/verateam/vera/downloads/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-doc${EXTRACT_SUFX}

MAINTAINER=	cristianorolim@outlook.com
COMMENT=	Tool for verification of C++ source code

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs

USES=		compiler:c++11-lang cmake tk

CMAKE_ARGS+=	-DTCL_INCLUDE_PATH=${TCL_INCLUDEDIR} \
		-DTK_INCLUDE_PATH=${TK_INCLUDEDIR} \
		-DVERA_USE_SYSTEM_BOOST:BOOL=ON \
		-DVERA_PYTHON:BOOL=OFF

PLIST_FILES=	bin/vera++ man/man1/vera++.1.gz

DATADIR=	${PREFIX}/lib/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS LUA
OPTIONS_DEFAULT=	LUA

LUA_CMAKE_OFF=	-DVERA_LUA:BOOL=OFF
LUA_CMAKE_ON=	-DVERA_LUA:BOOL=ON
LUA_LIB_DEPENDS=	libluabind.so:devel/luabind

post-patch:
	@${REINPLACE_CMD} -e '/^add_subdirectory(doc/d' \
		${WRKSRC}/CMakeLists.txt

post-install:
	${INSTALL_MAN} ${WRKDIR}/vera++.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/vera++.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
