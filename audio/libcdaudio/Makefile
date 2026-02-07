PORTNAME=	libcdaudio
PORTVERSION=	0.99.12p2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for playing audio CDs
WWW=		https://libcdaudio.sourceforge.net/

USES=		libtool pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcdaudio.so.1.*

.include <bsd.port.mk>
