# New ports collection makefile for:	holyshout
# Date created:				26 Aug 2000
# Whom:					JunSeon Oh <hollywar@mail.holywar.net>
#
# $FreeBSD$
#

PORTNAME=	holyshout
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	audio net
MASTER_SITES=	ftp://ftp.holywar.net/pub/FreeBSD/

MAINTAINER=	hollywar@mail.holywar.net
COMMENT=	Streaming audio to Icecast/shoutcast supports multiple bitrate stream

LIB_DEPENDS=	shout.2:${PORTSDIR}/audio/libshout

USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,,\\r,g' ${WRKSRC}/holyshout.c

.include <bsd.port.mk>
