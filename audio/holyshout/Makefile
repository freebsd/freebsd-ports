# New ports collection makefile for:	holyshout
# Date created:				26 Aug 2000
# Whom:					JunSeon Oh <hollywar@mail.holywar.net>
#
# $FreeBSD$
#

PORTNAME=	holyshout
PORTVERSION=	0.2
PORTREVISION=	4
CATEGORIES=	audio net
MASTER_SITES=	ftp://ftp.holywar.net/pub/FreeBSD/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Streaming audio to Icecast/shoutcast supports multiple bitrate stream

LIB_DEPENDS=	shout.5:${PORTSDIR}/audio/libshout2 \
		mp3lame.0:${PORTSDIR}/audio/lame

PLIST_FILES=	bin/holyshout

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
