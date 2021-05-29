# Created by: Andrey Zakhvatov

PORTNAME=	genius
DISTVERSION=	1.0.26
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME \
		http://ftp.5z.com/pub/genius/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Arbitrary precision calculator for Gnome Desktop Environment

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rarian-sk-config:textproc/rarian
LIB_DEPENDS=	libamtk-5.so:x11-toolkits/amtk \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgmp.so:math/gmp \
		libharfbuzz.so:print/harfbuzz \
		libmpfr.so:math/mpfr
RUN_DEPENDS=	rarian-sk-config:textproc/rarian

USES=		desktop-file-utils gmake gnome libtool pathfix pkgconfig \
		readline shared-mime-info tar:xz xorg
USE_GNOME=	cairo gnomeprefix gtksourceview4 intltool vte3
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
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
