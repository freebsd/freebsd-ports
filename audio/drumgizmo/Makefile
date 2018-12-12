# Created by: Goran Mekić <meka@tilda.center>
# $FreeBSD$

PORTNAME=	drumgizmo
PORTVERSION=	0.9.16
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.drumgizmo.org/releases/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	meka@tilda.center
COMMENT=	Multichannel drum sampler

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>=1.14.0:audio/lv2 \
		pkg-config:devel/pkgconf
LIB_DEPENDS=	libsmf.so:audio/libsmf \
		libzita-resampler.so:audio/zita-resampler \
		libjack.so:audio/jack \
		libsndfile.so:audio/libsndfile \
		libexpat.so:textproc/expat2

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lang gettext-runtime gnome libtool
USE_GNOME=	glib20
USE_XORG=	x11 xext

CPPFLAGS+=	-I../include -I../../include -I../src -I../../src

CONFIGURE_ENV=	EXPAT_CFLAGS=-isystem${LOCALBASE}/include EXPAT_LDFLAGS=-L${LOCALBASE}/lib \
		ZITA_CPPFLAGS=-isystem${LOCALBASE}/include ZITA_LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-output-alsa --enable-lv2

.include <bsd.port.mk>
