# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libcdaudio
PORTVERSION=	0.99.12p2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Library for playing audio CDs

USES=		libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcdaudio.so.1.*

.include <bsd.port.mk>
