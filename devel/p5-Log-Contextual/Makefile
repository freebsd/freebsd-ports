# $FreeBSD$

PORTNAME=	Log-Contextual
PORTVERSION=	0.006000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for simple logging interface with a contextual log

RUN_DEPENDS=	\
	p5-Data-Dumper-Concise>0:${PORTSDIR}/devel/p5-Data-Dumper-Concise \
	p5-Exporter-Declare>=0.111:${PORTSDIR}/devel/p5-Exporter-Declare \
	p5-Moo>=1.003:${PORTSDIR}/devel/p5-Moo
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Log-Log4perl>0:${PORTSDIR}/devel/p5-Log-Log4perl

USES=	perl5
USE_PERL5=	configure

.include <bsd.port.mk>
