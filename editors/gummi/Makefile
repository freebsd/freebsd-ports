# Created by: Hakisho Nukama <nukama@gmail.com>

PORTNAME=	gummi
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	https://github.com/alexandervdm/gummi/releases/download/${PORTVERSION}/

MAINTAINER=	zab@zltech.eu
COMMENT=	Simple LaTeX editor for GTK users

LICENSE=	MIT

BUILD_DEPENDS=	msgfmt:devel/gettext
LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libgtkspell3-3.so:textproc/gtkspell3 \
		libpoppler-glib.so:graphics/poppler-glib \
		libsynctex.so:devel/tex-synctex
RUN_DEPENDS=	etex:print/tex-formats

USES=		desktop-file-utils gmake gnome iconv pkgconfig xorg
GNU_CONFIGURE=	yes
USE_XORG=	xcomposite xcursor xdamage xft
USE_GNOME=	cairo glib20 gtksourceview3 intlhack
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

.include <bsd.port.mk>
