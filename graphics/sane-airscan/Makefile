PORTNAME=	sane-airscan
DISTVERSION=	0.99.29
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	SANE backend for AirScan (eSCL) and WSD document scanners
WWW=		https://github.com/alexpevzner/sane-airscan

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	sane-backends>0:graphics/sane-backends
LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
		libgnutls.so:security/gnutls \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		gnome jpeg meson pkgconfig
USE_GNOME=	libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	alexpevzner

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/sane.d/airscan.conf \
		${STAGEDIR}${PREFIX}/etc/sane.d/airscan.conf.sample

.include <bsd.port.mk>
