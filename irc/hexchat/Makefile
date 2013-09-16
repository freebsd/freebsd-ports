# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	hexchat
PORTVERSION=	2.9.5
CATEGORIES=	irc gnome ipv6
MASTER_SITES=	http://dl.hexchat.org/${PORTNAME}/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	IRC chat program with GTK and Text Frontend

LICENSE=	GPLv2

LIB_DEPENDS=	proxy:${PORTSDIR}/net/libproxy

USE_XZ=		yes
USES=		desktop-file-utils pathfix pkgconfig gmake
USE_GNOME=	gtk20 libxml2
USE_AUTOTOOLS=	automake autoconf libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-gtkfe --disable-sysinfo
INSTALLS_ICONS=	yes

LDFLAGS+=	-pthread

MAN1=		hexchat.1

PORTDOCS=	*

OPTIONS_DEFINE=		NLS SOCKS XFT OPENSSL TEXTFE PYTHON PERL DOAT DBUS NOTIFY

OPTIONS_RADIO=		SPELL
OPTIONS_RADIO_SPELL=	LIBSEXY GTKSPELL STATIC

OPTIONS_DEFAULT=	SOCKS XFT OPENSSL PERL DOAT DBUS NOTIFY LIBSEXY

TEXTFE_DESC=		Build the Text frontend
DOAT_DESC=		Build the Do At plugin
STATIC_DESC=		Spell checking embedded in the binary
LIBSEXY_DESC=		Spell checking through Libsexy
GTKSPELL_DESC=		Spell checking through GTKSpell

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ! ${PORT_OPTIONS:MLIBSEXY} && ! ${PORT_OPTIONS:MGTKSPELL} && ! ${PORT_OPTIONS:MSTATIC}
CONFIGURE_ARGS+=--enable-spell=none
.endif

.if ${PORT_OPTIONS:MSTATIC}
CONFIGURE_ARGS+=--enable-spell=static
.endif

.if ${PORT_OPTIONS:MLIBSEXY}
LIB_DEPENDS+=	sexy:${PORTSDIR}/x11-toolkits/libsexy
CONFIGURE_ARGS+=--enable-spell=libsexy
.endif

.if ${PORT_OPTIONS:MGTKSPELL}
LIB_DEPENDS+=	gtkspell:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=--enable-spell=gtkspell
.endif

.if ${PORT_OPTIONS:MSOCKS}
LIB_DEPENDS+=	socks:${PORTSDIR}/net/dante
CONFIGURE_ARGS+=--enable-socks
.else
CONFIGURE_ARGS+=--disable-socks
.endif

.if ${PORT_OPTIONS:MXFT}
USE_XORG+=	xft
CONFIGURE_ARGS+=--enable-xft
.else
CONFIGURE_ARGS+=--disable-xft
.endif

.if ${PORT_OPTIONS:MOPENSSL}
CONFIGURE_ARGS+=--enable-openssl
PLIST_SUB+=	OPENSSL=""
.else
CONFIGURE_ARGS+=--disable-openssl

PLIST_SUB+=	OPENSSL="@comment "
.endif

.if ${PORT_OPTIONS:MTEXTFE}
CONFIGURE_ARGS+=--enable-textfe
PLIST_SUB+=	TEXTFE=""
.else
CONFIGURE_ARGS+=--disable-textfe
PLIST_SUB+=	TEXTFE="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
CONFIGURE_ARGS+=--enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
CONFIGURE_ARGS+=--enable-perl
PLIST_SUB+=	PERL=""
.else
CONFIGURE_ARGS+=--disable-perl
PLIST_SUB+=	PERL="@comment "
.endif

.if ${PORT_OPTIONS:MDOAT}
CONFIGURE_ARGS+=--enable-doat
PLIST_SUB+=	DOAT=""
.else
CONFIGURE_ARGS+=--disable-doat
PLIST_SUB+=	DOAT="@comment "
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
USE_GNOME+=	gconf2
GCONF_SCHEMAS+=	apps_hexchat_url_handler.schemas
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	DBUS="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFY}
RUN_DEPENDS+=	notify-send:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-libnotify
PLIST_SUB+=	NOTIFY=""
.else
CONFIGURE_ARGS+=--disable-libnotify
PLIST_SUB+=	NOTIFY="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' ${WRKSRC}/autogen.sh
	@${REINPLACE_CMD} -e 's|po intl|po|g' ${WRKSRC}/Makefile.am

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh)

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/share/doc/*.md ${DOCSDIR}
.endif
	@(cd ${PREFIX}/lib/hexchat/plugins/ && ${RM} -f *.a)

.include <bsd.port.mk>
