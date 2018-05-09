# $FreeBSD$

PORTNAME=	libkgeomap
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	astro kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE library for browsing photos on a map

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/buffer_concepts.hpp:devel/boost-libs
LIB_DEPENDS=	libopencv_video.so:graphics/opencv

USES=		cmake:outsource gettext kde:5 pkgconfig tar:xz
USE_KDE=	config coreaddons ecm i18n kio marble service textwidgets
USE_QT5=	concurrent core gui network webkit widgets xml \
		buildtools_build qmake_build

USE_LDCONFIG=	yes

.include <bsd.port.mk>
