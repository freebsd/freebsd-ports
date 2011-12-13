# New ports collection makefile for:	p5-MooseX-Types-DateTime
# Date created:		2011-12-12
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Types-DateTime
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ILMARI
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	DateTime related constraints and coercions for Moose

BUILD_DEPENDS=	p5-DateTime>=0.43.02:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Locale>=0.45:${PORTSDIR}/devel/p5-DateTime-Locale \
		p5-DateTime-TimeZone>=0.95:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-Moose>=0.41:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0.30:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-namespace-clean>=0.08:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Exception>=0.27:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-use-ok>=0.02:${PORTSDIR}/devel/p5-Test-use-ok

PERL_CONFIGURE=	yes

MAN3=		MooseX::Types::DateTime.3

.include <bsd.port.mk>
