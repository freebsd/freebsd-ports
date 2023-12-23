PORTNAME=	xdx
DISTVERSION=	2.91
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/xdxclusterclient/${PORTVERSION}/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio DX cluster monitor
WWW=		https://sourceforge.net/projects/xdxclusterclient/

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext gmake gnome pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
