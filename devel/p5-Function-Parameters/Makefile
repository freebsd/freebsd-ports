# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Function-Parameters
PORTVERSION=	1.03.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MAUKE
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Subroutine definitions with parameter lists

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Dir-Self>=0:${PORTSDIR}/devel/p5-Dir-Self \
		p5-Moo>=0:${PORTSDIR}/devel/p5-Moo \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-aliased>=0:${PORTSDIR}/devel/p5-aliased

USE_PERL5=	5.14+ configure
USES=		perl5

MAN3=		Function::Parameters.3 \
		Function::Parameters::Info.3

.include <bsd.port.mk>
