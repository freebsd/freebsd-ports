# New ports collection makefile for:	MooseX-Meta-TypeConstraint-ForceCoercion
# Date created:	   13 May 2009
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Meta-TypeConstraint-ForceCoercion
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Force coercion when validating type constraints

BUILD_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::Meta::TypeConstraint::ForceCoercion.3

.include <bsd.port.mk>
