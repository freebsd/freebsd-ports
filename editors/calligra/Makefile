# New ports collection makefile for:	koffice-kde4
# Date created:		2008-07-22
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	koffice
PORTVERSION=	2.3.3
PORTREVISION=	5
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KOFFICE2_BRANCH}/${PORTNAME}-${PORTVERSION}/
PKGNAMESUFFIX=	-kde4
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Office suite for KDE

BUILD_DEPENDS=	eigen>=2.0.b3:${PORTSDIR}/math/eigen2 \
		gmm++>=3.0.4:${PORTSDIR}/math/gmm++ \
		${LOCALBASE}/lib/libpqxx.a:${PORTSDIR}/databases/postgresql-libpqxx30
LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs \
		qca.2:${PORTSDIR}/devel/qca \
		GraphicsMagick++.1:${PORTSDIR}/graphics/GraphicsMagick \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		exiv2.10:${PORTSDIR}/graphics/exiv2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		kdcraw.20:${PORTSDIR}/graphics/libkdcraw-kde4 \
		lcms2.2:${PORTSDIR}/graphics/lcms2 \
		wpg-0.2:${PORTSDIR}/graphics/libwpg \
		png.6:${PORTSDIR}/graphics/png \
		poppler-qt4.3:${PORTSDIR}/graphics/poppler-qt4 \
		tiff.4:${PORTSDIR}/graphics/tiff \
		gsl.16:${PORTSDIR}/math/gsl \
		freetype.9:${PORTSDIR}/print/freetype2 \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		fftw3:${PORTSDIR}/math/fftw3 \
		dcmdata.3:${PORTSDIR}/devel/dcmtk \
		okularcore.1:${PORTSDIR}/graphics/okular
RUN_DEPENDS=	${LOCALBASE}/lib/libpqxx.a:${PORTSDIR}/databases/postgresql-libpqxx30

CONFLICTS=	calligra-[0-9]*

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_ICONV=	yes
USE_PGSQL=	yes
MAKE_JOBS_SAFE=	yes
USE_KDE4=	kdelibs pimlibs kdehier kdeprefix sharedmime automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib phonon qmake_build moc_build porting_build rcc_build uic_build \
		uic3_build
USE_GL=		glut glew
USE_LDCONFIG=	yes

CMAKE_OUTSOURCE=	yes

CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:STRING="${QT_INCDIR} ${LOCALBASE}/include"

LDFLAGS+=	"-L${LOCALBASE}/lib"

OPTIONS+=	GTL	"Color transformations in Krita" off
OPTIONS+=	SYBASE	"SyBase support in Kexi" off

.include <bsd.port.options.mk>

.if exists(${LOCALBASE}/include/qconfig.h)
IGNORE=	does not build with x11-toolkits/qt33 installed. Please deinstall qt-3.x first
.endif

.if !defined(WITHOUT_GTL) || exists (${LOCALBASE}/lib/libQtShiva.so)
LIB_DEPENDS+=	OpenCTL.0:${PORTSDIR}/graphics/opengtl \
		QtShiva.0:${PORTSDIR}/graphics/qtgtl
PLIST_SUB+=	GTL=""
.else
PLIST_SUB+=	GTL="@comment "
.endif

.if exists(${LOCALBASE}/lib/pstoedit/libp2edrvlplot.so)
QT_COMPONENTS+=	qt3support
BUILD_DEPENDS+=	${LOCALBASE}/lib/pstoedit/libp2edrvlplot.so:${PORTSDIR}/graphics/pstoedit
RUN_DEPENDS+=	${LOCALBASE}/lib/pstoedit/libp2edrvlplot.so:${PORTSDIR}/graphics/pstoedit
PLIST_SUB+=	EPS=""
.else
PLIST_SUB+=	EPS="@comment "
.endif

.if defined(WITH_SYBASE) || exists (${LOCALBASE}/lib/libsybdb.so)
LIB_DEPENDS+=	sybdb.5:${PORTSDIR}/databases/freetds
PLIST_SUB+=	SYBASE=""
.else
PLIST_SUB+=	SYBASE="@comment "
.endif

post-patch:
# prevent updating mime during build/install
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/d; /SharedMimeInfo/d' \
		${PATCH_WRKSRC}/krita/plugins/formats/ora/CMakeLists.txt
	${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|' \
		${PATCH_WRKSRC}/cmake/modules/FindGLEW.cmake
	${REINPLACE_CMD} -e 's|/opt/local|${LOCALBASE}|' \
		${PATCH_WRKSRC}/cmake/modules/FindImageMagick.cmake
	${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		${PATCH_WRKSRC}/cmake/modules/FindWPD.cmake

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
