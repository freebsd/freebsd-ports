# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hexchat
PORTVERSION=	2.9.6.1
PORTREVISION=	6
CATEGORIES=	irc gnome ipv6
MASTER_SITES=	http://dl.hexchat.org/${PORTNAME}/

MAINTAINER=	koalative@gmail.com
COMMENT=	IRC chat program with GTK and Text Frontend

LICENSE=	GPLv2

LIB_DEPENDS=	libproxy.so:${PORTSDIR}/net/libproxy

USES=		gmake desktop-file-utils libtool pkgconfig tar:xz
USE_GNOME=	gtk20 libxml2
USE_AUTOTOOLS=	automake autoconf libtoolize
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-openssl --enable-gtkfe --disable-sysinfo \
		--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}
INSTALLS_ICONS=	yes

LDFLAGS+=	-pthread
LIBS+=		-L${LOCALBASE}/lib -lX11

SUB_FILES=	pkg-message

PORTDOCS=	*

OPTIONS_DEFINE=		CA_BUNDLE CANBERRA DBUS DOAT DOCS FISHLIM NLS NOTIFY \
			PERL PYTHON SOCKS TEXTFE XFT

OPTIONS_RADIO=		SPELL
OPTIONS_RADIO_SPELL=	GTKSPELL LIBSEXY STATIC

OPTIONS_DEFAULT=	CA_BUNDLE CANBERRA DBUS NOTIFY LIBSEXY PERL PYTHON \
			SOCKS XFT

OPTIONS_SUB=	yes

CA_BUNDLE_DESC=		Include CA bundle for SSL verification
CANBERRA_DESC=		Audio support via Libcanberra
DOAT_DESC=		Do At plugin
GTKSPELL_DESC=		Spell checking support via GTKSpell
FISHLIM_DESC=		FiSHLiM plugin
LIBSEXY_DESC=		Spell checking support via Libsexy
STATIC_DESC=		Spell checking embedded in the binary
TEXTFE_DESC=		Text frontend

CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
CANBERRA_LIB_DEPENDS=	libcanberra.so:${PORTSDIR}/audio/libcanberra
CANBERRA_CONFIGURE_ENABLE=	libcanberra
DBUS_LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
DBUS_CONFIGURE_ENABLE=	dbus
DOAT_CONFIGURE_ENABLE=	doat
FISHLIM_CONFIGURE_ENABLE=	fishlim
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
NOTIFY_RUN_DEPENDS=	notify-send:${PORTSDIR}/devel/libnotify
NOTIFY_CONFIGURE_ENABLE=	libnotify
PERL_CONFIGURE_ENABLE=	perl
PYTHON_CONFIGURE_ENABLE=	python
SOCKS_LIB_DEPENDS=	libsocks.so:${PORTSDIR}/net/dante
SOCKS_CONFIGURE_ENABLE=	socks
TEXTFE_CONFIGURE_ENABLE=	textfe
XFT_CONFIGURE_ENABLE=	xft
GTKSPELL_LIB_DEPENDS=	libgtkspell.so:${PORTSDIR}/textproc/gtkspell
LIBSEXY_LIB_DEPENDS=	libsexy.so:${PORTSDIR}/x11-toolkits/libsexy

# Wrong versioning upstream
PORTSCOUT=	skipv:2.10.0

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MGTKSPELL} && ! ${PORT_OPTIONS:MLIBSEXY} && ! ${PORT_OPTIONS:MSTATIC}
CONFIGURE_ARGS+=--enable-spell=none
.endif

.if ${PORT_OPTIONS:MGTKSPELL}
CONFIGURE_ARGS+=--enable-spell=gtkspell
.endif

.if ${PORT_OPTIONS:MLIBSEXY}
CONFIGURE_ARGS+=--enable-spell=libsexy
.endif

.if ${PORT_OPTIONS:MSTATIC}
CONFIGURE_ARGS+=--enable-spell=static
.endif

.if ${PORT_OPTIONS:MCA_BUNDLE}
CA_BUNDLE=	"${LOCALBASE}/share/certs/ca-root-nss.crt"
.else
CA_BUNDLE=	NULL
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
	@${REINPLACE_CMD} -e 's|%%CA_BUNDLE%%|${CA_BUNDLE}|' \
		${WRKSRC}/src/common/server.c

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh)

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/share/doc/*.md ${STAGEDIR}${DOCSDIR}
.endif
#	@(cd ${PREFIX}/lib/hexchat/plugins/ && ${RM} -f *.a)

.include <bsd.port.mk>
