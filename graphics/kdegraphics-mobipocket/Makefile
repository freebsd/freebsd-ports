PORTNAME=	kdegraphics-mobipocket
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mobipocket plugins for Strigi indexing and thumbnails
WWW=		https://invent.kde.org/graphics/kdegraphics-mobipocket

USES=		cmake compiler:c++11-lang kde:6 qt:6 tar:xz
USE_KDE=	completion config coreaddons jobwidgets kio service solid \
		widgetsaddons windowsystem \
		ecm:build
USE_QT=		base
USE_LDCONFIG=	yes

.include <bsd.port.mk>
