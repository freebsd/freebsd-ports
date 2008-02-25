# New ports collection makefile for:	MooseX-Policy-SemiAffordanceAccessor
# Date created:	   25 February 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Policy-SemiAffordanceAccessor
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/D/DR/DROLSKY
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	A policy to name accessors foo() and set_foo()

RUN_DEPENDS=	${SITE_PERL}/Moose.pm:${PORTSDIR}/devel/p5-Moose \
		${SITE_PERL}/Moose/Policy.pm:${PORTSDIR}/devel/p5-Moose-Policy
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		MooseX::Policy::SemiAffordanceAccessor.3

.include <bsd.port.mk>
