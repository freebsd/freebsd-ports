PORTNAME=	xoscope
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	audio hamradio
MASTER_SITES=	SF

MAINTAINER=	db@FreeBSD.org
COMMENT=	Sound card oscilloscope

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/README

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${STAGEDIR}${PREFIX} --sysconfdir=${STAGEDIR}${PREFIX}
USES=		gmake gnome pkgconfig tar:tgz xorg
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_XORG=	x11

.include <bsd.port.mk>
