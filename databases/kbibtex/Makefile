PORTNAME=	kbibtex
DISTVERSION=	0.10.0
PORTREVISION=	6
CATEGORIES=	databases kde
MASTER_SITES=	KDE/stable/KBibTeX/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Bibliography editor for KDE
WWW=		https://userbase.kde.org/KBibTeX

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5 \
		libqoauth-qt5.so:net/qoauth-qt5

USES=		cmake compiler:c++11-lang desktop-file-utils gettext gnome \
		iconv kde:5 pkgconfig qca qt:5 shared-mime-info tar:xz xorg
USE_GNOME=	libxml2 libxslt
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash i18n iconthemes itemviews jobwidgets kio \
		parts service solid sonnet syntaxhighlighting texteditor \
		textwidgets wallet widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus declarative gui location network \
		networkauth printsupport webchannel widgets xml xmlpatterns \
		buildtools:build qmake:build
USE_XORG=	x11
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	WEBENGINE
OPTIONS_DEFAULT_amd64=	WEBENGINE
OPTIONS_DEFAULT_i386=	WEBENGINE

WEBENGINE_DESC=		Add dependency on qt5-webengine
WEBENGINE_USE=		QT=webengine
WEBENGINE_USE_OFF=	QT=webkit
WEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngineWidgets

.include <bsd.port.mk>
