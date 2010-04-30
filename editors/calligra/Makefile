# New ports collection makefile for:	koffice-kde4
# Date created:		2008-07-22
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	koffice
PORTVERSION=	2.1.0
PORTREVISION=	5
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}-${PORTVERSION}/
PKGNAMESUFFIX=	-kde4
DIST_SUBDIR=	KDE/koffice

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Office suite for KDE

BUILD_DEPENDS=	eigen>=2.0.b3:${PORTSDIR}/math/eigen2 \
		gmm++>=3.0.4:${PORTSDIR}/math/gmm++
LIB_DEPENDS=	GraphicsMagick++.1:${PORTSDIR}/graphics/GraphicsMagick \
		exiv2.7:${PORTSDIR}/graphics/exiv2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		freetype.9:${PORTSDIR}/print/freetype2 \
		lcms.1:${PORTSDIR}/graphics/lcms \
		poppler-qt4.3:${PORTSDIR}/graphics/poppler-qt4 \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		wpg-0.1:${PORTSDIR}/graphics/libwpg \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz \
		boost_thread.4:${PORTSDIR}/devel/boost-libs \
		qca.2:${PORTSDIR}/devel/qca \
		gsl:${PORTSDIR}/math/gsl \
		wv2.4:${PORTSDIR}/textproc/wv2 \
		kipi.6:${PORTSDIR}/graphics/kdegraphics4

USE_BZIP2=	yes
USE_CMAKE=	yes
MAKE_JOBS_UNSAFE=	yes
KDE4_BUILDENV=	yes
USE_KDE4=	kdelibs pimlibs kdehier kdeprefix sharedmime automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib phonon qmake_build moc_build porting_build rcc_build uic_build \
		uic3_build
USE_GL=		glut glew
USE_LDCONFIG=	yes

CMAKE_VERBOSE=	yes
CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:STRING="${QT_INCDIR} ${LOCALBASE}/include"

OPTIONS=	GTL	"Color transformations in Krita (currently broken)" off

.include <bsd.port.pre.mk>

WITHOUT_GTL=	yes
.if !defined(WITHOUT_GTL) || exists (${LOCALBASE}/lib/libQtShiva.so)
LIB_DEPENDS+=	OpenCTL.0:${PORTSDIR}/graphics/opengtl \
		QtShiva.0:${PORTSDIR}/graphics/qtgtl
PLIST_SUB+=	GTL=""
.else
PLIST_SUB+=	GTL="@comment "
.endif

.if exists(${LOCALBASE}/lib/pstoedit/libp2edrvlplot.so)
BUILD_DEPENDS+=	${LOCALBASE}/lib/pstoedit/libp2edrvlplot.so:${PORTSDIR}/graphics/pstoedit
RUN_DEPENDS+=	${LOCALBASE}/lib/pstoedit/libp2edrvlplot.so:${PORTSDIR}/graphics/pstoedit
PLIST_SUB+=	EPS=""
.else
PLIST_SUB+=	EPS="@comment "
.endif

post-patch:
# prevent updating mime during build/install
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/d; /SharedMimeInfo/d' \
		${PATCH_WRKSRC}/krita/plugins/formats/ora/CMakeLists.txt
	${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		${PATCH_WRKSRC}/cmake/modules/FindWPD.cmake
	${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|' \
		${PATCH_WRKSRC}/cmake/modules/FindGLEW.cmake
	${REINPLACE_CMD} -e 's|/opt/local|${LOCALBASE}|' \
		${PATCH_WRKSRC}/cmake/modules/FindImageMagick.cmake

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>
