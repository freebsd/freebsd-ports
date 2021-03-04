# $FreeBSD$

PORTNAME=	kosmindoormap
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	astro kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library and QML component for rendering multi-level OSM indoor maps

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		bison cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	ecm i18n kpublictransport
USE_QT=		core declarative gui network quick3d \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
