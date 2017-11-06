# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Archive-Peek
PORTVERSION=	0.35
PORTREVISION=	2
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Peek into archives without extracting them

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Types-Path-Class>=0:devel/p5-MooseX-Types-Path-Class
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1.14:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
