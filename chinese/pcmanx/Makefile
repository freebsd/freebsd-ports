# New ports collection makefile for:   pcmanx
# Date created:                2005/07/16
# Whom:                        chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pcmanx
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	chinese net gnome
MASTER_SITES=	http://pcmanx-gtk2.googlecode.com/files/
DISTNAME=	${PORTNAME}-gtk2-${PORTVERSION}

MAINTAINER=	linpc@cs.nctu.edu.tw
COMMENT=	BBS client using GTK+ 2.x

LICENSE=	GPLv2

USE_XZ=		yes
USE_GNOME=	gtk20 intlhack
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NLS DEBUG DOCKLET NOTIFIER LIBNOTIFY NANCY MOUSE EXTERNAL IPLOOKUP PROXY
OPTIONS_DEFAULT=	DOCKLET NOTIFIER NANCY MOUSE EXTERNAL

DOCKLET_DESC=	Docklet / system tray support
NOTIFIER_DESC=	Popup notifier support
LIBNOTIFY_DESC=	Popup notifier support by libnotify
NANCY_DESC=	Nancy bot support
MOUSE_DESC=	Mouse click and wheel support
EXTERNAL_DESC=	External SSH/Telnet support
IPLOOKUP_DESC=	IP location lookup support
PROXY_DESC=	Proxy support

MAN1=		pcmanx.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

.if empty(PORT_OPTIONS:MDOCKLET)
CONFIGURE_ARGS+=--disable-docklet
.endif

.if empty(PORT_OPTIONS:MNOTIFIER)
CONFIGURE_ARGS+=--disable-notifier
.endif

.if ${PORT_OPTIONS:MLIBNOTIFY}
CONFIGURE_ARGS+=--enable-libnotify
BUILD_DEPENDS=	libnotify>0:${PORTSDIR}/devel/libnotify
.endif

.if empty(PORT_OPTIONS:MNANCY)
CONFIGURE_ARGS+=--disable-nancy
.endif

.if empty(PORT_OPTIONS:MMOUSE)
CONFIGURE_ARGS+=--disable-mouse
.endif

.if empty(PORT_OPTIONS:MEXTERNAL)
CONFIGURE_ARGS+=--disable-external
.endif

.if ${PORT_OPTIONS:MIPLOOKUP}
CONFIGURE_ARGS+=--enable-iplookup
.endif

.if ${PORT_OPTIONS:MPROXY}
CONFIGURE_ARGS+=--enable-proxy
.endif

.include <bsd.port.mk>
