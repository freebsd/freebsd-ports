# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hexchat
PORTVERSION=	2.10.2
CATEGORIES=	irc gnome ipv6
MASTER_SITES=	http://dl.hexchat.net/${PORTNAME}/

MAINTAINER=	serio.jeffrey@gmail.com
COMMENT=	IRC chat program with GTK and Text Frontend

LICENSE=	GPLv2

LIB_DEPENDS=	libproxy.so:${PORTSDIR}/net/libproxy

USES=		gmake desktop-file-utils libtool pkgconfig tar:xz
USE_GNOME=	gtk20 intltool libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-openssl --enable-gtkfe --disable-sysinfo \
		--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USE_OPENSSL=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11

SUB_FILES=	pkg-message

PORTDOCS=	*

OPTIONS_DEFINE=		CA_BUNDLE CANBERRA DBUS DOAT DOCS FISHLIM NLS NOTIFY \
			PERL PYTHON SOCKS TEXTFE

OPTIONS_DEFAULT=	CA_BUNDLE CANBERRA DBUS NOTIFY PERL PYTHON

OPTIONS_SUB=	yes

CA_BUNDLE_DESC=		Include CA bundle for SSL verification
CANBERRA_DESC=		Audio support via Libcanberra
DOAT_DESC=		Do At plugin
FISHLIM_DESC=		FiSHLiM plugin
TEXTFE_DESC=		Text frontend
SOCKS_DESC=		SOCKS proxy support, FORBIDDEN in FreeBSD 10+

CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
CANBERRA_LIB_DEPENDS=	libcanberra.so:${PORTSDIR}/audio/libcanberra
CANBERRA_CONFIGURE_ENABLE=	libcanberra
DBUS_LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
DBUS_CONFIGURE_ENABLE=	dbus
DOAT_CONFIGURE_ENABLE=	doat
FISHLIM_CONFIGURE_ENABLE=	fishlim
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools # doesn't build otherwise
NOTIFY_RUN_DEPENDS=	notify-send:${PORTSDIR}/devel/libnotify
NOTIFY_CONFIGURE_ENABLE=	libnotify
PERL_CONFIGURE_ENABLE=	perl
PYTHON_CONFIGURE_ENABLE=	python
SOCKS_LIB_DEPENDS=	libsocks.so:${PORTSDIR}/net/dante
SOCKS_CONFIGURE_ENABLE=	socks
TEXTFE_CONFIGURE_ENABLE=	textfe

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
WITH_OPENSSL_PORT=	yes
.endif

.if ${PORT_OPTIONS:MCA_BUNDLE}
CA_BUNDLE=	"${LOCALBASE}/share/certs/ca-root-nss.crt"
.else
CA_BUNDLE=	NULL
.endif

.if ${PORT_OPTIONS:MPYTHON}
USES+=	python
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
.endif

.if ${PORT_OPTIONS:MDBUS}
USE_GNOME+=	gconf2
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%CA_BUNDLE%%|${CA_BUNDLE}|' \
		${WRKSRC}/src/common/server.c

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
