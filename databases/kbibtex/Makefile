PORTNAME=	kbibtex
DISTVERSION=	0.10.0
PORTREVISION=	7
CATEGORIES=	databases kde
MASTER_SITES=	KDE/stable/KBibTeX/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Bibliography editor for KDE
WWW=		https://userbase.kde.org/KBibTeX

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5

USES=		cmake compiler:c++11-lang desktop-file-utils gettext-tools \
		kde:5 pkgconfig qt:5 shared-mime-info tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash i18n iconthemes itemviews jobwidgets kio \
		parts service solid sonnet syntaxhighlighting texteditor \
		textwidgets wallet widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus gui location network networkauth \
		widgets xml xmlpatterns \
		buildtools:build qmake:build
USE_XORG=	x11
USE_LDCONFIG=	yes

OPTIONS_DEFINE=			WEBENGINE
OPTIONS_DEFAULT_aarch64=	WEBENGINE
OPTIONS_DEFAULT_amd64=		WEBENGINE
OPTIONS_DEFAULT_i386=		WEBENGINE

WEBENGINE_DESC=			Webpage rendering support
WEBENGINE_USE=			QT=declarative,printsupport,webchannel,webengine
WEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngineWidgets

.include <bsd.port.mk>
