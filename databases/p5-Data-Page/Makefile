# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	Data-Page
PORTVERSION=	2.02
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pager utility for Class::DBI

BUILD_DEPENDS=	p5-Class-Accessor-Chained>=0:devel/p5-Class-Accessor-Chained
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
