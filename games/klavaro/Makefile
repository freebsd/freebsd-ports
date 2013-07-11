# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	klavaro
PORTVERSION=	1.9.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	h.skuhra@gmail.com
COMMENT=	Touchtyping trainer

LICENSE=	GPLv3

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		curl:${PORTSDIR}/ftp/curl \
		cairo:${PORTSDIR}/graphics/cairo \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		gtkdatabox:${PORTSDIR}/x11-toolkits/gtkdatabox

USES=		pkgconfig gettext iconv
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	pixman x11 xau xcb xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xrandr xrender
USE_GNOME=	gtk20
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/gtkdatabox
LDFLAGS+=	-L${LOCALBASE}/lib

GNU_CONFIGURE=	yes

MAN1=		${PORTNAME}.1

post-extract:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' \
		${WRKSRC}/data/klavaro.desktop.in

.include <bsd.port.mk>
