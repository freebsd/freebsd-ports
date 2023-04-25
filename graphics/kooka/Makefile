PORTNAME=	kooka
DISTVERSION=	0.61-323
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Intuitive, easy to use open source scan program
WWW=		https://userbase.kde.org/Kooka

LICENSE=	GPLv2+

LIB_DEPENDS=	libpaper.so:print/libpaper \
		libsane.so:graphics/sane-backends \
		libtiff.so:graphics/tiff

USES=		cmake compiler:c++11-lang kde:5 pkgconfig qt:5 xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets coreaddons \
		ecm i18n iconthemes itemviews jobwidgets kio service solid sonnet \
		textwidgets widgetsaddons windowsystem xmlgui \
		doctools:build
USE_QT=		concurrent core dbus gui network printsupport widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

KDE_INVENT=	3ed25fb9a1a62b88240a4f0f403b1ad49cf0adeb

PORTSCOUT=	limit:^0\.

.include <bsd.port.mk>
