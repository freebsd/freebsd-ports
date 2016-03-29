# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	pianobar
PORTVERSION=	2015.11.22
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://6xq.net/projects/${PORTNAME}/

MAINTAINER=	john@pcbsd.org
COMMENT=	Command line Pandora player

LICENSE=	MIT

LIB_DEPENDS=	libao.so:${PORTSDIR}/audio/libao \
		libfaad.so:${PORTSDIR}/audio/faad \
		libmad.so:${PORTSDIR}/audio/libmad \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libjson-c.so:${PORTSDIR}/devel/json-c \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libcurl.so:${PORTSDIR}/ftp/curl

PLIST_FILES=	bin/pianobar \
		man/man1/pianobar.1.gz

USES=		alias gmake pkgconfig tar:bzip2
MAKE_ARGS+=	CC="${CC}" PREFIX="${PREFIX}"

CFLAGS+=	-I${LOCALBASE}/include -std=c99
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
