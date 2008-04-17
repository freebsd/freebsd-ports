# New ports collection makefile for:	p5-Games-Alak
# Date created:		2006-08-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Games-Alak
PORTVERSION=	0.19
CATEGORIES=	games perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple game-tree implementation of a gomoku-like game

PERL_CONFIGURE=	yes

MAN3=		Games::Alak.3

post-patch:
	${REINPLACE_CMD} -e "s,^build_.*,,g" ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
