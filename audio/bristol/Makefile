# Created by: pjm <pierrejacqes.mimifir@gmail.com>
# $FreeBSD$

PORTNAME=	bristol
PORTVERSION=	0.60.10
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.60

MAINTAINER=	pierrejacques.mimifir@gmail.com
COMMENT=	Vintage synthesiers emulation for electric pianos and organs

LICENSE=	GPLv2

LIB_DEPENDS=	libjack.so:audio/jack \
		libfluidsynth.so:audio/fluidsynth

USES=		cpe libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
QT_COMPONENTS=	gui qmake_build moc_build uic_build rcc_build linguist_build
CPE_VENDOR=	nick_copeland

CONFIGURE_ARGS+=	--disable-alsa --enable-oss \
			--enable-jack-default-audio \
			--enable-jack-default-midi \
			--disable-version-check

PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|-march=core2 -msse -msse2 -mfpmath=sse||; s|-O3||' \
		${WRKSRC}/libbristol/Makefile.in
	@${REINPLACE_CMD} -e 's|-msse -mfpmath=sse||; s|-O2||' \
		${WRKSRC}/bristol/Makefile.in

.include <bsd.port.mk>
