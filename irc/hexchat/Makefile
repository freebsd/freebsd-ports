PORTNAME=	hexchat
DISTVERSION=	2.16.2
PORTREVISION=	2
CATEGORIES=	irc gnome
MASTER_SITES=	https://github.com/hexchat/hexchat/releases/download/v${PORTVERSION}/

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	IRC chat program with GTK and Text Frontend
WWW=		https://hexchat.github.io/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Repo archived upstream as of 2024-02-10

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR}
LIB_DEPENDS=	libproxy.so:net/libproxy \
		libfontconfig.so:x11-fonts/fontconfig \
		libdbus-1.so:devel/dbus \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/share/xml/iso-codes/iso_639.xml:misc/iso-codes

USES=		compiler:c++11-lang cpe desktop-file-utils gettext-tools gnome \
		localbase meson ninja pkgconfig python shebangfix \
		ssl tar:xz xorg
CPE_VENDOR=	${PORTNAME}_project
SHEBANG_FILES=	meson_post_install.py \
		plugins/perl/generate_header.py \
		plugins/python/generate_plugin.py \
		src/common/make-te.py
USE_GNOME=	cairo gdkpixbuf gtk20 intltool libxml2
USE_XORG=	x11

MESON_ARGS=	-Dtls=enabled -Dgtk-frontend=true -Dwith-python=python-${PYTHON_VER}

SUB_FILES=	pkg-message

PORTDOCS=	*

OPTIONS_DEFINE=		CANBERRA DBUS DOCS FISHLIM LUA PERL SYSINFO TEXTFE

OPTIONS_DEFAULT=	CANBERRA DBUS PERL

OPTIONS_SUB=	yes

CANBERRA_DESC=		Audio support via Libcanberra
FISHLIM_DESC=		FiSHLiM plugin
TEXTFE_DESC=		Text frontend
SYSINFO_DESC=		Sysinfo plugin

CANBERRA_LIB_DEPENDS=	libcanberra.so:audio/libcanberra
CANBERRA_MESON_ENABLED=	libcanberra
DBUS_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
DBUS_MESON_ENABLED=	dbus
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
