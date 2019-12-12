# $FreeBSD$

PORTNAME=	libkgeomap
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	astro kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE library for browsing photos on a map

LICENSE=	GPLv2+ BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/COPYING-CMAKE-SCRIPTS

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/buffer_concepts.hpp:devel/boost-libs
LIB_DEPENDS=	libopencv_video.so:graphics/opencv

USES=		cmake compiler:c++11-lang gettext kde:5 pkgconfig \
		qt:5 tar:xz
USE_KDE=	config coreaddons ecm i18n kio marble service textwidgets
USE_QT=		concurrent core dbus declarative gui location network \
		printsupport webchannel webengine webkit widgets xml \
		buildtools_build qmake_build

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
