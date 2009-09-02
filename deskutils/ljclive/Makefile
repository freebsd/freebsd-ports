# New ports collection makefile for:	clive
# Date created:				15 March 2004
# Whom:					johans
#
# $FreeBSD$
#

PORTNAME=	clive
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	SF/lj${PORTNAME}/lj${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	johans@stack.nl
COMMENT=	A command line client for posting LiveJournal entries

USE_ICONV=	yes

MAN1=	clive.1

GNU_CONFIGURE=	yes

CONFLICTS=	*clive-[1-9]*
LATEST_LINK=	ljclive

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} 's/iconv "iconv/"iconv/' ${WRKSRC}/configure

.include <bsd.port.post.mk>
