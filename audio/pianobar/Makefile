# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	pianobar
PORTVERSION=	2013.09.15
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
		libjson.so:${PORTSDIR}/devel/json-c \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

MAN1=		pianobar.1
MAN_COMPRESSED=	no

PLIST_FILES=	bin/pianobar

USES=		gmake pkgconfig
NO_STAGE=	yes
USE_BZIP2=	yes
MAKE_ARGS+=	CC="${CC}" PREFIX="${PREFIX}"

CFLAGS+=	-I${LOCALBASE}/include -std=c99
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
