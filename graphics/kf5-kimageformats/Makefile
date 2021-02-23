# $FreeBSD$

PORTNAME=	kimageformats
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	5
CATEGORIES=	graphics kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library providing support for additional image formats

LIB_DEPENDS=	libHalf.so:graphics/ilmbase

USES=		cmake compiler:c++11-lib kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	archive ecm
USE_QT=		core gui printsupport widgets \
		buildtools_build qmake_build

OPTIONS_DEFINE=	AVIF OPENEXR
OPTIONS_DEFAULT=	AVIF OPENEXR
OPTIONS_SUB=	yes

AVIF_DESC=		AV1 Image File Format via libavif
AVIF_LIB_DEPENDS=	libavif.so:graphics/libavif
AVIF_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_libavif

OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/openexr
OPENEXR_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_OpenEXR

.include <bsd.port.mk>
