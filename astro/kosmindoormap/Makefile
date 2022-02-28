PORTNAME=	kosmindoormap
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	astro kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library and QML component for rendering multi-level OSM indoor maps

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		bison cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	i18n kpublictransport \
		ecm_build
USE_QT=		core declarative gui network quick3d \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

# Override shared library version
KDE_APPLICATIONS_SHLIB_VER=	${KDE_APPLICATIONS_SHLIB_G_VER}

.include <bsd.port.mk>
