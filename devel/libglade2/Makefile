# New ports collection makefile for:	libglade2
# Date created:				18 August 1999
# Whom:					Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#

PORTNAME=	libglade2
PORTVERSION=	2.4.1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.4
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME glade library

BUILD_DEPENDS=	${PYEXPAT}
RUN_DEPENDS=	${PYEXPAT} \
		xmlcatmgr:${PORTSDIR}/textproc/xmlcatmgr

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomehack libxml2 gtk20
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		XMLCATALOG="$(LOCALBASE)/share/xml/catalog.ports"

PLIST_SUB=	XMLCATALOG="${LOCALBASE}/bin/xmlcatalog" \
		CATALOG_PORTS_XML="${LOCALBASE}/share/xml/catalog.ports"

.include <bsd.port.mk>
