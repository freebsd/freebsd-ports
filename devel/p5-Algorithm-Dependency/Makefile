# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Algorithm-Dependency
PORTVERSION=	1.111
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base class for implementing various dependency trees

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Params-Util>=0.31:devel/p5-Params-Util
TEST_DEPENDS=	p5-Test-ClassAPI>=0.6:devel/p5-Test-ClassAPI

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
