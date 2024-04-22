PORTNAME=	fapg
PORTVERSION=	0.43
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://royale.zerezo.com/${PORTNAME}/

MAINTAINER=	m.muenz@gmail.com
COMMENT=	Fast Audio Playlist Generator
WWW=		http://royale.zerezo.com/fapg/

LICENSE=	GPLv2

LIB_DEPENDS=	liburiparser.so:net/uriparser

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=--with-uriparser="${LOCALBASE}"
PLIST_FILES=	bin/fapg share/man/man1/fapg.1.gz

.include <bsd.port.mk>
