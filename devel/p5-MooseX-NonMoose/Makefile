# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-NonMoose
PORTVERSION=	0.25
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy subclassing of non-Moose classes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Runtime>=0:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Moose>=2:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-MooseX-InsideOut>=0:${PORTSDIR}/devel/p5-MooseX-InsideOut \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
