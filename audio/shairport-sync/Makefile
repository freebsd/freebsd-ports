# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shairport-sync
DISTVERSION=	3.3.5
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	AirPlay audio player with multi-room audio synchronisation capability

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
		libconfig.so:devel/libconfig \
		libdaemon.so:devel/libdaemon \
		libpopt.so:devel/popt \
		libsoxr.so:audio/libsoxr

USES=		autoreconf libtool pkgconfig ssl
USE_GITHUB=	yes

GNU_CONFIGURE=	yes

GH_ACCOUNT=	mikebrady

USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=	ALAC ALSA SNDIO PULSEAUDIO
OPTIONS_DEFAULT=SNDIO
ALAC_DESC=	Build with libalac support (experimental)

CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc \
		--with-piddir=/var/run/shairport-sync --with-avahi \
		--with-ssl=openssl --with-metadata --with-soxr \
		--with-stdout --with-pipe --with-libdaemon

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lcrypto

CONFIGURE_ENV+=	SSL_CFLAGS=-I${OPENSSLINC} SSL_LIBS=-L${OPENSSLLIB}

ALAC_LIB_DEPENDS=	libalac.so:audio/alac
ALAC_CONFIGURE_ON=	--with-apple-alac

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ON=	--with-alsa

SNDIO_CONFIGURE_ON=	--with-sndio
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio

PULSEAUDIO_CONFIGURE_ON=--with-pa
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

post-patch:
	@${REINPLACE_CMD} -e 's/-Wno-clobbered -Wno-psabi //' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
