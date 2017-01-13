# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CPAN-Meta-Check
PORTVERSION=	0.014
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Verify requirements in a CPAN::Meta object

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Deep>0:devel/p5-Test-Deep

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
BUILD_DEPENDS+=	p5-Module-Metadata>=1.000023:devel/p5-Module-Metadata
RUN_DEPENDS+=	p5-Module-Metadata>=1.000023:devel/p5-Module-Metadata
.endif

.include <bsd.port.post.mk>
