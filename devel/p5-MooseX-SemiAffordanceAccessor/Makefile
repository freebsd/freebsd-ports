# New ports collection makefile for:	p5-MooseX-SemiAffordanceAccessor
# Date created:				Fri 14 Aug 2009
# Whom:					Alexey V. Degtyarev
#
# $FreeBSD$
#

PORTNAME=	MooseX-SemiAffordanceAccessor
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DR/DROLSKY
PKGNAMEPREFIX=	p5-

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Name your accessors foo() and set_foo()

RUN_DEPENDS=	p5-Moose>=0.85:${PORTSDIR}/devel/p5-Moose
BUILD_DEPENDS=	${RUN_DEPENDS}

MAN3=		MooseX::SemiAffordanceAccessor.3 \
		MooseX::SemiAffordanceAccessor::Role::Attribute.3

PERL_MODBUILD=	yes

.include <bsd.port.mk>
