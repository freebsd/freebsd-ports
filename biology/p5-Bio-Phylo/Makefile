# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Bio-Phylo
PORTVERSION=	0.58
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Phylogenetic analysis using Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-GD>=0:graphics/p5-GD \
		p5-Math-CDF>=0:math/p5-Math-CDF \
		p5-Math-Random>=0:math/p5-Math-Random \
		p5-PDF-API2>=0:textproc/p5-PDF-API2 \
		p5-SVG>=0:textproc/p5-SVG \
		p5-SWF-Builder>=0:graphics/p5-SWF-Builder \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-XML-Twig>=0:textproc/p5-XML-Twig \
		p5-XML-XML2JSON>=0:textproc/p5-XML-XML2JSON \
		p5-bioperl>=0:biology/p5-bioperl \
		p5-libxml>=0:textproc/p5-libxml
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-JSON>=0:converters/p5-JSON

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e '/NAME/ s|Bio-Phylo|Bio::Phylo|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
