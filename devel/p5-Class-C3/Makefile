# $FreeBSD$

PORTNAME=	Class-C3
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pragma to use the C3 method resolution order algorithm

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

OPTIONS_DEFINE=	XS

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

XS_BUILD_DEPENDS=	p5-Class-C3-XS>=0.13:devel/p5-Class-C3-XS
XS_RUN_DEPENDS=		p5-Class-C3-XS>=0.13:devel/p5-Class-C3-XS
XS_BUILD_DEPENDS_OFF=	p5-Algorithm-C3>=0.07:devel/p5-Algorithm-C3
XS_RUN_DEPENDS_OFF=	p5-Algorithm-C3>=0.07:devel/p5-Algorithm-C3

.include <bsd.port.mk>
