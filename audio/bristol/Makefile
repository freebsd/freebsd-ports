# Created by: pjm <pierrejacqes.mimifir@gmail.com>
# $FreeBSD$

PORTNAME=	bristol
PORTVERSION=	0.60.10
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.60

MAINTAINER=	pierrejacques.mimifir@gmail.com
COMMENT=	Vintage synthesiers emulation for electric pianos and organs

LICENSE=	GPLv2

LIB_DEPENDS=	libjack.so:audio/jack \
		libfluidsynth.so:audio/fluidsynth

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
QT_COMPONENTS=	gui qmake_build moc_build uic_build rcc_build linguist_build

CONFIGURE_ARGS+=	--disable-alsa --enable-oss \
			--enable-jack-default-audio \
			--enable-jack-default-midi \
			--disable-version-check

BROKEN_aarch64=		Does not build: error: unknown FP unit 'sse'
BROKEN_armv6=		Does not build: error: unknown FP unit 'sse'
BROKEN_armv7=		Does not build: error: unknown FP unit 'sse'
BROKEN_mips64=		Does not build: error: unknown FP unit 'sse'
BROKEN_powerpc64=	Does not build: error: unknown FP unit 'sse'

PORTDATA=	*

.include <bsd.port.mk>
