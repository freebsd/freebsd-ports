# Created by: ijliao
# $FreeBSD$

PORTNAME=	tulip
PORTVERSION=	4.10.0
DISTVERSIONSUFFIX=	_src
CATEGORIES=	graphics
MASTER_SITES=	SF/auber/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	System dedicated to the visualization of huge graphs

LICENSE=	LGPL3

LIB_DEPENDS=	libquazip.so:archivers/quazip \
		libpng.so:graphics/png \
		libOGDF.so:math/ogdf \
		libfreetype.so:print/freetype2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		cmake:outsource compiler:c++11-lib dos2unix execinfo jpeg python \
		shebangfix
SHEBANG_FILES=	tulip-config.in
DOS2UNIX_FILES=	software/tulip/src/main.cpp
USE_GL=		gl glew glut
USE_GNOME=	libxml2
CMAKE_ARGS=	-DBUILD_DOC:BOOL=OFF \
		-DOGDFInclude:STRING=${LOCALBASE}/include \
		-DOGDFLibrary:STRING=${LOCALBASE}/lib/libOGDF.so
USE_LDCONFIG=	${PREFIX}/lib/tulip

CXXFLAGS+=	-fPIC -I${LOCALBASE}/include -DNDEBUG -DOGDF_DLL
# Unhide std::to_string() to fix build with GCC (see ports/193528 for details)
CXXFLAGS+=	-D_GLIBCXX_USE_C99
LDFLAGS+=	-L${LOCALBASE}/lib -lCOIN

PLIST_SUB=	TULIP_VERSION="${PORTVERSION}" \
		TULIP_VERS="${PORTVERSION:R}"

DESKTOP_ENTRIES="Tulip" "" "${PREFIX}/share/pixmaps.tulip.png" "tulip" "" ""

OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	QT4 QT5
OPTIONS_DEFAULT=	QT4

QT4_USE=		qt4=corelib,gui,network,opengl,webkit \
			qt4=xml,xmlpatterns \
			qt4=moc_build,qmake_build,rcc_build,uic_build
QT5_USE=		qt5=core,gui,network,opengl,webkit,widgets \
			qt5=xml,xmlpatterns \
			qt5=buildtools_build,qmake_build
QT5_CMAKE_BOOL=		USE_QT5_IF_INSTALLED

# Upstream contacted regarding build failures on FreeBSD 9: https://sourceforge.net/p/auber/discussion/206283/thread/489d80e8/
BROKEN_FreeBSD_9=	/usr/local/include/bfd.h:1610:38: error: expected ',' or '...' before 'ATTRIBUTE_UNUSED'

post-build:
	@${LN} -sf logo32x32.png \
		${WRKSRC}/library/tulip-gui/resources/icons/tulip.png

post-install:
	(cd ${WRKSRC}/library/tulip-gui/resources/icons && ${INSTALL_DATA} \
		tulip.png ${STAGEDIR}${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
