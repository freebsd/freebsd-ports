# New ports collection makefile for:	p5-MooX-Types-MooseLike
# Date created:		2012-03-28
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooX-Types-MooseLike
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Some Moosish types and a typer builder

BUILD_DEPENDS=	p5-Moo>=0:${PORTSDIR}/devel/p5-Moo \
		p5-strictures>=1:${PORTSDIR}/devel/p5-strictures
RUN_DEPENDS=	p5-Moo>=0:${PORTSDIR}/devel/p5-Moo \
		p5-strictures>=1:${PORTSDIR}/devel/p5-strictures

TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

PERL_CONFIGURE=	yes

MAN3=		MooX::Types::MooseLike.3 \
		MooX::Types::MooseLike::Base.3 \
		MooX::Types::MooseLike::Numeric.3

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
