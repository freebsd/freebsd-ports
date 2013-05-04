# Created by: Alexey V. Antipovsky <kemm@in-line.ru>
# $FreeBSD$

PORTNAME=	fuse
PORTVERSION=	1.0.0.1
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}-emulator/${PORTNAME}/${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Free Unix (Sinclair ZX-)Spectrum Emulator

LICENSE=	GPLv2

LIB_DEPENDS=	spectrum.8:${PORTSDIR}/emulators/libspectrum \
		png15:${PORTSDIR}/graphics/png \
		gcrypt:${PORTSDIR}/security/libgcrypt

GNU_CONFIGURE=	yes
USE_GNOME=	libxml2 glib20 gtk20

CONFIGURE_ARGS+=--without-alsa --without-joystick
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}

MAN1=		fuse.1

OPTIONS_DEFINE=	AO SAMPLERATE
OPTIONS_DEFAULT=	SAMPLERATE
AO_DESC=	Use libao for audio output
SAMPLERATE_DESC=	Better beeper sound quality

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAO}
CONFIGURE_ARGS+=--with-libao
LIB_DEPENDS+=	ao.4:${PORTSDIR}/audio/libao
.else
CONFIGURE_ARGS+=--without-libao
.endif

.if ${PORT_OPTIONS:MSAMPLERATE}
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
.else
CONFIGURE_ARGS+=--without-libsamplerate
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog README THANKS \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
