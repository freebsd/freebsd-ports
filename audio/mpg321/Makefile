# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpg321
PORTVERSION=	0.2.10
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Command-line MP3 player, compatible with mpg123

LIB_DEPENDS=	libao.so:audio/libao \
		libid3tag.so:audio/libid3tag \
		libmad.so:audio/libmad

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-mpg123-symlink
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/mpg321 man/man1/mpg321.1.gz

OPTIONS_DEFINE=	SCROBBLER
SCROBBLER_DESC=	Last.fm Audioscrobbler support

SCROBBLER_RUN_DEPENDS=	scrobbler-helper:audio/p5-Audio-Scrobbler
SCROBBLER_PATCHFILES=	mpg321-0.2.10-scrobbler-01.patch:scrobbler
SCROBBLER_PATCH_SITES=	http://people.FreeBSD.org/~roam/ports/audio/:scrobbler \
		http://devel.ringlet.net/audio/mpg321-scrobbler/:scrobbler

.include <bsd.port.mk>
