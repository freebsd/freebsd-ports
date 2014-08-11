# Created by: Mark Reidel <ports@mark.reidel.info>
# $FreeBSD$

PORTNAME=	gmpc
PORTVERSION=	11.8.16
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Full featured GTK2 client for musicpd

BUILD_DEPENDS=	gob2:${PORTSDIR}/devel/gob2 \
		valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libmpd.so:${PORTSDIR}/audio/libmpd \
		libsexy.so:${PORTSDIR}/x11-toolkits/libsexy \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique

GNU_CONFIGURE=	yes
USES=		gettext gmake libtool pathfix pkgconfig
USE_GNOME=	glib20 gtk20 libglade2
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-system-libsexy
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm

OPTIONS_DEFINE=	MMKEYS XSPF
OPTIONS_DEFAULT=	MMKEYS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMMKEYS}
CONFIGURE_ARGS+=--disable-mmkeys
.endif

.if ${PORT_OPTIONS:MXSPF}
LIB_DEPENDS+=	libxspf.so:${PORTSDIR}/multimedia/libxspf
CONFIGURE_ARGS+=--enable-libxspf
.else
CONFIGURE_ARGS+=--disable-libxspf
.endif

.include <bsd.port.mk>
