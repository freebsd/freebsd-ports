PORTNAME=	showimage
PORTVERSION=	1.12
CATEGORIES=	graphics kde
MASTER_SITES=	LOCAL/jhale/showimage/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simple KDE based image viewer
WWW=		https://store.kde.org/p/1126798

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 qt:5 \
		tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons i18n itemviews jobwidgets kio libkipi purpose \
		service solid widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
