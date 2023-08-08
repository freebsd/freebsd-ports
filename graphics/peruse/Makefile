PORTNAME=	peruse
DISTVERSION=	1.80
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Comic book viewer
WWW=		https://peruse.kde.org/

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lang gl pkgconfig kde:5 qt:5 tar:xz xorg
USE_GL=		gl
USE_KDE=	archive attica baloo completion config coreaddons crash ecm \
		filemetadata guiaddons i18n iconthemes jobwidgets \
		kdeclarative kio newstuff package service solid \
		widgetsaddons windowsystem
USE_QT=		concurrent core dbus declarative gui network opengl sql widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
