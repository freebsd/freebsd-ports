# New ports collection makefile for:	irssistats
# Date created:			14 Feb 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	irssistats
PORTVERSION=	0.6
CATEGORIES=	irc
MASTER_SITES=	http://royale.zerezo.com/irssistats/

MAINTAINER=	tlp@liquidx.org
COMMENT=	Generate IRC statistics based on irssi logs

USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
