# Created by: Nicolas Jombart <Nicolas.Jombart@hsc-labs.com>
# $FreeBSD$

PORTNAME=	Parallel-ForkManager
PORTVERSION=	1.18
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple parallel processing fork manager

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Warn>=0:devel/p5-Test-Warn

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
TEST_DEPENDS+=	p5-Test-Simple>=1.001:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
