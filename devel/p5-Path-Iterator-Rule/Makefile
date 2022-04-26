PORTNAME=	Path-Iterator-Rule
PORTVERSION=	1.015
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for iterative, recursive file finder

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Number-Compare>=0.02:math/p5-Number-Compare \
		p5-Text-Glob>=0:textproc/p5-Text-Glob \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-File-pushd>=0:devel/p5-File-pushd \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Filename>=0.03:devel/p5-Test-Filename

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
