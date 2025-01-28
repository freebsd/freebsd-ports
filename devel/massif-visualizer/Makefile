PORTNAME=	massif-visualizer
DISTVERSION=	0.8.24121
CATEGORIES=	devel kde

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Graphical viewer for Massif data
WWW=		https://apps.kde.org/massif_visualizer/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libKChart6.so:graphics/kdiagram-qt6

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gettext kde:6 \
		pkgconfig qt:6 shared-mime-info tar:xz xorg

USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		i18n jobwidgets kio parts service solid sonnet texteditor \
		textwidgets widgetsaddons windowsystem xmlgui ecm:build
KDE_INVENT=	5d616bea8ce2d8e2cc3cb51b30d077446633de30 sdk
USE_QT=		5compat svg
USE_XORG=	x11

.include <bsd.port.mk>
