# New ports collection makefile for:	p5-MooseX-MarkAsMethods
# Date created:		2011-11-03
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-MarkAsMethods
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mark overload code symbols as methods

BUILD_DEPENDS=	p5-B-Hooks-EndOfScope>=0:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-Moose>=0.94:${PORTSDIR}/devel/p5-Moose \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS=	p5-B-Hooks-EndOfScope>=0:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-Moose>=0.94:${PORTSDIR}/devel/p5-Moose \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean

PERL_CONFIGURE=	yes

MAN3=		MooseX::MarkAsMethods.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501200
TEST_DEPENDS+=	p5-Test-Simple>=0.94:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
