PORTNAME=	kdegraphics-mobipocket
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mobipocket plugins for Strigi indexing and thumbnails

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	completion config coreaddons ecm jobwidgets kio service \
		widgetsaddons
USE_QT=		concurrent core dbus gui network widgets \
		buildtools_build qmake_build

USE_LDCONFIG=	yes

.include <bsd.port.mk>
