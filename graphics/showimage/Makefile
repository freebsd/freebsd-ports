PORTNAME=	showimage
PORTVERSION=	1.10
PORTREVISION=	6
CATEGORIES=	graphics kde
MASTER_SITES=	https://dl.opendesktop.org/api/files/download/id/1482097460/ \
		LOCAL/tcberner/showimage-0.10/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simple KDE based image viewer
WWW=		http://kde-apps.org/content/show.php/ShowImage?content=143977

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:bzip2 xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons ecm i18n itemviews jobwidgets kio service solid \
		widgetsaddons windowsystem xmlgui \
		doctools:build
USE_QT=		concurrent core dbus gui network xml widgets \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
