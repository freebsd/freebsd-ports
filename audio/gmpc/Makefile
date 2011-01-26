# New ports collection makefile for:	gmpc
# Date created:		May 12 2004
# Whom:			Mark Reidel <ports@mark.reidel.info>
#
# $FreeBSD$
#

PORTNAME=	gmpc
PORTVERSION=	0.20.0
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Full featured GTK2 client for musicpd

BUILD_DEPENDS=	gob2:${PORTSDIR}/devel/gob2 \
		valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	mpd.3:${PORTSDIR}/audio/libmpd \
		sexy.2:${PORTSDIR}/x11-toolkits/libsexy \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		soup-2.4.1:${PORTSDIR}/devel/libsoup

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig glib20 gtk20 libglade2
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--enable-system-libsexy
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gmpc-remote.1 gmpc.1

OPTIONS=	MMKEYS "Enable multimedia keys support" on \
		XSPF "Enable support for XSPF playlists" off

.include <bsd.port.options.mk>

.if defined(WITHOUT_MMKEYS)
CONFIGURE_ARGS+=--disable-mmkeys
.endif

.if defined(WITH_XSPF)
LIB_DEPENDS+=	xspf.4:${PORTSDIR}/multimedia/libxspf
CONFIGURE_ARGS+=--enable-libxspf
.else
CONFIGURE_ARGS+=--disable-libxspf
.endif

.include <bsd.port.mk>
