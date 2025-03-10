PORTNAME=	massif-visualizer
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Graphical viewer for Massif data
WWW=		https://apps.kde.org/massif_visualizer/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${kgraphviewer_DEPENDS}
LIB_DEPENDS=	libKChart6.so:graphics/kdiagram-qt6
RUN_DEPENDS=	${kgraphviewer_DEPENDS}

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gettext \
		kde:6 qt:6 shared-mime-info tar:xz

USE_KDE=	archive config coreaddons i18n kio parts \
		ecm:build
USE_QT=		5compat base svg

kgraphviewer_DEPENDS=	${QT_PLUGINDIR}/kf6/parts/kgraphviewerpart.so:graphics/kgraphviewer

.include <bsd.port.mk>
