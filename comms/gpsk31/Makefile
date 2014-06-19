# Created by: Søren Straarup <xride@x12.dk>
# $FreeBSD$

PORTNAME=	gpsk31
PORTVERSION=	0.3
PORTREVISION=	7
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.qsl.net/pg4i/download/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	A gtk psk31 client

USES=		pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

.include <bsd.port.mk>
