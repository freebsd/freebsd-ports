# Created by: Oliver Lehmann <oliver@FreeBSD.org>

PORTNAME=	mousepad
PORTVERSION=	0.5.5
PORTREVISION=	1
CATEGORIES=	editors xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Simple text editor for the Xfce Desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		desktop-file-utils gettext-tools gmake gnome libtool perl5 \
		pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo dconf gdkpixbuf2 glib20 gtk30 gtksourceview3 intltool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.xfce.mousepad.gschema.xml

OPTIONS_DEFINE=		NLS SPELL
OPTIONS_DEFAULT=	SPELL
OPTIONS_SUB=		yes

SPELL_DESC=		Spell checking plugin

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

SPELL_CONFIGURE_ENABLE=	plugin-gspell
SPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell \
			libenchant-2.so:textproc/enchant2
SPELL_VARS=		GLIB_SCHEMAS+=org.xfce.mousepad.plugins.gspell.gschema.xml

.include <bsd.port.mk>
