# ex:ts=8
# New ports collection makefile for:	postal
# Date created:			Apr 2, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	postal
PORTVERSION=	0.61
CATEGORIES=	benchmarks mail
MASTER_SITES=	http://www.coker.com.au/postal/
EXTRACT_SUFX=	.tgz

MAINTAINER=	chris@unixpages.org

USE_REINPLACE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

MAN8=	postal.8 postal-list.8 rabid.8

post-patch:
	@${REINPLACE_CMD} -e "s,-pthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

.include <bsd.port.mk>
