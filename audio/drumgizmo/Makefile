PORTNAME=	drumgizmo
PORTVERSION=	0.9.19
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.drumgizmo.org/releases/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	meka@sys.it.com
COMMENT=	Multichannel drum sampler
WWW=		https://www.drumgizmo.org/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le

BUILD_DEPENDS=	lv2>=1.14.0:audio/lv2
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libjack.so:audio/jack \
		libsmf.so:audio/libsmf \
		libsndfile.so:audio/libsndfile \
		libzita-resampler.so:audio/zita-resampler

USES=		compiler:c++11-lang gnome libtool pkgconfig xorg
USE_GNOME=	glib20
USE_XORG=	x11 xext

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--disable-output-alsa \
		--enable-lv2
CONFIGURE_ENV=	EXPAT_CFLAGS=-isystem${LOCALBASE}/include \
		EXPAT_LDFLAGS=-L${LOCALBASE}/lib \
		ZITA_CPPFLAGS=-isystem${LOCALBASE}/include \
		ZITA_LDFLAGS=-L${LOCALBASE}/lib

CPPFLAGS+=	-I../include -I../../include -I../src -I../../src \
		-I${LOCALBASE}/include

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext-runtime gettext-tools

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/drumgizmo.lv2/drumgizmo.so

.include <bsd.port.mk>
