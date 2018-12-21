# Created by: alanp@unixpower.org
# $FreeBSD$

PORTNAME=	logjam
PORTVERSION=	4.6.2
PORTREVISION=	5
CATEGORIES=	deskutils
MASTER_SITES=	http://andy-shev.github.com/LogJam/download/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	GTK2 interface to livejournals, ie www.livejournal.com

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libdbus-glib-1.so:devel/dbus-glib

OPTIONS_DEFINE=	GTKSPELL SQLITE GTKHTML RSVG
OPTIONS_DEFAULT=	GTKSPELL
OPTIONS_SUB=	yes

GTKSPELL_DESC=	Support spell checking
GTKHTML_DESC=	Support rendering HTML
RSVG_DESC=	Support rendering SVG
SQLITE_DESC=	Use sqlite3 as a backend

USES=		gettext gmake pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gtk20 libxml2 intlhack
CONFIGURE_ARGS=	--program-transform-name="s/$$//"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

GTKSPELL_LIB_DEPENDS=	libgtkspell.so:textproc/gtkspell
GTKSPELL_CONFIGURE_WITH=	gtkspell

SQLITE_CONFIGURE_WITH=	sqlite3
SQLITE_LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

GTKHTML_USE=	GNOME=gtkhtml3
GTKHTML_CONFIGURE_WITH=	gtkhtml

RSVG_USE=	GNOME=librsvg2
RSVG_CONFIGURE_WITH=	librsvg

post-patch:
	@${REINPLACE_CMD} -e 's|libgtkhtml-3.0|libgtkhtml-3.18|g' ${WRKSRC}/configure

.include <bsd.port.mk>
