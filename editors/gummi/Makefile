PORTNAME=	gummi
DISTVERSION=	0.8.3
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	https://github.com/alexandervdm/gummi/releases/download/${DISTVERSION}/

MAINTAINER=	zab@zltech.eu
COMMENT=	Simple LaTeX editor for GTK users
WWW=		https://gummi.app/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	msgfmt:devel/gettext
LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libgtkspell3-3.so:textproc/gtkspell3 \
		libpoppler-glib.so:graphics/poppler-glib \
		libsynctex.so:devel/tex-synctex
RUN_DEPENDS=	etex:print/tex-formats

USES=		cpe desktop-file-utils gmake gnome iconv pkgconfig xorg
CPE_VENDOR=	${PORTNAME}_project
USE_GNOME=	cairo glib20 gtksourceview3 intlhack
USE_XORG=	xcomposite xcursor xdamage xft

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
