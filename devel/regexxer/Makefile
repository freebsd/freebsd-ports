# Created by: Rui Lopes <rui@ruilopes.com>
# $FreeBSD$

PORTNAME=	regexxer
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	devel textproc gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Interactive tool for performing search and replace operations

USES=		gettext gmake pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix intltool intlhack gtkmm30 gtksourceviewmm3
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.regexxer.gschema.xml

.include <bsd.port.mk>
