# $FreeBSD$

PORTNAME=	Throwable
PORTVERSION=	0.200012
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy-to-use class for error objects

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Devel-StackTrace>=1.32:${PORTSDIR}/devel/p5-Devel-StackTrace \
		p5-Module-Runtime>=0.002:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Moo>=1.000001:${PORTSDIR}/devel/p5-Moo
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
