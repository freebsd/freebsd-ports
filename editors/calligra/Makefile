# $FreeBSD$

PORTNAME=	calligra
PORTVERSION=	${CALLIGRA_VERSION}
PORTREVISION=	3
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${CALLIGRA_BRANCH}/${PORTNAME}-${PORTVERSION}/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE graphic art and office suite

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		qca:${PORTSDIR}/devel/qca \
		exiv2:${PORTSDIR}/graphics/exiv2 \
		lcms2:${PORTSDIR}/graphics/lcms2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		freetype:${PORTSDIR}/print/freetype2 \
		wpd-0.9:${PORTSDIR}/textproc/libwpd \
		wpg-0.2:${PORTSDIR}/graphics/libwpg \
		poppler-qt4:${PORTSDIR}/graphics/poppler-qt4 \
		openjpeg:${PORTSDIR}/graphics/openjpeg \
		jpeg:${PORTSDIR}/graphics/jpeg \
		dcmdata:${PORTSDIR}/devel/dcmtk \
		fftw3:${PORTSDIR}/math/fftw3 \
		tiff:${PORTSDIR}/graphics/tiff \
		gsl:${PORTSDIR}/math/gsl \
		wps-0.2:${PORTSDIR}/textproc/libwps \
		visio-0.0:${PORTSDIR}/textproc/libvisio \
		OpenColorIO:${PORTSDIR}/graphics/opencolorio
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen2.pc:${PORTSDIR}/math/eigen2

CONFLICTS=	koffice-kde4-2.*
CONFLICTS_BUILD=qt-3.*

USE_GL=		glew
USE_GNOME=	glib20 libxml2 libxslt
USE_KDE4=	kactivities kdehier kdelibs kdeprefix libkdcraw nepomuk-core \
		okular pimlibs attica automoc4 sharedmime soprano
USE_QT4=	dbus designer_build gui opengl phonon porting_build qt3support \
		qtestlib_build script sql svg webkit xml xmlpatterns \
		moc_build qmake_build rcc_build uic_build uic3_build
USE_SQLITE=	3
USE_BZIP2=	yes
USES=		cmake:outsource pkgconfig iconv perl5
CMAKE_ARGS=	-DCMAKE_INCLUDE_PATH:STRING="${QT_INCDIR} ${LOCALBASE}/include" \
		-DIHAVEPATCHEDQT:BOOL=TRUE # To be removed with Qt 4.8.2.
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GTL MARBLE MYSQL PGSQL SYBASE
OPTIONS_DEFAULT=MARBLE MYSQL PGSQL

GTL_DESC=	Color transformations in Krita (requires LLVM)
MARBLE_DESC=	World globe widget support via Marble
MYSQL_DESC=	MySQL database support in Kexi
PGSQL_DESC=	PostgreSQL database support in Kexi
SYBASE_DESC=	Sybase database support in Kexi

.if exists(${LOCALBASE}/lib/pstoedit/libp2edrvlplot.so)
BUILD_DEPENDS+=	${LOCALBASE}/lib/pstoedit/libp2edrvlplot.so:${PORTSDIR}/graphics/pstoedit
RUN_DEPENDS+=	${LOCALBASE}/lib/pstoedit/libp2edrvlplot.so:${PORTSDIR}/graphics/pstoedit
PLIST_SUB+=	EPS=""
.else
PLIST_SUB+=	EPS="@comment "
.endif

.if defined(PACKAGE_BUILDING)
# Requires Vc (http://code.compeng.uni-frankfurt.de/projects/vc).
CMAKE_ARGS+=	-DWITH_PACKAGERS_BUILD:BOOL=TRUE
.else
CMAKE_ARGS+=	-DWITH_PACKAGERS_BUILD:BOOL=FALSE
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTL} || exists(${LOCALBASE}/lib/libQtShiva.so)
LIB_DEPENDS+=	OpenCTL:${PORTSDIR}/graphics/opengtl \
		QtShiva:${PORTSDIR}/graphics/qtgtl
PLIST_SUB+=	GTL=""
.else
PLIST_SUB+=	GTL="@comment "
.endif

.if ${PORT_OPTIONS:MMARBLE}
USE_KDE4+=	marble
PLIST_SUB+=	MARBLE=""
.else
CMAKE_ARGS+=	-DWITH_Marble:BOOL=FALSE
PLIST_SUB+=	MARBLE="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
.else
CMAKE_ARGS+=	-DWITH_MySQL:BOOL=FALSE
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
BUILD_DEPENDS+=	${LOCALBASE}/lib/libpqxx.a:${PORTSDIR}/databases/postgresql-libpqxx3
RUN_DEPENDS+=	${LOCALBASE}/lib/libpqxx.a:${PORTSDIR}/databases/postgresql-libpqxx3
PLIST_SUB+=	PGSQL=""
.else
CMAKE_ARGS+=	-DWITH_PostgreSQL:BOOL=FALSE
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSYBASE}
LIB_DEPENDS+=	sybdb:${PORTSDIR}/databases/freetds
PLIST_SUB+=	SYBASE=""
.else
CMAKE_ARGS+=	-DWITH_FreeTDS:BOOL=FALSE
PLIST_SUB+=	SYBASE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|' \
		${PATCH_WRKSRC}/cmake/modules/FindGLEW.cmake
	@${REINPLACE_CMD} -e 's|/opt/local|${LOCALBASE}|' \
		${PATCH_WRKSRC}/cmake/modules/FindImageMagick.cmake
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		${PATCH_WRKSRC}/cmake/modules/FindWPD.cmake
	@${REINPLACE_CMD} -e 's/^# *include  *< *malloc\.h *>/#include <stdlib.h>/' \
		${PATCH_WRKSRC}/libs/db/parser/sqlparser.cpp \
		${PATCH_WRKSRC}/libs/db/parser/sqlparser.y \
		${PATCH_WRKSRC}/plan/plugins/schedulers/rcps/libs/src/*.c
# They require memalign() to build; as they're not installed, they're just a
# waste of CPU cycles.
	@${REINPLACE_CMD} -e '/add_subdirectory.*benchmarks/ d' \
		${PATCH_WRKSRC}/krita/CMakeLists.txt
# Prevent updating MIME during build/install.
	@${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d; /SharedMimeInfo/ d' \
		${PATCH_WRKSRC}/filters/libmsooxml/CMakeLists.txt \
		${PATCH_WRKSRC}/krita/plugins/formats/ora/CMakeLists.txt

.include <bsd.port.mk>
