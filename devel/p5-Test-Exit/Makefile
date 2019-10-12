# $FreeBSD$

PORTNAME=	Test-Exit
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Test whether code exits without terminating testing

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Return-MultiLevel>=0:devel/p5-Return-MultiLevel

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes
PLIST_FILES=	${SITE_PERL_REL}/Test/Exit.pm \
		${SITE_MAN3_REL}/Test::Exit.3.gz

.include <bsd.port.mk>
