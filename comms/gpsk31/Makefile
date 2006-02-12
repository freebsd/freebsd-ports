# New ports collection makefile for:	gpsk31
# Date created:		2005-05-27
# Whom:				Søren Straarup <xride@x12.dk>
#
# $FreeBSD$

PORTNAME=	gpsk31
PORTVERSION=	0.3
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.qsl.net/pg4i/download/

MAINTAINER=	xride@x12.dk
COMMENT=	A gtk psk31 client

BROKEN=		Incomplete pkg-plist

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

MAN1=	gpsk31.1
.include <bsd.port.mk>
