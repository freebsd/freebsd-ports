PORTNAME=	gnubg
PORTVERSION=	1.08.003
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	GNU
DISTFILES=	gnubg-release-${PORTVERSION}-sources.tar.gz

MAINTAINER=	cs@FreeBSD.org
COMMENT=	GNU Backgammon
WWW=		https://www.gnu.org/software/gnubg/

LICENSE=	GPLv3

RUN_DEPENDS=	sqlite3:databases/sqlite3
LIB_DEPENDS=	libcanberra-gtk.so:audio/libcanberra-gtk2 \
		libcanberra.so:audio/libcanberra \
		libcurl.so:ftp/curl \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgmp.so:math/gmp \
		libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libharfbuzz.so:print/harfbuzz \
		libpng16.so:graphics/png

USES=		bison gl gmake gnome libtool pathfix shebangfix python \
		pkgconfig compiler:c++11-lang xorg ncurses readline
USE_GNOME=	glib20 gtk20 cairo pangox-compat gdkpixbuf
USE_XORG+=	xmu xt sm ice x11
USE_GL+=	glu gl

CONFIGURE_ARGS=	--with-board3d --with-sqlite --with-python=${PYTHON_CMD}
CONFIGURE_ENV=	ac_cv_path_ARTSC_CONFIG=no ac_cv_path_LIBART_CONFIG=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes

ICON_THEMES+=	gnubg
DESKTOP_ENTRIES="GNU Backgammon" "A Backgammon application" \
		"${DATADIR}/pixmaps/gnubg-big.png" \
		"gnubg" "Application;Game;BoardGame;" \
		false

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
