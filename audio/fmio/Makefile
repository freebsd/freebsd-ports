# New ports collection makefile for:	fmio
# Date created:				10 Feb 2001
# Whom:					Den Ivanov <d.s.div@bigfoot.com>
#
# $FreeBSD$
#

PORTNAME=	fmio
PORTVERSION=	1.2.18
CATEGORIES=	audio
MASTER_SITES=	http://www.jumbo.narod.ru/src/fmio/

MAINTAINER=	kunia@istc.kiev.ua

MAN1=		fmio.1
MANCOMPRESSED=	no

pre-build:
	${PERL} -pi.orig -e "s@lib fmio man@lib fmio@g; \
			     s@install -c -o root@#install@g" ${WRKSRC}/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/fmio.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
