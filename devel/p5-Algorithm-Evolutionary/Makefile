# Created by: ijliao
# $FreeBSD$

PORTNAME=	Algorithm-Evolutionary
PORTVERSION=	0.80
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Library for doing evolutionary computation in Perl

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Algorithm-Permute>=0.01:${PORTSDIR}/devel/p5-Algorithm-Permute \
		p5-Bit-Vector>=0:${PORTSDIR}/math/p5-Bit-Vector \
		p5-Clone>=0.31:${PORTSDIR}/devel/p5-Clone \
		p5-GD>=2.17:${PORTSDIR}/graphics/p5-GD \
		p5-Math-Random>=0.63:${PORTSDIR}/math/p5-Math-Random \
		p5-Object-Array>=0:${PORTSDIR}/devel/p5-Object-Array \
		p5-Sort-Key>=0:${PORTSDIR}/devel/p5-Sort-Key \
		p5-Statistics-Basic>=1.6:${PORTSDIR}/math/p5-Statistics-Basic \
		p5-String-Random>=0:${PORTSDIR}/devel/p5-String-Random \
		p5-Tree-DAG_Node>=1.04:${PORTSDIR}/devel/p5-Tree-DAG_Node \
		p5-XML-LibXML>=1.5:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-Parser>=2.40:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Parser-Style-EasyTree>=0:${PORTSDIR}/textproc/p5-XML-Parser-Style-EasyTree \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Pod-Escapes>=0:${PORTSDIR}/textproc/p5-Pod-Escapes \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
