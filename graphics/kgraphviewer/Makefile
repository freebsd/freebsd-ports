PORTNAME=	kgraphviewer
DISTVERSION=	2.4.3
PORTREVISION=	8
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Graphs-viewer for GraphViz files
WWW=		https://extragear.kde.org/apps/kgraphviewer/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/concept_check.hpp:devel/boost-libs
LIB_DEPENDS=	libgvc.so:graphics/graphviz

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 qt:5 tar:xz \
		pkgconfig xorg
USE_KDE=	auth codecs completion config configwidgets \
		coreaddons i18n iconthemes jobwidgets kio parts service \
		solid sonnet textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build doctools:build
USE_QT=		concurrent core dbus gui network printsupport svg widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
