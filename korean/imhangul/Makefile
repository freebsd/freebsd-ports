# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	imhangul
PORTVERSION=	${GTKVER:R}.1.1
PORTREVISION=	3
CATEGORIES=	korean

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	GTK+ Hangul input module

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhangul.so:korean/libhangul

GH_ACCOUNT=	choehwanjin
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PLIST_SUB=	GTKVER=${GTKVER}
USE_GNOME=	cairo gdkpixbuf2 gtk${GTKVER:S|.||}
USES=		autoreconf gmake libtool pkgconfig

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=	GTK3
OPTIONS_SINGLE=	GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3
OPTIONS_SUB=	yes
GTK_DESC=	Select GTK+ version
GTK2_LIB_DEPENDS=	libfreetype.so:print/freetype2
GTK2_LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig
GTK2_VARS=	GH_TAGNAME=d2f555d GTKVER=2.0
GTK3_VARS=	GH_TAGNAME=85f6d10 GTKVER=3.0
NLS_USES=	gettext localbase

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS /s| po||' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e '/^po\/Makefile\.in/d' ${WRKSRC}/configure.in

pre-configure-NLS-on:
	@(cd ${WRKSRC} && ${LOCALBASE}/bin/glib-gettextize)

.include <bsd.port.mk>
