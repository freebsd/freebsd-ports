# Created by: ijliao
# $FreeBSD$

PORTNAME=	tulip
PORTVERSION=	4.10.0
PORTREVISION=	7
DISTVERSIONSUFFIX=	_src
CATEGORIES=	graphics
MASTER_SITES=	SF/auber/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	System dedicated to the visualization of huge graphs

LICENSE=	LGPL3

LIB_DEPENDS=	libquazip.so:archivers/quazip@qt4 \
		libpng.so:graphics/png \
		libOGDF.so:math/ogdf \
		libfreetype.so:print/freetype2

BROKEN_powerpc64=	fails to link: libOGDF.so: undefined reference to CoinPackedVector::CoinPackedVector

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		cmake:noninja compiler:c++11-lib dos2unix jpeg python \
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
OPTIONS_DEFAULT=	QT5

QT4_USES=		qt:4
QT4_USE=		qt=corelib,gui,network,opengl,webkit \
			qt=xml,xmlpatterns \
			qt=moc_build,qmake_build,rcc_build,uic_build
QT_USES=		qt:5
QT5_USE=		qt=core,gui,network,opengl,webkit,widgets \
			qt=xml,xmlpatterns \
			qt=buildtools_build,qmake_build
QT5_CMAKE_BOOL=		USE_QT5_IF_INSTALLED

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

.if ${PORT_OPTIONS:MQT5}
BROKEN=			does not build
.endif

post-build:
	@${LN} -sf logo32x32.png \
		${WRKSRC}/library/tulip-gui/resources/icons/tulip.png

post-install:
	(cd ${WRKSRC}/library/tulip-gui/resources/icons && ${INSTALL_DATA} \
		tulip.png ${STAGEDIR}${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
