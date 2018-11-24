# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Git-Repository
PORTVERSION=	1.323
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to Git repositories

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	git:devel/git \
		p5-Git-Version-Compare>=1.001:devel/p5-Git-Version-Compare \
		p5-System-Command>=1.118:devel/p5-System-Command \
		p5-namespace-clean>=0:devel/p5-namespace-clean
TEST_DEPENDS=	p5-Test-Requires-Git>=1.005:devel/p5-Test-Requires-Git

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
