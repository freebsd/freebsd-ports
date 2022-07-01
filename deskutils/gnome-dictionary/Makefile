# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	gnome-dictionary
PORTVERSION=	40.0
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	87c026cfe4ac.patch:-p1 # meson 0.57
PATCHFILES+=	cf3f8a67cd6f.patch:-p1 # https://gitlab.gnome.org/GNOME/gnome-dictionary/-/merge_requests/18

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME dictionary lookup application

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
