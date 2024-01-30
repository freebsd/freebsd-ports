PORTNAME=	kxstitch
DISTVERSION=	2.2.0
PORTREVISION=	6
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross stitch pattern editor
WWW=		https://kde.org/applications/graphics/kxstitch/

USES=		cmake compiler:c++11-lang desktop-file-utils magick:6 kde:5 qt:5 tar:xz \
		xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets coreaddons \
		i18n itemviews jobwidgets kio service solid sonnet textwidgets \
		widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus gui network printsupport widgets x11extras \
		xml \
		buildtools:build qmake:build
USE_XORG=	ice sm x11 xext

.include <bsd.port.mk>
