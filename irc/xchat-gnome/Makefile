# New ports collection makefile for:	xchat
# Date created:			17 Nov 1998
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		xchat
PORTVERSION=		1.5.5
CATEGORIES=		irc gnome
MASTER_SITES=		http://xchat.org/files/source/1.5/ \
			http://xchat.linuxpower.org/files/source/1.5/

MAINTAINER=		jim@FreeBSD.org

.if defined(WITH_SOCKS)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
.endif
LIB_DEPENDS=		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
			Imlib.5:${PORTSDIR}/graphics/imlib
.if defined(WITH_GNOME)
LIB_DEPENDS+=		gnome.4:${PORTSDIR}/x11/gnomelibs
.endif

.if exists(${X11BASE}/bin/panel) && defined(WITH_GNOME)
WITH_GDK_PIXBUF=	YES
WITH_PANEL=		YES
LIB_DEPENDS+=		panel_applet.4:${PORTSDIR}/x11/gnomecore
.endif

.if defined(WITH_GDK_PIXBUF)
LIB_DEPENDS+=		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
.endif

GTK_CONFIG?=		${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=		${LOCALBASE}/bin/glib12-config
GDK_PIXBUF_CONFIG?=	${X11BASE}/bin/gdk-pixbuf-config

USE_X_PREFIX=		yes
USE_BZIP2=		yes
USE_GMAKE=		yes
USE_PERL5=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--disable-python

.if defined(WITH_SOCKS)
CONFIGURE_ARGS+=	--enable-socks
.endif

.if defined(WITH_GNOME)
CONFIGURE_ARGS+=	--enable-gnome
.if defined(WITH_PANEL)
CONFIGURE_ARGS+=	--enable-panel
.else
CONFIGURE_ARGS+=	--disable-panel
.endif
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

.if defined(WITH_GDK_PIXBUF)
CONFIGURE_ARGS+=	--enable-gdk-pixbuf
.else
CONFIGURE_ARGS+=	--disable-gdk-pixbuf
.endif

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			GTK_CONFIG="${GTK_CONFIG}" \
			GLIB_CONFIG="${GLIB_CONFIG}" \
			GDK_PIXBUF_CONFIG="${GDK_PIXBUF_CONFIG}" \
			LIBS="-L${LOCALBASE}/lib"

.if defined(WITH_GNOME)
PLIST=			${PKGDIR}/PLIST.gnome
.endif

post-install:
	@strip ${PREFIX}/bin/xchat
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing xchat docs in ${PREFIX}/share/doc/xchat"
	@${MKDIR} ${PREFIX}/share/doc/xchat && ${CHMOD} a+rx ${PREFIX}/share/doc/xchat
	@${INSTALL_DATA} ${WRKSRC}/doc/*.* ${PREFIX}/share/doc/xchat
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xchat
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/xchat
.endif

.include <bsd.port.mk>
