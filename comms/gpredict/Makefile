# Created by: Matt Dawson <matt@mattsnetwork.co.uk>
# $FreeBSD$

PORTNAME=	gpredict
DISTVERSION=	2.2.1
CATEGORIES=	comms hamradio
MASTER_SITES=	https://github.com/csete/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio satellite tracking and prediction

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libhamlib.so:comms/hamlib \
		libgoocanvas-2.0.so:graphics/goocanvas2 \
		libgps.so:astro/gpsd

USES=		gettext gmake pkgconfig tar:bz2
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool

post-patch:
	@${REINPLACE_CMD} -e \
		'/^Icon/s|=.*|=${PREFIX}/share/pixmaps/gpredict-icon.png|' \
		${WRKSRC}/data/desktop/gpredict.desktop.in

.include <bsd.port.mk>
