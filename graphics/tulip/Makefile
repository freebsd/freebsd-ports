# Created by: ijliao
# $FreeBSD$

PORTNAME=	tulip
PORTVERSION=	4.10.0
PORTREVISION=	9
DISTVERSIONSUFFIX=	_src
CATEGORIES=	graphics
MASTER_SITES=	SF/auber/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	System dedicated to the visualization of huge graphs

LICENSE=	LGPL3

BROKEN=		Missing libquazip.so:archivers/quazip@qt4
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2019-05-08
LIB_DEPENDS=	libpng.so:graphics/png \
		libOGDF.so:math/ogdf \
		libfreetype.so:print/freetype2

BROKEN_powerpc64=	fails to link: libOGDF.so: undefined reference to CoinPackedVector::CoinPackedVector

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		cmake:noninja compiler:c++11-lib dos2unix jpeg python qt:5 \
		shebangfix
SHEBANG_FILES=	tulip-config.in
DOS2UNIX_FILES=	software/tulip/src/main.cpp
USE_GL=		gl glew glut
USE_GNOME=	libxml2
CMAKE_ARGS=	-DBUILD_DOC:BOOL=OFF \
		-DOGDFInclude:STRING=${LOCALBASE}/include \
		-DOGDFLibrary:STRING=${LOCALBASE}/lib/libOGDF.so
USE_LDCONFIG=	${PREFIX}/lib/tulip
USE_QT=			core gui network opengl webkit widgets \
			xml xmlpatterns \
			buildtools_build qmake_build

CXXFLAGS+=	-fPIC -I${LOCALBASE}/include -DNDEBUG -DOGDF_DLL
# Unhide std::to_string() to fix build with GCC (see ports/193528 for details)
CXXFLAGS+=	-D_GLIBCXX_USE_C99
LDFLAGS+=	-L${LOCALBASE}/lib -lCOIN

PLIST_SUB=	TULIP_VERSION="${PORTVERSION}" \
		TULIP_VERS="${PORTVERSION:R}"

DESKTOP_ENTRIES="Tulip" "" "${PREFIX}/share/pixmaps.tulip.png" "tulip" "" ""

CMAKE_ON=		USE_QT5_IF_INSTALLED

BROKEN=			does not build

post-build:
	@${LN} -sf logo32x32.png \
		${WRKSRC}/library/tulip-gui/resources/icons/tulip.png

post-install:
	(cd ${WRKSRC}/library/tulip-gui/resources/icons && ${INSTALL_DATA} \
		tulip.png ${STAGEDIR}${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
