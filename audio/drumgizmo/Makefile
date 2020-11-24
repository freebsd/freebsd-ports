# Created by: Goran Mekić <meka@tilda.center>
# $FreeBSD$

PORTNAME=	drumgizmo
PORTVERSION=	0.9.19
CATEGORIES=	audio
MASTER_SITES=	http://www.drumgizmo.org/releases/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	meka@tilda.center
COMMENT=	Multichannel drum sampler

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>=1.14.0:audio/lv2
LIB_DEPENDS=	libsmf.so:audio/libsmf \
		libzita-resampler.so:audio/zita-resampler \
		libjack.so:audio/jack \
		libsndfile.so:audio/libsndfile \
		libexpat.so:textproc/expat2

USES=		compiler:c++11-lang gnome libtool pkgconfig xorg
USE_GNOME=	glib20
USE_XORG=	x11 xext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-output-alsa --enable-lv2
CONFIGURE_ENV=	EXPAT_CFLAGS=-isystem${LOCALBASE}/include EXPAT_LDFLAGS=-L${LOCALBASE}/lib \
		ZITA_CPPFLAGS=-isystem${LOCALBASE}/include ZITA_LDFLAGS=-L${LOCALBASE}/lib

CPPFLAGS+=	-I../include -I../../include -I../src -I../../src -I${LOCALBASE}/include

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext-runtime gettext-tools

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/drumgizmo.lv2/drumgizmo.so

.include <bsd.port.mk>
