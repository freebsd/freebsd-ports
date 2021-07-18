# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>

PORTNAME=	gnubg
PORTVERSION=	1.06.002
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	GNU
DISTFILES=	gnubg-release-${PORTVERSION}-sources.tar.gz

MAINTAINER=	cs@FreeBSD.org
COMMENT=	GNU Backgammon

LICENSE=	GPLv3

RUN_DEPENDS=	sqlite3:databases/sqlite3
LIB_DEPENDS=	libpng.so:graphics/png \
		libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libcanberra-gtk.so:audio/libcanberra \
		libgmp.so:math/gmp \
		libcurl.so:ftp/curl \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		bison gl gmake gnome libtool pathfix shebangfix python \
		pkgconfig compiler:c++11-lang readline xorg
USE_GNOME=	glib20 gtk20 cairo pangox-compat
USE_XORG+=	xmu xt sm ice x11
USE_GL+=	glu gl

CONFIGURE_ARGS=	--with-board3d --with-sqlite --with-python=${PYTHON_CMD}
CONFIGURE_ENV=	ac_cv_path_ARTSC_CONFIG=no ac_cv_path_LIBART_CONFIG=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
