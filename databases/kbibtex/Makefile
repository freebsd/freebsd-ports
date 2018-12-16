# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kbibtex
DISTVERSION=	0.8.1
PORTREVISION=	2
CATEGORIES=	databases kde
MASTER_SITES=	KDE/stable/KBibTeX/${DISTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Bibliography editor for KDE

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libqca-qt5.so:devel/qca@qt5 \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5 \
		libqoauth-qt5.so:net/qoauth-qt5

USES=		cmake desktop-file-utils gettext iconv kde:5 qt:5 \
		shared-mime-info tar:xz
USE_GNOME=	libxml2 libxslt
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash ecm i18n iconthemes itemviews jobwidgets \
		kio parts service solid sonnet textwidgets wallet \
		widgetsaddons xmlgui
USE_QT=		concurrent core dbus declarative gui location network printsupport \
		webchannel webengine widgets xml xmlpatterns \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
