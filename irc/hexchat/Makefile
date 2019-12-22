# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hexchat
PORTVERSION=	2.14.3
DISTVERSIONPREFIX=	v
CATEGORIES=	irc gnome

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	IRC chat program with GTK and Text Frontend

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes
LIB_DEPENDS=	libproxy.so:net/libproxy \
		libfontconfig.so:x11-fonts/fontconfig \
		libdbus-1.so:devel/dbus \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/share/xml/iso-codes/iso_639.xml:misc/iso-codes

USES=		compiler:c++11-lang desktop-file-utils gettext-tools gnome \
		libtool localbase meson ninja pkgconfig python:3.5+ shebangfix \
		ssl xorg
USE_GNOME=	cairo gtk20 intltool libxml2
USE_XORG=	x11
USE_GITHUB=	yes

MESON_ARGS=	-Dwith-ssl=true -Dwith-gtk=true -Dwith-python=python-${PYTHON_VER}
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

LIBS+=		-lX11

SUB_FILES=	pkg-message

PORTDOCS=	*

OPTIONS_DEFINE=		CA_BUNDLE CANBERRA DBUS DOCS FISHLIM LUA NOTIFY \
			PERL TEXTFE SYSINFO

OPTIONS_DEFAULT=	CA_BUNDLE CANBERRA DBUS NOTIFY PERL

OPTIONS_SUB=	yes

CA_BUNDLE_DESC=		Include CA bundle for SSL verification
CANBERRA_DESC=		Audio support via Libcanberra
FISHLIM_DESC=		FiSHLiM plugin
TEXTFE_DESC=		Text frontend
SYSINFO_DESC=		Sysinfo plugin

CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
CA_BUNDLE_VARS=	CA_BUNDLE="${LOCALBASE}/share/certs/ca-root-nss.crt"
CA_BUNDLE_VARS_OFF=	CA_BUNDLE=NULL
CANBERRA_LIB_DEPENDS=	libcanberra.so:audio/libcanberra
CANBERRA_MESON_TRUE=	with-libcanberra
DBUS_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
DBUS_MESON_TRUE=	with-dbus
DBUS_USE=		GNOME=gconf2
FISHLIM_MESON_TRUE=	with-fishlim
LUA_MESON_ON=		-Dwith-lua=lua-${LUA_VER}
LUA_MESON_OFF=		-Dwith-lua=false
LUA_USES=		lua
LUA_USE=		GCC=any
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_MESON_TRUE=	with-libnotify
PERL_MESON_TRUE=	with-perl
PERL_USES=		perl5
TEXTFE_MESON_TRUE=	with-text
SYSINFO_MESON_TRUE=	with-sysinfo

SHEBANG_FILES=	meson_post_install.py \
		plugins/perl/generate_header.py \
		src/common/make-te.py

post-patch:
	@${REINPLACE_CMD} -e 's|%%CA_BUNDLE%%|${CA_BUNDLE}|' \
		${WRKSRC}/src/common/server.c
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%PERL_VER%%|${PERL_VER}|g' \
		${WRKSRC}/plugins/perl/meson.build

post-install:
	${LN} -sf ../share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
