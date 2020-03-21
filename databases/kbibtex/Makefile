# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kbibtex
DISTVERSION=	0.9.1
PORTREVISION=	4
CATEGORIES=	databases kde
MASTER_SITES=	KDE/stable/KBibTeX/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Bibliography editor for KDE

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5 \
		libqoauth-qt5.so:net/qoauth-qt5

USES=		cmake compiler:c++11-lang desktop-file-utils gettext gnome \
		iconv kde:5 qca qt:5 shared-mime-info tar:xz
USE_GNOME=	libxml2 libxslt
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash ecm i18n iconthemes itemviews jobwidgets \
		kio parts service solid sonnet texteditor textwidgets wallet \
		widgetsaddons xmlgui
USE_QT=		concurrent core dbus declarative gui location network \
		printsupport webchannel widgets xml xmlpatterns \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	WEBENGINE
OPTIONS_DEFAULT_amd64=	WEBENGINE
OPTIONS_DEFAULT_i386=	WEBENGINE
OPTIONS_DEFAULT_powerpc64=	${OPTIONS_DEFAULT_powerpc64_${OSREL:R}}
OPTIONS_DEFAULT_powerpc64_13=	WEBENGINE

WEBENGINE_DESC=		Add dependency on qt5-webengine
WEBENGINE_USE=		QT=webengine
WEBENGINE_USE_OFF=	QT=webkit
WEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngineWidgets

.include <bsd.port.mk>
