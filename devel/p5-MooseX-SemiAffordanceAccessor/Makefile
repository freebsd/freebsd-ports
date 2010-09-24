# New ports collection makefile for:	p5-MooseX-SemiAffordanceAccessor
# Date created:				Fri 14 Aug 2009
# Whom:					Alexey V. Degtyarev
#
# $FreeBSD$
#

PORTNAME=	MooseX-SemiAffordanceAccessor
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DR/DROLSKY
PKGNAMEPREFIX=	p5-

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Name your accessors foo() and set_foo()

BUILD_DEPENDS=	p5-Moose>=0.94:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS=	p5-Moose>=0.94:${PORTSDIR}/devel/p5-Moose

MAN3=		MooseX::SemiAffordanceAccessor.3 \
		MooseX::SemiAffordanceAccessor::Role::Attribute.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
