# $FreeBSD$

PORTNAME=	kturtle
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	lang kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Educational programming environment for KDE

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	attica auth codecs config configwidgets coreaddons crash ecm \
		emoticons i18n init itemmodels kdelibs4support kio newstuff \
		service sonnet textwidgets widgetsaddons xmlgui
USE_QT=		core dbus gui network printsupport svg widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
