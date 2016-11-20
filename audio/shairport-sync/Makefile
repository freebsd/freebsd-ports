# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shairport-sync
PORTVERSION=	2.8.6
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	AirPlay audio player with multi-room audio synchronisation capability

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libconfig.so:devel/libconfig \
		libdaemon.so:devel/libdaemon \
		libpopt.so:devel/popt \
		libsoxr.so:audio/libsoxr \
		libavahi-client.so:net/avahi-app

GNU_CONFIGURE=	yes
USES=		autoreconf libtool pkgconfig ssl
USE_GITHUB=	yes

USE_RC_SUBR=	${PORTNAME}

GH_ACCOUNT=	mikebrady

CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc \
		--with-piddir=/var/run/shairport-sync --with-avahi \
		--with-ssl=openssl --with-metadata --with-soxr --with-alsa \
		--with-stdout --with-pipe

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lcrypto

CONFIGURE_ENV+=	SSL_CFLAGS=-I${OPENSSLINC} SSL_LIBS=-L${OPENSSLLIB}

.include <bsd.port.mk>
