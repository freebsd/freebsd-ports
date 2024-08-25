PORTNAME=	libkcddb
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	audio kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE CDDB library
WWW=		https://www.kde.org/

LIB_DEPENDS=	libmusicbrainz5.so:audio/libmusicbrainz5

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets \
		coreaddons i18n jobwidgets kcmutils kio service solid \
		widgetsaddons windowsystem \
		ecm:build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
