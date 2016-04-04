# Created by: Mark Reidel <ports@mark.reidel.info>
# $FreeBSD$

PORTNAME=	gmpc
PORTVERSION=	11.8.16
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full featured GTK2 client for musicpd

BUILD_DEPENDS=	gob2:devel/gob2 \
		valac:lang/vala
LIB_DEPENDS=	libmpd.so:audio/libmpd \
		libsexy.so:x11-toolkits/libsexy \
		libsqlite3.so:databases/sqlite3 \
		libsoup-2.4.so:devel/libsoup \
		libunique-1.0.so:x11-toolkits/unique

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool pathfix pkgconfig
USE_GNOME=	glib20 gtk20 intltool libglade2
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-system-libsexy
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm

OPTIONS_DEFINE=	MMKEYS XSPF
OPTIONS_DEFAULT=	MMKEYS

MMKEYS_CONFIGURE_ON=--disable-mmkeys

XSPF_LIB_DEPENDS=	libxspf.so:multimedia/libxspf
XSPF_CONFIGURE_ENABLE=	libxspf

.include <bsd.port.mk>
