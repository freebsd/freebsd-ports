# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	File-Flat
PORTVERSION=	1.04
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Implements a flat filesystem

BUILD_DEPENDS=	p5-File-NCopy>=0:devel/p5-File-NCopy \
		p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive \
		p5-File-Remove>=0:devel/p5-File-Remove \
		p5-Class-Autouse>=0:devel/p5-Class-Autouse \
		p5-prefork>=0:devel/p5-prefork
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-ClassAPI>=0:devel/p5-Test-ClassAPI

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
