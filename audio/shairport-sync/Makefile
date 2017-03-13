# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shairport-sync
PORTVERSION=	3.0.2
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	AirPlay audio player with multi-room audio synchronisation capability

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
		libconfig.so:devel/libconfig \
		libdaemon.so:devel/libdaemon \
		libpopt.so:devel/popt \
		libsoxr.so:audio/libsoxr \
		libasound.so:audio/alsa-lib

GNU_CONFIGURE=	yes
USES=		autoreconf libtool pkgconfig ssl

USE_GITHUB=	yes
GH_ACCOUNT=	mikebrady

USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=	ALAC
ALAC_DESC=	Build with libalac support (experimental)

CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc \
		--with-piddir=/var/run/shairport-sync --with-avahi \
		--with-ssl=openssl --with-metadata --with-soxr --with-alsa \
		--with-stdout --with-pipe

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lcrypto

CONFIGURE_ENV+=	SSL_CFLAGS=-I${OPENSSLINC} SSL_LIBS=-L${OPENSSLLIB}

ALAC_LIB_DEPENDS=	libalac.so:audio/alac
ALAC_CONFIGURE_ON=	--with-apple-alac

.include <bsd.port.mk>
