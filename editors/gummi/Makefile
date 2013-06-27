# Created by: Hakisho Nukama <Nukama@gmail.com>
# $FreeBSD$

PORTNAME=	gummi
PORTVERSION=	0.6.5
CATEGORIES=	editors
MASTER_SITES=	http://dev.midnightcoding.org/attachments/download/301/

MAINTAINER=	nukama+maintainer@gmail.com
COMMENT=	Simple LaTex editor for GTK users

LICENSE=	MIT

BUILD_DEPENDS+=	msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS+=	poppler-glib:${PORTSDIR}/graphics/poppler-glib \
		gtkspell:${PORTSDIR}/textproc/gtkspell

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_XORG=	xdamage xft xcursor xcomposite
USE_GNOME=	desktopfileutils gtksourceview2 glib20 intlhack
USE_PKGCONFIG=	build
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

MAN1=		gummi.1

OPTIONS_DEFINE=	TETEX LATEXMK RUBBER TEXCOUNT
OPTIONS_DEFAULT=	TETEX

TETEX_DESC=	Use pdfetex typesetter
LATEXMK_DESC=	Use latexmk typesetter
RUBBER_DESC=	Use rubber typesetter
TEXCOUNT_DESC=	With texcount statistics

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MTETEX}
RUN_DEPENDS+=	pdfetex:${PORTSDIR}/print/teTeX-base
.endif

.if ${PORT_OPTIONS:MLATEXMK}
RUN_DEPENDS+=	latexmk:${PORTSDIR}/print/latexmk
.endif

.if ${PORT_OPTIONS:MRUBBER}
RUN_DEPENDS+=	rubber:${PORTSDIR}/textproc/rubber
.endif

.if ${PORT_OPTIONS:MTEXCOUNT}
#RUN_DEPENDS+=	${LOCALBASE}/bin/texcount.${PORTVERSION}:${PORTSDIR}/texproc/p5-texcount
.endif

.include <bsd.port.mk>
