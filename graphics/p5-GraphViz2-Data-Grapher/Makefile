# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GraphViz2-Data-Grapher
PORTVERSION=	2.51
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Visualize a data structure as a graph

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-GraphViz2>=2.48:graphics/p5-GraphViz2 \
		p5-Moo>=2.001001:devel/p5-Moo \
		p5-Tree-DAG_Node>=1.06:devel/p5-Tree-DAG_Node
TEST_DEPENDS=	p5-File-Slurp>=9999.19:devel/p5-File-Slurp \
		p5-Test-Snapshot>=0.06:devel/p5-Test-Snapshot \
		p5-XML-Bare>=0:textproc/p5-XML-Bare

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
