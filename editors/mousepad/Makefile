PORTNAME=	mousepad
PORTVERSION=	0.6.5
PORTREVISION=	1
CATEGORIES=	editors xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Simple text editor for the Xfce Desktop
WWW=		https://git.xfce.org/apps/mousepad/about/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:indirect desktop-file-utils gettext-tools gnome libtool \
		meson perl5 pkgconfig tar:xz xfce
USE_GNOME=	gdkpixbuf glib20 gtk30 gtksourceview4 intltool
GLIB_SCHEMAS=	org.xfce.mousepad.gschema.xml
USE_LDCONFIG=	yes
MESON_ARGS=	-Dpolkit=enabled \
		-Dgtksourceview4=enabled

OPTIONS_DEFINE=		NLS SHORTCUTS SPELL
OPTIONS_DEFAULT=	SHORTCUTS SPELL
OPTIONS_SUB=		yes

SHORTCUTS_DESC=	Shortcuts editor plugin
SPELL_DESC=	Spell checking plugin

NLS_USES=	gettext-runtime

SHORTCUTS_USE=			XFCE=libmenu,xfconf
SHORTCUTS_MESON_ENABLED=	shortcuts-plugin

SPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell
SPELL_MESON_ENABLED=	gspell-plugin
SPELL_VARS=		GLIB_SCHEMAS+=org.xfce.mousepad.plugins.gspell.gschema.xml

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
