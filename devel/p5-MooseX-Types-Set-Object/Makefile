# New ports collection makefile for:	p5-MooseX-Types-Set-Object
# Date created:		2011-06-11
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Types-Set-Object
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set::Object type with coercions and stuff

RUN_DEPENDS=	p5-Moose>=0.50:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Set-Object>=0:${PORTSDIR}/devel/p5-Set-Object
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok

PERL_CONFIGURE=	yes

MAN3=		MooseX::Types::Set::Object.3

.include <bsd.port.mk>
