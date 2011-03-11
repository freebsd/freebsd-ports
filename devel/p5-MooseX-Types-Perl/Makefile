# New ports collection makefile for:	p5-MooseX-Types-Perl
# Date created:		2011-02-16
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Types-Perl
PORTVERSION=	0.101340
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Moose types that check against Perl syntax

RUN_DEPENDS=	p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Params-Util>=0:${PORTSDIR}/devel/p5-Params-Util

PERL_CONFIGURE=	yes

MAN3=		MooseX::Types::Perl.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
RUN_DEPENDS+=	p5-version>=0.82:${PORTSDIR}/devel/p5-version
.endif

.include <bsd.port.post.mk>
