# Created by: ijliao
# $FreeBSD$

PORTNAME=	Class-DBI-AutoLoader
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generates Class::DBI subclasses dynamically

BUILD_DEPENDS=	p5-Class-DBI>=0:databases/p5-Class-DBI \
		p5-Class-DBI-BaseDSN>=0:databases/p5-Class-DBI-BaseDSN
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
