# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Algorithm-Dependency
PORTVERSION=	1.110
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base class for implementing various dependency trees

RUN_DEPENDS=	p5-Params-Util>=0.31:${PORTSDIR}/devel/p5-Params-Util
BUILD_DEPENDS:=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-ClassAPI>=0.6:${PORTSDIR}/devel/p5-Test-ClassAPI

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
