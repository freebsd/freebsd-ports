# New ports collection makefile for:	devel/p5-MooseX-OneArgNew
# Date created:				2011-09-19
# Whom:					Geraud CONTINSOUZAS <geraud@gcu.info>
#
# $FreeBSD$
#

PORTNAME=	MooseX-OneArgNew
PORTVERSION=	0.002
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
#MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	geraud@gcu.info
COMMENT=	Teach ->new to accept single, non-hashref arguments

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-MooseX-Role-Parameterized>=0:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	MooseX::OneArgNew.3

.include <bsd.port.mk>
