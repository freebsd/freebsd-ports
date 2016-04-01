# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	anjuta-extras
PORTVERSION=	3.10.0
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Extra anjuta 3 plugins

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libanjuta-3.so:devel/anjuta

USES=		gettext gmake libtool pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk30 intltool libxml2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.anjuta.plugins.scintilla.gschema.xml \
		org.gnome.anjuta.plugins.scratchbox.gschema.xml

post-patch:
		@${REINPLACE_CMD} -e 's|return style_data|return|g' \
			${WRKSRC}/plugins/scintilla/style-editor.c

.include <bsd.port.mk>
