PORTNAME=	regexxer
PORTVERSION=	0.10
PORTREVISION=	9
CATEGORIES=	devel textproc gnome
MASTER_SITES=	GNOME

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive tool for performing search and replace operations
WWW=		https://regexxer.sourceforge.net/

USES=		compiler:c++11-lang gettext gmake gnome localbase pathfix \
		pkgconfig tar:xz
USE_CXXSTD=	c++11
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix intltool intlhack gtkmm30 gtksourceviewmm3

GLIB_SCHEMAS=	org.regexxer.gschema.xml

.include <bsd.port.mk>
