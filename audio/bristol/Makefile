PORTNAME=	bristol
PORTVERSION=	0.60.10
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.60

MAINTAINER=	pierrejacques.mimifir@gmail.com
COMMENT=	Vintage synthesizers emulation for electric pianos and organs

LICENSE=	GPLv2

LIB_DEPENDS=	libjack.so:audio/jack \
		libfluidsynth.so:audio/fluidsynth

USES=		cpe libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CPE_VENDOR=	nick_copeland

CONFIGURE_ARGS+=	--disable-alsa --enable-oss \
			--enable-jack-default-audio \
			--enable-jack-default-midi \
			--disable-version-check

# Fix build on recent current (would require a handful of patches)
CFLAGS+=		-fcommon

PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|-march=core2 -msse -msse2 -mfpmath=sse||; s|-O3||' \
		${WRKSRC}/libbristol/Makefile.in
	@${REINPLACE_CMD} -e 's|-msse -mfpmath=sse||; s|-O2||' \
		${WRKSRC}/bristol/Makefile.in

.include <bsd.port.mk>
