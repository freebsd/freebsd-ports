# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	hexchat
PORTVERSION=	2.9.6.1
CATEGORIES=	irc gnome ipv6
MASTER_SITES=	http://dl.hexchat.org/${PORTNAME}/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	IRC chat program with GTK and Text Frontend

LICENSE=	GPLv2

LIB_DEPENDS=	libproxy.so:${PORTSDIR}/net/libproxy \
		libcanberra.so:${PORTSDIR}/audio/libcanberra

USE_XZ=		yes
USES=		gmake desktop-file-utils pkgconfig
USE_GNOME=	gtk20 libxml2
USE_AUTOTOOLS=	automake autoconf libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-openssl --enable-gtkfe --disable-sysinfo \
		--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig
INSTALLS_ICONS=	yes

LDFLAGS+=	-pthread

MAN1=		hexchat.1

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS NLS SOCKS XFT TEXTFE PYTHON PERL DOAT FISHLIM DBUS NOTIFY

OPTIONS_RADIO=		SPELL
OPTIONS_RADIO_SPELL=	LIBSEXY GTKSPELL STATIC

OPTIONS_DEFAULT=	SOCKS XFT PERL DOAT DBUS NOTIFY LIBSEXY

OPTIONS_SUB=	yes

TEXTFE_DESC=		Text frontend
DOAT_DESC=		Do At plugin
FISHLIM_DESC=		FiSHLiM plugin
STATIC_DESC=		Spell checking embedded in the binary
LIBSEXY_DESC=		Spell checking support via Libsexy
GTKSPELL_DESC=		Spell checking support via GTKSpell

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
LIBSEXY_LIB_DEPENDS=	libsexy.so:${PORTSDIR}/x11-toolkits/libsexy
GTKSPELL_LIB_DEPENDS=	libgtkspell.so:${PORTSDIR}/textproc/gtkspell
SOCKS_LIB_DEPENDS=	libsocks.so:${PORTSDIR}/net/dante
SOCKS_CONFIGURE_ENABLE=	socks
XFT_CONFIGURE_ENABLE=	xft
TEXTFE_CONFIGURE_ENABLE=	textfe
PYTHON_CONFIGURE_ENABLE=	python
PERL_CONFIGURE_ENABLE=	perl
DOAT_CONFIGURE_ENABLE=	doat
FISHLIM_CONFIGURE_ENABLE=	fishlim
DBUS_LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
DBUS_CONFIGURE_ENABLE=	dbus
NOTIFY_RUN_DEPENDS=	notify-send:${PORTSDIR}/devel/libnotify
NOTIFY_CONFIGURE_ENABLE=	libnotify

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MLIBSEXY} && ! ${PORT_OPTIONS:MGTKSPELL} && ! ${PORT_OPTIONS:MSTATIC}
CONFIGURE_ARGS+=--enable-spell=none
.endif

.if ${PORT_OPTIONS:MLIBSEXY} || ${PORT_OPTIONS:MGTKSPELL} || ${PORT_OPTIONS:MSTATIC}
RUN_DEPENDS+=	aspell:${PORTSDIR}/textproc/en-aspell
.endif

.if ${PORT_OPTIONS:MSTATIC}
CONFIGURE_ARGS+=--enable-spell=static
.endif

.if ${PORT_OPTIONS:MLIBSEXY}
CONFIGURE_ARGS+=--enable-spell=libsexy
.endif

.if ${PORT_OPTIONS:MGTKSPELL}
CONFIGURE_ARGS+=--enable-spell=gtkspell
.endif

.if ${PORT_OPTIONS:MXFT}
USE_XORG+=	xft
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
.endif

.if ${PORT_OPTIONS:MDBUS}
USE_GNOME+=	gconf2
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' ${WRKSRC}/autogen.sh
	@${REINPLACE_CMD} -e '/^appdata_DATA/s|hexchat.appdata.xml||' \
		 ${WRKSRC}/share/misc/Makefile.am ${WRKSRC}/share/misc/Makefile.in

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh)

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/share/doc/*.md ${DOCSDIR}
.endif
#	@(cd ${PREFIX}/lib/hexchat/plugins/ && ${RM} -f *.a)

.include <bsd.port.mk>
