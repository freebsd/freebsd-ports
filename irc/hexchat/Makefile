# Created by: Rusmir Dusko <nemysis@FreeBSD.org>

PORTNAME=	hexchat
DISTVERSION=	2.16.1
CATEGORIES=	irc gnome
MASTER_SITES=	https://dl.hexchat.net/hexchat/

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	IRC chat program with GTK and Text Frontend

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR}
LIB_DEPENDS=	libproxy.so:net/libproxy \
		libfontconfig.so:x11-fonts/fontconfig \
		libdbus-1.so:devel/dbus \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/share/xml/iso-codes/iso_639.xml:misc/iso-codes

USES=		compiler:c++11-lang cpe desktop-file-utils gettext-tools gnome \
		libtool localbase meson ninja pkgconfig python:3.5+ shebangfix \
		ssl tar:xz xorg
CPE_VENDOR=	${PORTNAME}_project
SHEBANG_FILES=	meson_post_install.py \
		plugins/perl/generate_header.py \
		plugins/python/generate_plugin.py \
		src/common/make-te.py
USE_GNOME=	cairo gdkpixbuf2 gtk20 intltool libxml2
USE_XORG=	x11

INSTALLS_ICONS=yes

MESON_ARGS=	-Dtls=enabled -Dgtk-frontend=true -Dwith-python=python-${PYTHON_VER}

SUB_FILES=	pkg-message

PORTDOCS=	*

OPTIONS_DEFINE=		CA_BUNDLE CANBERRA DBUS DOCS FISHLIM LUA PERL TEXTFE \
			SYSINFO

OPTIONS_DEFAULT=	CA_BUNDLE CANBERRA DBUS PERL

OPTIONS_SUB=	yes

CA_BUNDLE_DESC=		Include CA bundle for SSL verification
CANBERRA_DESC=		Audio support via Libcanberra
FISHLIM_DESC=		FiSHLiM plugin
TEXTFE_DESC=		Text frontend
SYSINFO_DESC=		Sysinfo plugin

CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
CANBERRA_LIB_DEPENDS=	libcanberra.so:audio/libcanberra
CANBERRA_MESON_ON=	-Dlibcanberra=enabled
CANBERRA_MESON_OFF=	-Dlibcanberra=disabled
DBUS_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
DBUS_MESON_ON=		-Ddbus=enabled
DBUS_MESON_OFF=		-Ddbus=disabled
FISHLIM_MESON_TRUE=	with-fishlim
LUA_MESON_ON=		-Dwith-lua=lua-${LUA_VER}
LUA_MESON_OFF=		-Dwith-lua=false
LUA_USES=		lua
LUA_USE=		GCC=yes
PERL_MESON_TRUE=	with-perl
PERL_USES=		perl5
TEXTFE_MESON_TRUE=	text-frontend
SYSINFO_MESON_TRUE=	with-sysinfo

post-patch:
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
