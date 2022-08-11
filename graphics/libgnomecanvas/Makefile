PORTNAME=	libgnomecanvas
PORTVERSION=	2.30.3
PORTREVISION?=	6
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graphics library for GNOME

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES+=		gettext gmake gnome libtool localbase pathfix pkgconfig tar:bzip2
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk20 intltool libartlgpl2 pango
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-glade \
		--disable-gtk-doc
INSTALL_TARGET=	install-strip

post-install:
		${RMDIR} ${STAGEDIR}${PREFIX}/lib/libglade/2.0
		${RMDIR} ${STAGEDIR}${PREFIX}/lib/libglade

.include <bsd.port.mk>
