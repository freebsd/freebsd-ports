PORTNAME=	massif-visualizer
DISTVERSION=	0.8.0
CATEGORIES=	devel kde

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Graphical viewer for Massif data
WWW=		https://apps.kde.org/massif-visualizer/

LICENSE=		GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libKChart.so:graphics/kdiagram

USES=		cmake compiler:c++11-lang desktop-file-utils gettext \
			pkgconfig kde:5 qt:5 tar:xz cpe xorg shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	kde
GH_PROJECT=	massif-visualizer
GH_TAGNAME=	v0.7.0
USE_KDE= 	archive  auth  auth  codecs  completion  config  config  \
			configwidgets  coreaddons  i18n  jobwidgets  kio parts  service  \
			solid sonnet texteditor textwidgets  widgetsaddons  windowsystem  \
			xmlgui \
			ecm:build
USE_QT=		concurrent core dbus gui network printsupport svg widgets xml xmlpatterns \
			buildtools:build qmake:build testlib:build
USE_XORG=	x11

.include <bsd.port.mk>
