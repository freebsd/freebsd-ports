# $FreeBSD$

PORTNAME=	Test-Net-RabbitMQ
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl mock RabbitMQ implementation for use when testing

BUILD_DEPENDS=	p5-Moose>=0:devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
