# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Function-Parameters
PORTVERSION=	1.0704
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MAUKE
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Subroutine definitions with parameter lists

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Dir-Self>=0:devel/p5-Dir-Self \
		p5-Moo>=0:devel/p5-Moo \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-aliased>=0:devel/p5-aliased

PORTSCOUT=	limit:^[0-9\.]*$$

USE_PERL5=	configure
USES=		perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Function/Parameters/Parameters.so

.include <bsd.port.mk>
