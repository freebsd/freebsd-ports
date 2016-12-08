# Created by: ijliao
# $FreeBSD$

PORTNAME=	vorbisgain
PORTVERSION=	0.37
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://sjeng.org/ftp/vorbis/

MAINTAINER=	gamato@users.sf.net
COMMENT=	Calculates the perceived sound level of an Ogg Vorbis file

OPTIONS_DEFINE=	RECURSIVE
RECURSIVE_DESC=	recursive processing and pattern matching

LIB_DEPENDS=	libvorbis.so:audio/libvorbis

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/vorbisgain \
		man/man1/vorbisgain.1.gz

RECURSIVE_CONFIGURE_ARGS=	--enable-recursive

.include <bsd.port.mk>
