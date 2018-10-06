# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-Types-URI
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	URI related types and coercions for Moose

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Types>=0.40:devel/p5-MooseX-Types \
		p5-MooseX-Types-Path-Class>=0:devel/p5-MooseX-Types-Path-Class \
		p5-URI>=0:net/p5-URI \
		p5-URI-FromHash>=0:net/p5-URI-FromHash \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean

NO_ARCH=	yes
USE_PERL5=	modbuildtiny
USES=		perl5

.include <bsd.port.mk>
