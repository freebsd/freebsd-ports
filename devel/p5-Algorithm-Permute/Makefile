# Created by: will
# $FreeBSD$

PORTNAME=	Algorithm-Permute
PORTVERSION=	0.16
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to handy and fast permutation

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Test-LeakTrace>=0:devel/p5-Test-LeakTrace

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Algorithm/Permute/Permute.so

.include <bsd.port.mk>
