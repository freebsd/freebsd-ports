PORTNAME=	libkipi
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Image Plugin Interface

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons ecm i18n \
		libkdcraw libkexiv2 service widgetsaddons xmlgui
USE_QT=		core dbus gui widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
