# Created by: Cristiano Rolim Pereira <cristianorolim@outlook.com>
# $FreeBSD$

PORTNAME=	vera++
PORTVERSION=	1.3.0
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/verateam/vera/downloads/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-doc${EXTRACT_SUFX}

MAINTAINER=	cristianorolim@outlook.com
COMMENT=	Tool for verification of C++ source code

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs

USES=		cmake:outsource tk

CMAKE_ARGS+=	-DTCL_INCLUDE_PATH=${TCL_INCLUDEDIR} \
		-DTK_INCLUDE_PATH=${TK_INCLUDEDIR} \
		-DVERA_USE_SYSTEM_BOOST:BOOL=ON

PLIST_FILES=	bin/vera++ man/man1/vera++.1.gz

DATADIR=	${PREFIX}/lib/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS LUA PYTHON
OPTIONS_DEFAULT=	LUA PYTHON

PYTHON_CMAKE_OFF=	-DVERA_PYTHON:BOOL=OFF
PYTHON_CMAKE_ON=	-DVERA_PYTHON:BOOL=ON
PYTHON_LIB_DEPENDS=	${PY_BOOST}
PYTHON_USES=	python
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
