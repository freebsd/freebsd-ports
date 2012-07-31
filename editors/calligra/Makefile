# New ports collection makefile for:	calligra
# Date created:				28 May 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	calligra
PORTVERSION=	${CALLIGRA_VERSION}
PORTREVISION=	1
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${CALLIGRA_BRANCH}/${PORTNAME}-${PORTVERSION}/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE graphic art and office suite

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		boost_thread.4:${PORTSDIR}/devel/boost-libs \
		qca.2:${PORTSDIR}/devel/qca \
		exiv2.12:${PORTSDIR}/graphics/exiv2 \
		lcms2.2:${PORTSDIR}/graphics/lcms2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		freetype.9:${PORTSDIR}/print/freetype2 \
		wpd-0.9.9:${PORTSDIR}/textproc/libwpd \
		wpg-0.2:${PORTSDIR}/graphics/libwpg \
		poppler-qt4.3:${PORTSDIR}/graphics/poppler-qt4 \
		openjpeg.2:${PORTSDIR}/graphics/openjpeg \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		dcmdata.3:${PORTSDIR}/devel/dcmtk \
		fftw3.6:${PORTSDIR}/math/fftw3 \
		tiff.4:${PORTSDIR}/graphics/tiff \
		gsl.16:${PORTSDIR}/math/gsl
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen2.pc:${PORTSDIR}/math/eigen2

CONFLICTS=	koffice-kde4-2.*
CONFLICTS_BUILD=	qt-3.*

USE_GL=		glew
USE_GNOME=	glib20 libxml2 libxslt
USE_ICONV=	yes
USE_KDE4=	kdehier kdelibs kdeprefix libkdcraw okular pimlibs \
		automoc4 sharedmime soprano
USE_PERL5=	yes
USE_QT4=	dbus designer gui opengl phonon porting_build qt3support \
		qtestlib_build script sql svg webkit xml xmlpatterns \
		moc_build qmake_build rcc_build uic_build uic3_build
USE_SQLITE=	3
USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_OUTSOURCE=	yes
CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:STRING="${QT_INCDIR} ${LOCALBASE}/include" \
		-DBUILD_active:BOOL=FALSE \
		-DBUILD_mobile:BOOL=FALSE \
		-DIHAVEPATCHEDQT:BOOL=TRUE # To be removed with Qt 4.8.2.
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

OPTIONS=	GTL	"Color transformations in Krita (requires LLVM)" off \
		MARBLE	"Support for globe widget" on \
		MYSQL	"MySQL support in Kexi" on \
		PGSQL	"PostgreSQL support in Kexi" on \
		SYBASE	"SyBase support in Kexi" off

.if exists(${LOCALBASE}/lib/pstoedit/libp2edrvlplot.so)
BUILD_DEPENDS+=	${LOCALBASE}/lib/pstoedit/libp2edrvlplot.so:${PORTSDIR}/graphics/pstoedit
RUN_DEPENDS+=	${LOCALBASE}/lib/pstoedit/libp2edrvlplot.so:${PORTSDIR}/graphics/pstoedit
PLIST_SUB+=	EPS=""
.else
PLIST_SUB+=	EPS="@comment "
.endif

.include <bsd.port.options.mk>

.if defined(WITH_GTL) || exists(${LOCALBASE}/lib/libQtShiva.so)
LIB_DEPENDS+=	OpenCTL.0:${PORTSDIR}/graphics/opengtl \
		QtShiva.0:${PORTSDIR}/graphics/qtgtl
PLIST_SUB+=	GTL=""
.else
PLIST_SUB+=	GTL="@comment "
.endif

.if !defined(WITHOUT_MARBLE)
USE_KDE4+=	marble
CMAKE_ARGS+=	-DWITH_Marble:BOOL=TRUE
PLIST_SUB+=	MARBLE=""
.else
CMAKE_ARGS+=	-DWITH_Marble:BOOL=FALSE
PLIST_SUB+=	MARBLE="@comment "
.endif

.if !defined(WITHOUT_MYSQL) || exists(${LOCALBASE}/lib/mysql/libmysqlclient.so)
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if !defined(WITHOUT_PGSQL)
USE_PGSQL=	yes
BUILD_DEPENDS+=	${LOCALBASE}/lib/libpqxx.a:${PORTSDIR}/databases/postgresql-libpqxx3
RUN_DEPENDS+=	${LOCALBASE}/lib/libpqxx.a:${PORTSDIR}/databases/postgresql-libpqxx3
PLIST_SUB+=	PGSQL=""
.else
CMAKE_ARGS+=	-DWITH_PostgreSQL:BOOL=FALSE
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_SYBASE) || exists(${LOCALBASE}/lib/libsybdb.so)
LIB_DEPENDS+=	sybdb.5:${PORTSDIR}/databases/freetds
PLIST_SUB+=	SYBASE=""
.else
PLIST_SUB+=	SYBASE="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|' \
		${PATCH_WRKSRC}/cmake/modules/FindGLEW.cmake
	${REINPLACE_CMD} -e 's|/opt/local|${LOCALBASE}|' \
		${PATCH_WRKSRC}/cmake/modules/FindImageMagick.cmake
	${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		${PATCH_WRKSRC}/cmake/modules/FindWPD.cmake
	${REINPLACE_CMD} -e 's/^# *include  *< *malloc\.h *>/#include <stdlib.h>/' \
		${PATCH_WRKSRC}/kexi/kexidb/parser/sqlparser.cpp \
		${PATCH_WRKSRC}/kexi/kexidb/parser/sqlparser.y \
		${PATCH_WRKSRC}/plan/plugins/schedulers/rcps/libs/src/*.c
	# Prevent updating MIME during build/install.
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d; /SharedMimeInfo/ d' \
		${PATCH_WRKSRC}/filters/libmsooxml/CMakeLists.txt \
		${PATCH_WRKSRC}/krita/plugins/formats/ora/CMakeLists.txt

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
