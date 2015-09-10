# Created by: ijliao
# $FreeBSD$

PORTNAME=	tulip
PORTVERSION=	4.7.0
DISTVERSIONSUFFIX=	_src
CATEGORIES=	graphics
MASTER_SITES=	SF/auber/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	woodsb02@gmail.com
COMMENT=	System dedicated to the visualization of huge graphs

LICENSE=	LGPL3

LIB_DEPENDS=	libquazip.so:${PORTSDIR}/archivers/quazip \
		libpng.so:${PORTSDIR}/graphics/png \
		libOGDF.so:${PORTSDIR}/math/ogdf \
		libfreetype.so:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		cmake:outsource compiler:c++11-lib dos2unix execinfo jpeg python \
		shebangfix
SHEBANG_FILES=	tulip-config.in
DOS2UNIX_FILES=	software/tulip/src/main.cpp
USE_CXXSTD=	c++11
USE_GL=		glew glut
USE_GNOME=	libxml2
CMAKE_ARGS=	-DBUILD_DOC:BOOL=OFF \
		-DOGDFInclude:STRING=${LOCALBASE}/include \
		-DOGDFLibrary:STRING=${LOCALBASE}/lib/libOGDF.so
USE_LDCONFIG=	${PREFIX}/lib/tulip

CXXFLAGS+=	-fPIC -I${LOCALBASE}/include -DNDEBUG -DOGDF_DLL
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	TULIP_VERSION="${PORTVERSION}" \
		TULIP_VERS="${PORTVERSION:R}"

DESKTOP_ENTRIES="Tulip" "" "${PREFIX}/share/pixmaps.tulip.png" "tulip" "" ""

OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	QT4 QT5
OPTIONS_DEFAULT=	QT4

QT4_USE=		qt4=corelib,gui,network,opengl,webkit \
			qt4=xml,xmlpatterns \
			qt4=moc_build,qmake_build,rcc_build,uic_build
QT4_CMAKE_ON=		-DUSE_QT5_IF_INSTALLED:BOOL=OFF
QT5_USE=		qt5=core,gui,network,opengl,webkit,widgets \
			qt5=xml,xmlpatterns \
			qt5=buildtools_build,qmake_build
QT5_CMAKE_ON=		-DUSE_QT5_IF_INSTALLED:BOOL=ON

post-build:
	@${LN} -sf logo32x32.png \
		${WRKSRC}/library/tulip-gui/resources/icons/tulip.png

post-install:
	(cd ${WRKSRC}/library/tulip-gui/resources/icons && ${INSTALL_DATA} \
		tulip.png ${STAGEDIR}${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
