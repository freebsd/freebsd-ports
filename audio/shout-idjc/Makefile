# Created by: Sean Bruno <sbruno@freebsd.org>
# $FreeBSD$

PORTNAME=	libshout-idjc
PORTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	SF/idjc/libshout-idjc/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	sbruno@FreeBSD.org
COMMENT=	Shoutcast/Icecast Library for audio/idjc

LICENSE=	LGPL20

LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libspeex.so:audio/speex

GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig autoreconf
PATHFIX_MAKEFILEIN=	Makefile.am
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} '/_XOPEN_SOURCE/d' ${WRKSRC}/configure

.include <bsd.port.mk>
