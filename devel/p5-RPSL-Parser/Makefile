# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	RPSL-Parser
PORTVERSION=	0.04000
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LMC
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Router Policy Specification Language (RFC2622) Parser

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0.31:devel/p5-Class-Accessor
RUN_DEPENDS:=	${BUILD_DEPENDS}

PORTSCOUT=	skipv:0.039001,0.039_001,0.19,0.28,0.29,0.32,0.38,0.39

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
