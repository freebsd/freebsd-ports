# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Devel-ebug
PORTVERSION=	0.60
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple, extensible Perl debugger

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor-Chained>=0:devel/p5-Class-Accessor-Chained \
		p5-Devel-StackTrace>=0:devel/p5-Devel-StackTrace \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-Module-Pluggable>=0:devel/p5-Module-Pluggable \
		p5-PadWalker>=0:devel/p5-PadWalker \
		p5-Proc-Background>=0:devel/p5-Proc-Background \
		p5-String-Koremutake>=0:textproc/p5-String-Koremutake \
		p5-YAML>=0:textproc/p5-YAML
TEST_DEPENDS=	p5-Test-Expect>=0:devel/p5-Test-Expect

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
