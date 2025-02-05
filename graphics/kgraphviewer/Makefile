PORTNAME=	kgraphviewer
DISTVERSION=	2.5.0
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Graphs-viewer for GraphViz files
WWW=		https://apps.kde.org/kgraphviewer/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/concept_check.hpp:devel/boost-libs
LIB_DEPENDS=	libgvc.so:graphics/graphviz

USES=		cmake compiler:c++11-lang desktop-file-utils gettext \
		kde:6 pkgconfig qt:6 tar:xz xorg
USE_KDE=	coreaddons i18n parts widgetsaddons \
		ecm:build doctools:build
USE_QT=		5compat base svg \
		tools:build
USE_XORG=	x11

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

.include <bsd.port.mk>
