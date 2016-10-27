# $FreeBSD$

PORTNAME=	lordsawar
PORTVERSION=	0.3.1
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Warlords II clone

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib gettext gmake libarchive pkgconfig shebangfix
USE_GNOME=	gtkmm30 intltool libxslt
USE_GSTREAMER=	mm
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
SHEBANG_FILES=	create-lw-file

.include <bsd.port.mk>
