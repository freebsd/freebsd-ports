PORTNAME=	kosmindoormap
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	astro kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library and QML component for rendering multi-level OSM indoor maps
WWW=		https://marble.kde.org/

LIB_DEPENDS=	libprotobuf.so:devel/protobuf \
		libKOpeningHours.so:devel/kopeninghours

USES=		bison cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	coreaddons i18n kirigami2 kpublictransport service \
		ecm:build
USE_QT=		base

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
