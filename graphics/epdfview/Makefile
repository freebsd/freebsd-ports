PORTNAME=	epdfview
DISTVERSION=	0.2.0
PORTREVISION=	3
CATEGORIES=	graphics print gnome

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Lightweight PDF document viewer
WWW=		https://github.com/Flow-It/epdfview_old

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib

USES=		compiler:c++11-lang desktop-file-utils gnome iconv meson \
		pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	Flow-It
GH_PROJECT=	epdfview_old
GH_TAGNAME=	6f907bd

USE_GNOME=	glib20 gtk30

OPTIONS_DEFINE=		CUPS NLS
OPTIONS_DEFAULT=	CUPS NLS
OPTIONS_SUB=		yes

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_MESON_TRUE=	enable-printing
NLS_USES=		gettext
NLS_MESON_TRUE=		enable-nls

.include <bsd.port.mk>
