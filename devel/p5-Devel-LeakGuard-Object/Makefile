# Created by: TERAMOTO Masahiro <markun@onohara.to>
# $FreeBSD$

PORTNAME=	Devel-LeakGuard-Object
PORTVERSION=	0.06
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Scoped checks for object leaks

BUILD_DEPENDS=	p5-Test-Differences>=0:devel/p5-Test-Differences
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-latest>0:devel/p5-latest

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
