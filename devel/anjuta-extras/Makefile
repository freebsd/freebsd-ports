# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/anjuta-extras3/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTNAME=	anjuta-extras
PORTVERSION=	3.4.0
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extra anjuta 3 plugins

LIB_DEPENDS=	libanjuta-3.so:${PORTSDIR}/devel/anjuta
		
NO_STAGE=	yes
USE_XZ=		yes
USES=		gettext gmake pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	intltool libxml2 gtk30
CPPFLAGS+=	-I${LOCALBASE}/include 
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.anjuta.plugins.scintilla.gschema.xml \
		org.gnome.anjuta.plugins.scratchbox.gschema.xml

.include <bsd.port.mk>
