PORTNAME=	gdscpp
DISTVERSION=	g20200611
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library to create and read GDSII file
WWW=		https://github.com/judefdiv/gdscpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	judefdiv
GH_TAGNAME=	20018e1

CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_FILES=	bin/gdscpp \
		include/gdscpp/gdsCpp.hpp \
		include/gdscpp/gdsForge.hpp \
		include/gdscpp/gdsParser.hpp \
		lib/libgds.so

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${LOCALBASE}/bin
	${INSTALL_LIB} ${BUILD_WRKSRC}/libgds.so ${STAGEDIR}${LOCALBASE}/lib
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${LOCALBASE}/include

.include <bsd.port.mk>
