# Created by: Ashish SHUKLA <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	MooseX-Object-Pluggable
PORTVERSION=	0.0014
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Make your classes pluggable

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Moose>=0:devel/p5-Moose \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-Module-Pluggable>=0:devel/p5-Module-Pluggable \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
