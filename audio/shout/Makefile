# Created by: will
# $FreeBSD$

PORTNAME=	shout
PORTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	audio net
MASTER_SITES=	http://downloads.xiph.org/releases/libshout/ \
		http://downloads.us.xiph.org/releases/libshout/ \
		http://public.planetmirror.com/pub/xiph/releases/libshout/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Send mp3 streams to an icecast/shoutcast server

GNU_CONFIGURE=	yes

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

.include <bsd.port.mk>
