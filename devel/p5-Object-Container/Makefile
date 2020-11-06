# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Object-Container
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple object container

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor
TEST_DEPENDS=	p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PORTSCOUT=	limit:^[0-9]*.[0-9][0-9]$$

.include <bsd.port.mk>
