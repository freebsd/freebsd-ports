# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	notification-daemon
PORTVERSION=	0.3.7
PORTREVISION=	19
CATEGORIES=	deskutils xfce
MASTER_SITES=	CRITICAL/
PKGNAMEPREFIX=	xfce4-
DISTNAME=	${PORTNAME}-xfce-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Port of Gnome's notification-daemon for the Xfce desktop

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	libsexy.so:${PORTSDIR}/x11-toolkits/libsexy \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	dbus-daemon:${PORTSDIR}/devel/dbus

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USES=		gmake pkgconfig tar:bzip2
USE_GNOME=	librsvg2
USE_LDCONFIG=	yes
USE_XFCE=	configenv libutil libgui

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/xfce4 \
			--libexecdir=${PREFIX}/libexec/xfce4 \
			--with-dbus-services=${PREFIX}/share/dbus-1/services

CONFLICTS=	notification-daemon-[0-9]* xfce4-notifyd-[0-9]* notify-osd-[0-9]*

OPTIONS_DEFINE=	GRADIENT CLOSE NLS

GRADIENT_DESC=	Show a gradient look in the default theme
CLOSE_DESC=	Show the close button in the default theme

OPTIONS_DEFAULT=CLOSE NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MGRADIENT}
CONFIGURE_ARGS+=	--enable-gradient-look
.endif

.if ${PORT_OPTIONS:MCLOSE}
CONFIGURE_ARGS+=	--disable-close-button
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\(notification-daemon-xfce\)-1.0|\1|' \
		${WRKSRC}/src/daemon/Makefile.am \
		${WRKSRC}/src/daemon/Makefile.in \
		${WRKSRC}/src/themes/bubble/Makefile.am \
		${WRKSRC}/src/themes/bubble/Makefile.in \
		${WRKSRC}/src/themes/standard/Makefile.am \
		${WRKSRC}/src/themes/standard/Makefile.in
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e 's|\(USE_NLS=\)yes|\1no|' ${WRKSRC}/configure
.endif

.include <bsd.port.mk>
