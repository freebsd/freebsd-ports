# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	klavaro
PORTVERSION=	1.9.9
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	h.skuhra@gmail.com
COMMENT=	Touchtyping trainer

LICENSE=	GPLv3

LIB_DEPENDS=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libcairo.so:${PORTSDIR}/graphics/cairo \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libgtkdatabox.so:${PORTSDIR}/x11-toolkits/gtkdatabox

USES=		pkgconfig gettext gmake iconv pathfix
USE_BZIP2=	yes
USE_XORG=	pixman x11 xau xcb xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender
USE_GNOME=	gtk20
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/gtkdatabox
LDFLAGS+=	-L${LOCALBASE}/lib -rdynamic

GNU_CONFIGURE=	yes

post-extract:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' \
		${WRKSRC}/data/klavaro.desktop.in

pre-build:
	@${REINPLACE_CMD} -e 's|^am__append_1|#am__append_1|' \
		${WRKSRC}/src/Makefile

.include <bsd.port.mk>
