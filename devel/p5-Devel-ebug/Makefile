# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Devel-ebug
PORTVERSION=	0.56
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple, extensible Perl debugger

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Class-Accessor-Chained>=0:devel/p5-Class-Accessor-Chained \
		p5-Devel-StackTrace>=0:devel/p5-Devel-StackTrace \
		p5-PadWalker>=0:devel/p5-PadWalker \
		p5-Proc-Background>=0:devel/p5-Proc-Background \
		p5-String-Koremutake>=0:textproc/p5-String-Koremutake \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Expect>=0:devel/p5-Test-Expect \
		p5-YAML>=0:textproc/p5-YAML

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
