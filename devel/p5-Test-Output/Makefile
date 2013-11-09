# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Test-Output
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Utilities to test STDOUT and STDERR messages

BUILD_DEPENDS=	p5-Capture-Tiny>=0.17:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Tester>=0.10.7:${PORTSDIR}/devel/p5-Test-Tester

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
