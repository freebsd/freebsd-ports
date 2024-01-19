PORTNAME=	kdegraphics-thumbnailers
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Thumbnailers for various graphics file formats
WWW=		https://www.kde.org

LIB_DEPENDS=	 libqmobipocket.so:graphics/kdegraphics-mobipocket

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz xorg
USE_KDE=	archive completion config coreaddons jobwidgets libkdcraw \
		libkexiv2 kio service solid widgetsaddons windowsystem \
		ecm:build
USE_QT=		concurrent core dbus gui network widgets \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
