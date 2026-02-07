PORTNAME=	gpredict
DISTVERSION=	2.2.1
PORTREVISION=	6
CATEGORIES=	comms hamradio
MASTER_SITES=	https://github.com/csete/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio satellite tracking and prediction
WWW=		http://gpredict.oz9aec.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libatk-1.0.so:accessibility/at-spi2-core \
		libcurl.so:ftp/curl \
		libhamlib.so:comms/hamlib \
		libharfbuzz.so:print/harfbuzz \
		libgoocanvas-2.0.so:graphics/goocanvas2 \
		libgps.so:astro/gpsd

USES=		compiler:c11 gettext gmake gnome pkgconfig tar:bz2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_GNOME=	cairo gdkpixbuf gtk30 intltool

post-patch:
	@${REINPLACE_CMD} -e \
		'/^Icon/s|=.*|=${PREFIX}/share/pixmaps/gpredict-icon.png|' \
		${WRKSRC}/data/desktop/gpredict.desktop.in

.include <bsd.port.mk>
