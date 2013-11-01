# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	self
PORTVERSION=	0.34
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GUGOD
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides "self" and "args" keywords in your OO program

BUILD_DEPENDS=	p5-B-Hooks-Parser>0:${PORTSDIR}/devel/p5-B-Hooks-Parser \
		p5-B-OPCheck>0:${PORTSDIR}/devel/p5-B-OPCheck \
		p5-Devel-Declare>0:${PORTSDIR}/devel/p5-Devel-Declare \
		p5-Sub-Exporter>0:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-PadWalker>=0:${PORTSDIR}/devel/p5-PadWalker

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
