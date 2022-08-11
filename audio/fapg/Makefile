PORTNAME=	fapg
PORTVERSION=	0.43
CATEGORIES=	audio
MASTER_SITES=	http://royale.zerezo.com/${PORTNAME}/

MAINTAINER=	m.muenz@gmail.com
COMMENT=	Fast Audio Playlist Generator

LICENSE=	GPLv2

LIB_DEPENDS=	liburiparser.so:net/uriparser

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-uriparser="${LOCALBASE}"
PLIST_FILES=	bin/fapg man/man1/fapg.1.gz

.include <bsd.port.mk>
