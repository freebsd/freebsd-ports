# Created by: Sahil Tandon <sahil@tandon.net>
# $FreeBSD$

PORTNAME=	MooseX-Types-Common
PORTVERSION=	0.001014
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Set of commonly-used type constraints that do not ship with p5-Moose

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moose>=0.39:devel/p5-Moose \
		p5-MooseX-Types>=0.04:devel/p5-MooseX-Types
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Warnings>=0.005:devel/p5-Test-Warnings

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
