# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GraphViz2-Parse-ISA
PORTVERSION=	2.54
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Visualize N Perl class hierarchies as a graph

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-GraphViz2>=2.48:graphics/p5-GraphViz2 \
		p5-Module-Runtime>=0.016:devel/p5-Module-Runtime \
		p5-Moo>=2.001001:devel/p5-Moo
TEST_DEPENDS=	p5-Test-Snapshot>=0.06:devel/p5-Test-Snapshot

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
