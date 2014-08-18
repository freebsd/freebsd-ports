# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/anjuta-extras/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	anjuta-extras
PORTVERSION=	3.6.0
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extra anjuta 3 plugins

LIB_DEPENDS=	libanjuta-3.so:${PORTSDIR}/devel/anjuta
		
USES=		gettext gmake pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk30 intltool libxml2
CPPFLAGS+=	-I${LOCALBASE}/include 
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.anjuta.plugins.scintilla.gschema.xml \
		org.gnome.anjuta.plugins.scratchbox.gschema.xml

post-patch:
		@${REINPLACE_CMD} -e 's|return style_data|return|g' \
			${WRKSRC}/plugins/scintilla/style-editor.c

.include <bsd.port.mk>
