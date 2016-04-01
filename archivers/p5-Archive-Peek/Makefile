# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Archive-Peek
PORTVERSION=	0.35
PORTREVISION=	1
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Peek into archives without extracting them

BUILD_DEPENDS=	p5-Archive-Tar>=0:archivers/p5-Archive-Tar \
		p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Types-Path-Class>=0:devel/p5-MooseX-Types-Path-Class
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Pod>=1.14:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

regression-test: build
	cd ${WRKSRC}/ && ${MAKE} test

.include <bsd.port.mk>
