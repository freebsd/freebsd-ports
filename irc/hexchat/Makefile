# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hexchat
PORTVERSION=	2.12.3
CATEGORIES=	irc gnome ipv6
MASTER_SITES=	http://dl.hexchat.net/${PORTNAME}/

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	IRC chat program with GTK and Text Frontend

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libproxy.so:net/libproxy \
		libfontconfig.so:x11-fonts/fontconfig \
		libdbus-1.so:devel/dbus \
		libfreetype.so:print/freetype2

USES=		gmake desktop-file-utils libtool pkgconfig tar:xz ssl
USE_GNOME=	cairo gtk20 intltool libxml2
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-openssl --enable-gtkfe --disable-sysinfo \
		--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig \
		LUA=lua-${LUA_VER}
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

MAKE_ARGS=	OBJC="${CC}"

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11

SUB_FILES=	pkg-message

PORTDOCS=	*

OPTIONS_DEFINE=		CA_BUNDLE CANBERRA DBUS DOAT DOCS FISHLIM LUA NLS NOTIFY \
			PERL PYTHON SOCKS TEXTFE

OPTIONS_DEFAULT=	CA_BUNDLE CANBERRA DBUS NOTIFY PERL PYTHON

OPTIONS_SUB=	yes

CA_BUNDLE_DESC=		Include CA bundle for SSL verification
CANBERRA_DESC=		Audio support via Libcanberra
DOAT_DESC=		Do At plugin
FISHLIM_DESC=		FiSHLiM plugin
TEXTFE_DESC=		Text frontend
SOCKS_DESC=		SOCKS proxy support, FORBIDDEN in FreeBSD 10+

CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
CANBERRA_LIB_DEPENDS=	libcanberra.so:audio/libcanberra
CANBERRA_CONFIGURE_ENABLE=libcanberra
DBUS_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
DBUS_CONFIGURE_ENABLE=	dbus
DBUS_USE=		GNOME=gconf2
DOAT_CONFIGURE_ENABLE=	doat
FISHLIM_CONFIGURE_ENABLE=fishlim
LUA_CONFIGURE_ENABLE=	lua
LUA_USES=		lua
LUA_USE=		GCC=any
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools # doesn't build otherwise
NOTIFY_RUN_DEPENDS=	notify-send:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=libnotify
PERL_CONFIGURE_ENABLE=	perl
PERL_USES=		perl5
PYTHON_CONFIGURE_ENABLE=python
PYTHON_USES=		python
SOCKS_LIB_DEPENDS=	libsocks.so:net/dante
SOCKS_CONFIGURE_ENABLE=	socks
TEXTFE_CONFIGURE_ENABLE=textfe

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
WITH_OPENSSL_PORT=	yes
.endif

.if ${PORT_OPTIONS:MCA_BUNDLE}
CA_BUNDLE=	"${LOCALBASE}/share/certs/ca-root-nss.crt"
.else
CA_BUNDLE=	NULL
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%CA_BUNDLE%%|${CA_BUNDLE}|' \
		${WRKSRC}/src/common/server.c

post-install:
	${LN} -sf ../share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
