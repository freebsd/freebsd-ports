PORTNAME=	genius
DISTVERSION=	1.0.27
PORTREVISION=	5
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME \
		http://ftp.5z.com/pub/genius/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Arbitrary precision calculator for Gnome Desktop Environment
WWW=		https://www.jirka.org/genius.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgmp.so:math/gmp \
		libharfbuzz.so:print/harfbuzz \
		libmpfr.so:math/mpfr

USES=		desktop-file-utils gmake gnome libtool pkgconfig \
		readline shared-mime-info tar:xz xorg
USE_GNOME=	cairo gnomeprefix gdkpixbuf gtksourceview4 intltool vte3
USE_XORG=	x11 xext
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-extra-gcc-optimization \
		--disable-scrollkeeper \
		--disable-update-mimedb
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
