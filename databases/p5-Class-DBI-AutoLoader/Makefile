# ex:ts=8
# Created by: ijliao
# $FreeBSD$

PORTNAME=	Class-DBI-AutoLoader
PORTVERSION=	0.12
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generates Class::DBI subclasses dynamically

BUILD_DEPENDS=	p5-Class-DBI>=0:${PORTSDIR}/databases/p5-Class-DBI \
		p5-Class-DBI-BaseDSN>=0:${PORTSDIR}/databases/p5-Class-DBI-BaseDSN
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Class::DBI::AutoLoader.3

.include <bsd.port.mk>
