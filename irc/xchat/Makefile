# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/irc/xchat/Makefile,v 1.7 2008/08/06 07:59:00 kwm Exp $

PORTNAME=	xchat
PORTVERSION=	2.8.8
PORTREVISION=	2
CATEGORIES=	irc gnome ipv6
MASTER_SITES=	SF/${PORTNAME}/ \
		http://xchat.org/files/source/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	X11 IRC client using the GTK+ 2 toolkit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	xchat-1* xchat-systray-plugin-[0-9]*

USES=		cpe gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-ipv6
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DBUS NOTIFY PERL PYTHON SOCKS TCL
OPTIONS_DEFAULT=DBUS GTKSPELL PERL
OPTIONS_RADIO=	SPELL
OPTIONS_RADIO_SPELL=	GTKSPELL LIBSEXY
GTKSPELL_DESC=	Spell check support via gtkspell
LIBSEXY_DESC=	Spell check support via libsexy

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	libdbus-glib-1.so:devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
USE_GNOME+=	gconf2
GCONF_SCHEMAS+=	apps_xchat_url_handler.schemas
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	DBUS="@comment "
.endif

.if ${PORT_OPTIONS:MGTKSPELL}
LIB_DEPENDS+=	libgtkspell.so:textproc/gtkspell
CONFIGURE_ARGS+=--enable-spell=gtkspell
.elif ${PORT_OPTIONS:MLIBSEXY}
LIB_DEPENDS+=	libsexy.so:x11-toolkits/libsexy
CONFIGURE_ARGS+=--enable-spell=libsexy
.else
CONFIGURE_ARGS+=--enable-spell=none
.endif

.if ${PORT_OPTIONS:MNOTIFY}
RUN_DEPENDS+=	notify-send:devel/libnotify \
		${LOCALBASE}/libexec/notification-daemon:deskutils/notification-daemon
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
CONFIGURE_ARGS+=--enable-perl
PLIST_SUB+=	PERL=""
.else
CONFIGURE_ARGS+=--disable-perl
PLIST_SUB+=	PERL="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python
CONFIGURE_ARGS+=--enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MSOCKS}
LIB_DEPENDS+=	libsocks.so:net/dante
CONFIGURE_ARGS+=--enable-socks
.endif

.if ${PORT_OPTIONS:MTCL}
USES+=		tcl
CONFIGURE_ARGS+=--enable-tcl=${TCL_LIBDIR}
CPPFLAGS+=	-I${TCL_INCLUDEDIR}
LIBS+=		-L${TCL_LIBDIR}
PLIST_SUB+=	TCL=""
.else
CONFIGURE_ARGS+=--enable-tcl=no
PLIST_SUB+=	TCL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/common/*.[ch]
	@${REINPLACE_CMD} '/_LDADD =/s/$$/ -lgmodule-2.0/' \
		${WRKSRC}/src/fe-gtk/Makefile.in \
		${WRKSRC}/src/fe-text/Makefile.in

# Create plugins directory even when no plugins are installed
post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xchat/plugins

.include <bsd.port.mk>
