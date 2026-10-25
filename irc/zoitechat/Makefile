PORTNAME=	zoitechat
DISTVERSIONPREFIX=	v
DISTVERSION=	2.19.1
CATEGORIES=	irc gnome

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	GTK3 IRC client based on HexChat
WWW=		https://zoitechat.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		${LOCALBASE}/share/public_suffix_list/public_suffix_list.dat:dns/public_suffix_list \
		${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR}
LIB_DEPENDS=	libsecret-1.so:security/libsecret
RUN_DEPENDS=	${LOCALBASE}/share/xml/iso-codes/iso_639.xml:misc/iso-codes

USES=		desktop-file-utils gettext gnome libarchive meson pkgconfig \
		python shebangfix ssl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	ZoiteChat
SHEBANG_FILES=	meson_post_install.py \
		plugins/perl/generate_header.py \
		plugins/python/generate_plugin.py \
		src/common/make-te.py
USE_GNOME=	cairo gdkpixbuf gtk30
USE_XORG=	x11

MESON_ARGS=	-Dtls=enabled -Dgtk-frontend=true \
		-Dwith-python=python-${PYTHON_VER}-embed

SUB_FILES=	pkg-message

PORTDOCS=	*

OPTIONS_DEFINE=		APPINDICATOR CANBERRA DBUS DOCS FISHLIM LUA PERL SYSINFO \
			TEXTFE
OPTIONS_DEFAULT=	CANBERRA DBUS PERL
OPTIONS_SUB=		yes

APPINDICATOR_DESC=	Tray icon via Ayatana AppIndicator
CANBERRA_DESC=		Audio support via Libcanberra
FISHLIM_DESC=		FiSHLiM plugin
SYSINFO_DESC=		Sysinfo plugin
TEXTFE_DESC=		Text frontend

APPINDICATOR_LIB_DEPENDS=	libayatana-appindicator3.so:devel/libayatana-appindicator
APPINDICATOR_MESON_ENABLED=	appindicator
CANBERRA_LIB_DEPENDS=	libcanberra.so:audio/libcanberra
CANBERRA_MESON_ENABLED=	libcanberra
DBUS_MESON_ENABLED=	dbus
FISHLIM_MESON_TRUE=	with-fishlim
LUA_MESON_ON=		-Dwith-lua=lua-${LUA_VER}
LUA_MESON_OFF=		-Dwith-lua=false
LUA_USES=		lua
PERL_MESON_ON=		-Dwith-perl=${PERL}
PERL_MESON_OFF=		-Dwith-perl=false
PERL_USES=		perl5
SYSINFO_LIB_DEPENDS=	libpci.so:devel/libpci
SYSINFO_MESON_TRUE=	with-sysinfo
TEXTFE_MESON_TRUE=	text-frontend

# gen-public-suffix.py downloads the public suffix list at build time and
# otherwise only looks at a sibling public_suffix_list.dat, so give it the
# one from dns/public_suffix_list.
pre-configure:
	${CP} ${LOCALBASE}/share/public_suffix_list/public_suffix_list.dat \
		${WRKSRC}/src/common/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${WRKSRC}/changelog.rst \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
