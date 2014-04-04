# Created by: Hakisho Nukama <nukama@gmail.com>
# $FreeBSD$

PORTNAME=		gummi
PORTVERSION=		0.6.5
PORTREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		http://dev.midnightcoding.org/attachments/download/301/

MAINTAINER=		nukama+maintainer@gmail.com
COMMENT=		Simple LaTex editor for GTK users

DEPRECATED=		Builds fine but the program itself is unusable
EXPIRATION_DATE=	2014-07-01

LICENSE=		MIT

BUILD_DEPENDS+=		msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS+=		libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib \
			libgtkspell.so:${PORTSDIR}/textproc/gtkspell

USES=			iconv gmake pkgconfig desktop-file-utils
GNU_CONFIGURE=		yes
USE_XORG=		xdamage xft xcursor xcomposite
USE_GNOME=		gtksourceview2 glib20 intlhack
INSTALLS_ICONS=		yes
INSTALLS_OMF=		yes

OPTIONS_DEFINE=		TETEX LATEXMK RUBBER TEXCOUNT
OPTIONS_DEFAULT=	TETEX

TETEX_DESC=		Use pdfetex typesetter
LATEXMK_DESC=		Use latexmk typesetter
RUBBER_DESC=		Use rubber typesetter
TEXCOUNT_DESC=		With texcount statistics

CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "

NLS_USES+=		gettext
NLS_CONFIGURE_ARGS+=	--enable-nls
NLS_PLIST_SUB+=		NLS=""

TETEX_RUN_DEPENDS=	pdfetex:${PORTSDIR}/print/teTeX-base

LATEXMK_RUN_DEPENDS=	latexmk:${PORTSDIR}/print/latexmk

RUBBER_RUN_DEPENDS=	rubber:${PORTSDIR}/textproc/rubber

TEXCOUNT_RUN_DEPENDS=	${LOCALBASE}/bin/texcount.${PORTVERSION}:${PORTSDIR}/texproc/p5-texcount

.include <bsd.port.mk>
