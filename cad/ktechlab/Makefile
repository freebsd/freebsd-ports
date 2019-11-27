# $FreeBSD$

PORTNAME=	ktechlab
DISTVERSIONPREFIX=	v
DISTVERSION=	0.40.1-66
DISTVERSIONSUFFIX=	-gd5096083
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	IDE for microcontrollers and electronics

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgpsim.so:misc/gpsim

USES=		cmake desktop-file-utils gnome kde:5 localbase qt:5 shared-mime-info
USE_GITHUB=	yes
USE_QT=		concurrent core dbus gui network printsupport widgets xml \
		qmake_build buildtools_build
USE_KDE=	auth bookmarks codecs completion config configwidgets coreaddons \
		crash guiaddons i18n iconthemes itemviews jobwidgets js \
		kdelibs4support khtml kio notifications parts service solid \
		sonnet texteditor textwidgets unitconversion widgetsaddons windowsystem xmlgui
USE_GNOME=	glib20

CXXFLAGS+=	-I${LOCALBASE}/lib/glib-2.0/include

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

.include <bsd.port.mk>
