# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	imhangul
PORTVERSION=	2.1.1
CATEGORIES=	korean
PKGNAMESUFFIX=	-gtk2

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Hangul input module for GTK+ 2.0

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhangul.so:korean/libhangul \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

CONFLICTS_INSTALL=	ko-imhangul-[0-2].*

GH_ACCOUNT=	choehwanjin
GH_TAGNAME=	d2f555d
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_GNOME=	cairo gdkpixbuf2 gtk20
USES=		autoreconf gmake gnome libtool pkgconfig

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext localbase

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS /s| po||' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e '/^po\/Makefile\.in/d' ${WRKSRC}/configure.in

pre-configure-NLS-on:
	@(cd ${WRKSRC} && ${LOCALBASE}/bin/glib-gettextize)

.include <bsd.port.mk>
