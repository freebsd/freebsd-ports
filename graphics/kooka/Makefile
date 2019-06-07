# $FreeBSD$

PORTNAME=	kooka
DISTVERSION=	0.61-296
DISTVERSIONSUFFIX=	-g22e3bcd
PORTEPOCH=	1
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Intuitive, easy to use open source scan program

LICENSE=	GPLv2+

PORTSCOUT=	ignore:v4.0.71

LIB_DEPENDS=	libpaper.so:print/libpaper \
		libsane.so:graphics/sane-backends \
		libtiff.so:graphics/tiff

USES=		cmake compiler:c++11-lang kde:5 pkgconfig qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	KDE
USE_KDE=	auth bookmarks codecs completion config configwidgets coreaddons \
		ecm i18n iconthemes itemviews jobwidgets kio service solid sonnet \
		textwidgets widgetsaddons xmlgui
USE_QT=		concurrent core dbus gui network printsupport widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
