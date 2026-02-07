PORTNAME=	kgraphviewer
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Graphs-viewer for GraphViz files
WWW=		https://apps.kde.org/kgraphviewer/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/concept_check.hpp:devel/boost-libs
LIB_DEPENDS=	libgvc.so:graphics/graphviz

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-tools \
		kde:6 localbase pkgconfig qt:6 tar:xz xorg
USE_KDE=	coreaddons i18n parts widgetsaddons \
		ecm:build doctools:build
USE_QT=		5compat base svg \
		tools:build
USE_XORG=	x11

_${PORTNAME}_PROJECT_VERSION=	2.5
KDE_APPS_BASED_PATCHLEVEL=	${KDE_APPLICATIONS_VERSION:R:S/.//}${KDE_APPLICATIONS_VERSION:E}

.include <bsd.port.mk>
