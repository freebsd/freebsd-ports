# New ports collection makefile for:	xchat2
# Date created:			17 Aug 2002
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/irc/xchat/Makefile,v 1.7 2008/08/06 07:59:00 kwm Exp $
#

PORTNAME=	xchat
PORTVERSION=	2.8.6
PORTREVISION=	7
CATEGORIES=	irc gnome ipv6
MASTER_SITES=	SF \
		http://xchat.org/files/source/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}/


MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An X11 IRC client using the GTK+ 2 toolkit

CONFLICTS=	xchat-1* xchat-systray-plugin-[0-9]*

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-ipv6
WANT_PERL=	yes

OPTIONS=	DBUS "Enable DBUS support" on \
		GTKSPELL "Enable spell check support using gtkspell" on \
		LIBSEXY "Enable spell check support using libsexy" off \
		NOTIFY "Depend on libnotify for notifications" off \
		PERL "Enable Perl support" on \
		PYTHON "Enable Python support" off \
		TCL "Enable TCL support" off \
		SOCKS "Build with socks5 support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
USE_GNOME+=	gconf2
GCONF_SCHEMAS+=	apps_xchat_url_handler.schemas
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	DBUS="@comment "
.endif

.if defined(WITH_GTKSPELL)
.if defined(WITH_LIBSEXY)
BROKEN=		You can select only one of GTKSPELL and LIBSEXY for spell check support
.endif
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=--enable-spell=gtkspell
.endif

.if defined(WITH_LIBSEXY)
.if defined(WITH_GTKSPELL)
BROKEN=		You can select only one of GTKSPELL and LIBSEXY for spell check support
.endif
LIB_DEPENDS+=	sexy.2:${PORTSDIR}/x11-toolkits/libsexy
CONFIGURE_ARGS+=--enable-spell=libsexy
.endif

.if !defined(WITH_GTKSPELL) && !defined(WITH_LIBSEXY)
CONFIGURE_ARGS+=--enable-spell=none
.endif

.if defined(WITH_NOTIFY)
RUN_DEPENDS+=	notify-send:${PORTSDIR}/devel/libnotify \
		${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon
.endif

.if defined(WITHOUT_PERL)
CONFIGURE_ARGS+=--disable-perl
PLIST_SUB+=	PERL="@comment "
.else
USE_PERL5=	yes
CONFIGURE_ARGS+=--enable-perl
PLIST_SUB+=	PERL=""
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
CONFIGURE_ARGS+=--enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(WITH_TCL)
USE_TCL=	84+
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
CONFIGURE_ARGS+=--enable-tcl=${TCL_LIBDIR}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS} \
		-I${TCL_INCLUDEDIR}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS} \
		-L${TCL_LIBDIR}"
PLIST_SUB+=	TCL=""
.else
CONFIGURE_ARGS+=--enable-tcl=no
PLIST_SUB+=	TCL="@comment "
.endif

.if defined(WITH_SOCKS)
ONLY_FOR_ARCHS=	i386
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
CONFIGURE_ARGS+=--enable-socks
.endif

post-patch:
	@${REINPLACE_CMD} -E -e 's|PY_LIBS=.*|PY_LIBS="-L\$$PY_EXEC_PREFIX/lib/python\$$PY_VER/config -lpython\$$PY_VER ${PTHREAD_LIBS} -lutil"|' \
		${WRKSRC}/configure
.for file in dccgui.c fe-gtk.c maingui.c menu.c plugin-tray.c sexy-spell-entry.c xtext.c xtext.h
	@${REINPLACE_CMD} -e 's|#define GTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/src/fe-gtk/${file}
.endfor

# Create plugins directory even when no plugins are installed
post-install:
	@${MKDIR} ${PREFIX}/lib/xchat/plugins

.include <bsd.port.post.mk>
