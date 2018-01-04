# $FreeBSD$

PORTNAME=	kimageformats
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	graphics kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library providing support for additional image formats

LIB_DEPENDS=	libHalf.so:graphics/ilmbase

USES=		cmake:outsource compiler:c++11-lib kde:5 pkgconfig tar:xz
USE_KDE=	archive ecm 
USE_QT5=	buildtools_build core gui printsupport qmake_build widgets

OPTIONS_DEFINE=	OPENEXR
OPTIONS_DEFAULT=	OPENEXR
OPTIONS_SUB=	yes

OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/OpenEXR
OPENEXR_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_OpenEXR

.include <bsd.port.mk>
