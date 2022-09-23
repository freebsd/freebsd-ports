PORTNAME=	kiten
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	japanese education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Japanese reference/study tool for KDE
WWW=		https://edu.kde.org/kiten

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth archive codecs completion config configwidgets coreaddons \
		crash doctools i18n jobwidgets js khtml kio notifications \
		parts service sonnet textwidgets widgetsaddons xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
