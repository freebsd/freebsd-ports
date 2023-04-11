PORTNAME=	ktechlab
DISTVERSIONPREFIX=	v
DISTVERSION=	0.51.0
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	IDE for microcontrollers and electronics
WWW=		https://userbase.kde.org/KTechlab

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgpsim.so:misc/gpsim

USES=		cmake compiler:c++11-lang desktop-file-utils gnome kde:5 \
		localbase qt:5 shared-mime-info xorg
USE_GITHUB=	yes
USE_QT=		concurrent core dbus gui network printsupport serialport widgets xml \
		qmake:build buildtools:build
USE_KDE=	auth bookmarks codecs completion config configwidgets coreaddons \
		crash guiaddons i18n iconthemes init itemviews jobwidgets js \
		kdelibs4support khtml kio notifications parts service solid \
		sonnet syntaxhighlighting texteditor textwidgets unitconversion \
		widgetsaddons windowsystem xmlgui \
		doctools:build
USE_GNOME=	glib20
USE_XORG=	x11

CXXFLAGS+=	-I${LOCALBASE}/lib/glib-2.0/include

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

PORTSCOUT=	limit:^\d+\. # prevent alpha-numeric strings

.include <bsd.port.mk>
