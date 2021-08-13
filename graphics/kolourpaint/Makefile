PORTNAME=	kolourpaint
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE paint program

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash emoticons guiaddons i18n iconthemes init \
		itemmodels itemviews jobwidgets kdelibs4support kio libkexiv2 \
		libksane notifications parts service solid sonnet textwidgets \
		unitconversion widgetsaddons windowsystem xmlgui \
		ecm_build
USE_QT=		dbus concurrent core gui network printsupport widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
