# Created by: ijliao
# $FreeBSD$

PORTNAME=	Algorithm-Evolutionary
PORTVERSION=	0.80
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Library for doing evolutionary computation in Perl

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Algorithm-Permute>=0.01:devel/p5-Algorithm-Permute \
		p5-Bit-Vector>=0:math/p5-Bit-Vector \
		p5-Clone>=0.31:devel/p5-Clone \
		p5-GD>=2.17:graphics/p5-GD \
		p5-Math-Random>=0.63:math/p5-Math-Random \
		p5-Object-Array>=0:devel/p5-Object-Array \
		p5-Sort-Key>=0:devel/p5-Sort-Key \
		p5-Statistics-Basic>=1.6:math/p5-Statistics-Basic \
		p5-String-Random>=0:devel/p5-String-Random \
		p5-Tree-DAG_Node>=1.04:devel/p5-Tree-DAG_Node \
		p5-XML-LibXML>=1.5:textproc/p5-XML-LibXML \
		p5-XML-Parser>=2.40:textproc/p5-XML-Parser \
		p5-XML-Parser-Style-EasyTree>=0:textproc/p5-XML-Parser-Style-EasyTree \
		p5-YAML>=0:textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Pod-Escapes>=0:textproc/p5-Pod-Escapes \
		p5-Test-Pod>=0:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
