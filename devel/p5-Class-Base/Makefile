# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Class-Base
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Useful base class for deriving other modules

USES=		perl5
USE_PERL5=	configure

MAN3=		Class::Base.3

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} test

NO_STAGE=	yes
.include <bsd.port.mk>
