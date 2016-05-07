# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	fapg
PORTVERSION=	0.42
CATEGORIES=	audio
MASTER_SITES=	http://royale.zerezo.com/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast Audio Playlist Generator

LICENSE=	GPLv2

LIB_DEPENDS=	liburiparser.so:net/uriparser

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-uriparser="${LOCALBASE}"
PLIST_FILES=	bin/fapg man/man1/fapg.1.gz

.include <bsd.port.mk>
