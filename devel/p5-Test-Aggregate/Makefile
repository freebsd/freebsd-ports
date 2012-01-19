# New ports collection makefile for:	p5-Test-Aggregate
# Date created:		2012-01-18
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Aggregate
PORTVERSION=	0.364
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Aggregate perl tests for better performance

BUILD_DEPENDS=	p5-Test-Most>=0:${PORTSDIR}/devel/p5-Test-Most \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings
RUN_DEPENDS=	p5-Test-Most>=0:${PORTSDIR}/devel/p5-Test-Most \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings

PERL_CONFIGURE=	yes

MAN3=	Test::Aggregate.3 Test::Aggregate::Base.3 \
	Test::Aggregate::Builder.3 Test::Aggregate::Nested.3

.include <bsd.port.mk>
