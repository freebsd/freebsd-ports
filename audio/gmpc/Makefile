# New ports collection makefile for:	gmpc
# Date created:		May 12 2004
# Whom:			Mark Reidel <ports@mark.reidel.info>
#
# $FreeBSD$
#

PORTNAME=	gmpc
PORTVERSION=	0.18.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Full featured GTK2 client for musicpd

BUILD_DEPENDS=	gob2:${PORTSDIR}/devel/gob2
LIB_DEPENDS=	mpd:${PORTSDIR}/audio/libmpd \
		curl.5:${PORTSDIR}/ftp/curl \
		soup-2.4.1:${PORTSDIR}/devel/libsoup

GNU_CONFIGURE=	yes
USE_XORG=	x11 sm
USE_GMAKE=	yes
USE_GNOME=	libglade2 gnomevfs2 gnomehack
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	gmpc-remote.1 gmpc.1

OPTIONS=	SESSION "Enable session support" on \
		MMKEYS "Enable multimedia keys support" on \
		TRAY "Enable tray icon support" on

.include <bsd.port.pre.mk>

pre-configure:
.if defined(WITHOUT_SESSION)
CONFIGURE_ARGS+=	--disable-sm
.endif

.if defined(WITHOUT_MMKEYS)
CONFIGURE_ARGS+=	--disable-mmkeys
.endif

.if defined(WITHOUT_TRAY)
CONFIGURE_ARGS+=	--disable-trayicon
.endif

.include <bsd.port.post.mk>
