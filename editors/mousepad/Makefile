PORTNAME=	mousepad
PORTVERSION=	0.6.3
CATEGORIES=	editors xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Simple text editor for the Xfce Desktop
WWW=		https://git.xfce.org/apps/mousepad/about/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		desktop-file-utils gettext-tools gmake gnome libtool perl5 \
		pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 gtksourceview3 intltool
GLIB_SCHEMAS=	org.xfce.mousepad.gschema.xml
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		NLS SHORTCUTS SPELL
OPTIONS_DEFAULT=	SHORTCUTS SPELL
OPTIONS_SUB=		yes

SHORTCUTS_DESC=		Shortcuts editor plugin
SPELL_DESC=		Spell checking plugin

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

SHORTCUTS_USE=		XFCE=libmenu,xfconf
SHORTCUTS_CONFIGURE_ENABLE=	plugin-shortcuts

SPELL_LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
			libgspell-1.so:textproc/gspell
SPELL_CONFIGURE_ENABLE=	plugin-gspell
SPELL_VARS=		GLIB_SCHEMAS+=org.xfce.mousepad.plugins.gspell.gschema.xml

.include <bsd.port.mk>
