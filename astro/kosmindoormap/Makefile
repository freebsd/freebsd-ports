PORTNAME=	kosmindoormap
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	2
CATEGORIES=	astro kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library and QML component for rendering multi-level OSM indoor maps
WWW=		https://marble.kde.org/

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		bison cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	i18n kpublictransport \
		ecm:build
USE_QT=		core declarative gui network quick3d \
		buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
