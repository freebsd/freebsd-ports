# New ports collection makefile for:	p5-Multiplex-CMD
# Date created:		21 March 2011
# Whom:			Andrey Ignatov <rdna@rdna.ru>
#
# $FreeBSD$
#

PORTNAME=	Multiplex-CMD
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	rdna@rdna.ru
COMMENT=	Perl5 module which provides Multiplexed Fork Client

PERL_CONFIGURE=	yes

MAN3=		Multiplex::CMD.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
RUN_DEPENDS=	p5-version>=0:${PORTSDIR}/devel/p5-version
.endif

.include <bsd.port.post.mk>
