# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	IOC
PORTVERSION=	0.29
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:STEVAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lightweight IOC (Inversion of Control) framework

BUILD_DEPENDS=	p5-Class-Throwable>=0:devel/p5-Class-Throwable \
		p5-XML-SAX>=0:textproc/p5-XML-SAX \
		p5-Class-StrongSingleton>=0:devel/p5-Class-StrongSingleton \
		p5-Class-Interfaces>=0:devel/p5-Class-Interfaces
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
