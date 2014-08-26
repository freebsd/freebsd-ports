# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	notify-osd
PORTVERSION=	0.9.29
PORTREVISION=	7
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpadlibrarian.net/43419242/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	On-screen-display notification agent using libnotify

LICENSE=	GPLv3

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libnotify.so:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	dbus-daemon:${PORTSDIR}/devel/dbus

CONFLICTS=	xfce4-notification-daemon-[0-9]*

GNU_CONFIGURE=	yes
USES=		gmake libtool pkgconfig
USE_GNOME=	libwnck gconf2
USE_XORG=	pixman x11

LIBS+=		-L${LOCALBASE}/lib -lpixman-1 -lX11

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} '/SUBDIRS =/s/tests//' ${WRKSRC}/Makefile.in
.if ${OSVERSION} < 900033
	@${REINPLACE_CMD} 's/-Bsymbolic-functions/-Bsymbolic/' \
		${WRKSRC}/src/Makefile.in
.endif

.include <bsd.port.mk>
