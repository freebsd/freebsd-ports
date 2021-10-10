# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	gnome-dictionary
PORTVERSION=	40.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 dictionary lookup application

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.libs

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
		itstool:textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson pkgconfig tar:xz
USE_GNOME=	cairo gtk30 introspection:build libxslt:build
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.dictionary.gschema.xml

.include <bsd.port.mk>
