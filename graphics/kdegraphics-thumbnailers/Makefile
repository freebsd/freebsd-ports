PORTNAME=	kdegraphics-thumbnailers
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Thumbnailers for various graphics file formats
WWW=		https://www.kde.org

LIB_DEPENDS=	libQMobipocket6.so:graphics/kdegraphics-mobipocket

USES=		cmake compiler:c++11-lang kde:6 qt:6 tar:xz xorg
USE_KDE=	archive completion config coreaddons jobwidgets kio libkdcraw \
		libkexiv2 service solid widgetsaddons windowsystem \
		ecm:build
USE_QT=		base
USE_XORG=	x11

.include <bsd.port.mk>
