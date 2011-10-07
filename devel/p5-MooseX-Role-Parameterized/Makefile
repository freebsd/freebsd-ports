# New ports collection makefile for:	MooseX-Role-Parameterized
# Date created:	   18 Aug 2009
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Role-Parameterized
PORTVERSION=	0.27
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SARTAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Roles with composition parameters

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.78:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS=	p5-Moose>=0.78:${PORTSDIR}/devel/p5-Moose

TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Simple>0:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		MooseX::Role::Parameterized.3 \
		MooseX::Role::Parameterized::Extending.3 \
		MooseX::Role::Parameterized::Meta::Role::Parameterizable.3 \
		MooseX::Role::Parameterized::Meta::Role::Parameterized.3 \
		MooseX::Role::Parameterized::Meta::Trait::Parameterized.3 \
		MooseX::Role::Parameterized::Parameters.3 \
		MooseX::Role::Parameterized::Tutorial.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.76:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
