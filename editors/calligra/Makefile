# $FreeBSD$

PORTNAME=	calligra
PORTVERSION=	${CALLIGRA_VERSION}
PORTREVISION=	1
CATEGORIES=	editors kde
MASTER_SITES=	KDE/${CALLIGRA_BRANCH}/${PORTNAME}-${PORTVERSION}/
DIST_SUBDIR=	KDE/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE graphic art and office suite

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libqca.so:${PORTSDIR}/devel/qca \
		libexiv2.so:${PORTSDIR}/graphics/exiv2 \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libwpd-0.10.so:${PORTSDIR}/textproc/libwpd010 \
		libwpg-0.3.so:${PORTSDIR}/graphics/libwpg03 \
		libpoppler-qt4.so:${PORTSDIR}/graphics/poppler-qt4 \
		libopenjpeg.so:${PORTSDIR}/graphics/openjpeg15 \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libgsl.so:${PORTSDIR}/math/gsl \
		libwps-0.3.so:${PORTSDIR}/textproc/libwps03 \
		libvisio-0.1.so:${PORTSDIR}/textproc/libvisio01 \
		libOpenColorIO.so:${PORTSDIR}/graphics/opencolorio \
		libodfgen-0.1.so:${PORTSDIR}/textproc/libodfgen01 \
		libetonyek-0.1.so:${PORTSDIR}/graphics/libetonyek01 \
		librevenge-0.0.so:${PORTSDIR}/textproc/librevenge
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen3.pc:${PORTSDIR}/math/eigen3 \
		pstoedit:${PORTSDIR}/graphics/pstoedit
RUN_DEPENDS=	pstoedit:${PORTSDIR}/graphics/pstoedit

USE_GL=		glew
USE_GNOME=	glib20 libxml2 libxslt
USE_KDE4=	kactivities kdelibs kdeprefix libkdcraw \
		okular pimlibs attica automoc4 soprano
USE_QT4=	corelib dbus designer_build gui opengl phonon \
		qtestlib_build script sql svg webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_SQLITE=	3
USES=		cmake:outsource cpe compiler:c++11-lang iconv:translit jpeg \
		perl5 pkgconfig shared-mime-info tar:xz
CMAKE_ARGS=	-DCMAKE_INCLUDE_PATH:STRING="${QT_INCDIR} ${LOCALBASE}/include" \
		-DPRODUCTSET:STRING="DESKTOP"
USE_LDCONFIG=	yes

PLIST_SUB+=     SHLIB_VER=14.0.0 \
                SHLIB_SHVER=14

OPTIONS_DEFINE=	GMIC MARBLE MYSQL PGSQL SYBASE
OPTIONS_DEFAULT=MARBLE MYSQL PGSQL
OPTIONS_SUB=	yes

# GMIC does not mix well with clang as compiler. It needs >20GB of memory to be
# built, which is not sensible on most systems
# See bug report: https://llvm.org/bugs/show_bug.cgi?id=22199
GMIC_DESC=	Build the G'Mic plugin (needs lots and lots of RAM)
GMIC_CMAKE_ON=	-DWITH_GMIC:BOOL=ON
GMIC_CMAKE_OFF=	-DWITH_GMIC:BOOL=OFF

MARBLE_DESC=	World globe widget support via Marble
MARBLE_USE=	KDE4=marble
MARBLE_CMAKE_OFF=-DWITH_Marble:BOOL=FALSE

MYSQL_DESC=	MySQL database support in Kexi
MYSQL_USE=	MYSQL=yes
MYSQL_CMAKE_OFF=-DWITH_MySQL:BOOL=FALSE

PGSQL_DESC=	PostgreSQL database support in Kexi
PGSQL_LIB_DEPENDS=libpqxx-3.1.so:${PORTSDIR}/databases/postgresql-libpqxx3
PGSQL_USES=	pgsql
PGSQL_CMAKE_OFF=-DWITH_PostgreSQL:BOOL=FALSE

SYBASE_DESC=	Sybase database support in Kexi
SYBASE_LIB_DEPENDS=libsybdb.so:${PORTSDIR}/databases/freetds
SYBASE_CMAKE_OFF=-DWITH_FreeTDS:BOOL=FALSE

post-patch:
# They require memalign() to build; as they're not installed, they're just a
# waste of CPU cycles.
	@${REINPLACE_CMD} -e '/add_subdirectory.*benchmarks/ d' \
		${PATCH_WRKSRC}/krita/CMakeLists.txt
# Prevent updating MIME during build/install.
	@${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d' \
		${PATCH_WRKSRC}/filters/libmsooxml/CMakeLists.txt \
		${PATCH_WRKSRC}/filters/plan/mpxj/import/CMakeLists.txt \
		${PATCH_WRKSRC}/filters/stage/keynote/import/CMakeLists.txt \
		${PATCH_WRKSRC}/filters/words/wiki/CMakeLists.txt \
		${PATCH_WRKSRC}/krita/data/CMakeLists.txt \
		${PATCH_WRKSRC}/krita/plugins/formats/ora/CMakeLists.txt \
		${PATCH_WRKSRC}/krita/plugins/formats/ora/CMakeLists.txt \
		${PATCH_WRKSRC}/plugins/vectorshape/CMakeLists.txt

.include <bsd.port.mk>
