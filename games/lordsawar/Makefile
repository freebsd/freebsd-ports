# $FreeBSD$

PORTNAME=	lordsawar
PORTVERSION=	0.3.0
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Warlords II clone

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib gettext gmake libarchive pkgconfig
USE_GNOME=	gtkmm30 intltool libxslt
USE_GSTREAMER=	mm
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
