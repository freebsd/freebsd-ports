# New ports collection makefile for:	MooseX-Role-Parameterized
# Date created:	   18 Aug 2009
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Role-Parameterized
PORTVERSION=	0.19
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Roles with composition parameters

BUILD_DEPENDS=	p5-Moose>=0.78:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::Role::Parameterized.3 \
		MooseX::Role::Parameterized::Extending.3 \
		MooseX::Role::Parameterized::Meta::Parameter.3 \
		MooseX::Role::Parameterized::Meta::Role::Parameterizable.3 \
		MooseX::Role::Parameterized::Meta::Role::Parameterized.3 \
		MooseX::Role::Parameterized::Meta::Trait::Parameterized.3 \
		MooseX::Role::Parameterized::Parameters.3 \
		MooseX::Role::Parameterized::Tutorial.3

.include <bsd.port.mk>
