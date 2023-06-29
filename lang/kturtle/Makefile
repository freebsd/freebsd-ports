PORTNAME=	kturtle
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	lang education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Educational programming environment for KDE
WWW=		https://edu.kde.org/kturtle

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	attica auth codecs config configwidgets coreaddons crash \
		emoticons i18n init itemmodels kio newstuff \
		service sonnet textwidgets widgetsaddons xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus gui network printsupport svg widgets xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
