PORTNAME=	kdegraphics-thumbnailers
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Thumbnailers for various graphics file formats

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	archive completion config coreaddons ecm jobwidgets libkdcraw \
		libkexiv2 kio service widgetsaddons
USE_QT=		concurrent core dbus gui network widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
