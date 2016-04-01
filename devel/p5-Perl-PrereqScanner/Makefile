# Created by: Geraud CONTINSOUZAS <geraud@gcu.info>
# $FreeBSD$

PORTNAME=	Perl-PrereqScanner
PORTVERSION=	1.023
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	geraud@gcu.info
COMMENT=	Tool to scan your Perl code for its prerequisites

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Getopt-Long-Descriptive>=0:devel/p5-Getopt-Long-Descriptive \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Module-Path>=0:devel/p5-Module-Path \
		p5-Moose>=0:devel/p5-Moose \
		p5-PPI>=1.215:textproc/p5-PPI \
		p5-Params-Util>=0:devel/p5-Params-Util \
		p5-String-RewritePrefix>=0.005:textproc/p5-String-RewritePrefix \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Try-Tiny>=0:lang/p5-Try-Tiny

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
