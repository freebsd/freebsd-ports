# $FreeBSD$

PORTNAME=	Test-File-ShareDir
PORTVERSION=	1.001001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Create a fake ShareDir for your modules for testing

BUILD_DEPENDS=	p5-Class-Tiny>0:devel/p5-Class-Tiny \
		p5-File-Copy-Recursive>0:devel/p5-File-Copy-Recursive \
		p5-File-ShareDir>=1.00:devel/p5-File-ShareDir \
		p5-Path-Tiny>=0.018:devel/p5-Path-Tiny \
		p5-Scope-Guard>0:devel/p5-Scope-Guard
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
