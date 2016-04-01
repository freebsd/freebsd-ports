# $FreeBSD$

PORTNAME=	Test-mysqld
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for mysqld test runner

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>0:devel/p5-Class-Accessor-Lite \
	p5-File-Copy-Recursive>0:devel/p5-File-Copy-Recursive \
	p5-DBD-mysql>=0:databases/p5-DBD-mysql \
	p5-Test-SharedFork>=0.06:devel/p5-Test-SharedFork
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
