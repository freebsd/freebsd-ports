PORTNAME=	App-perlbrew
PORTVERSION=	1.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GUGOD
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl Environment manager
WWW=		https://metacpan.org/release/App-perlbrew

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CPAN-Perl-Releases>=5.20240920:devel/p5-CPAN-Perl-Releases \
		p5-Capture-Tiny>=0.48:devel/p5-Capture-Tiny \
		p5-Devel-PatchPerl>=2.08:devel/p5-Devel-PatchPerl \
		p5-local-lib>=2.000014:devel/p5-local-lib
TEST_DEPENDS=	p5-File-Which>=1.21:sysutils/p5-File-Which \
		p5-Path-Class>=0.33:devel/p5-Path-Class \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple \
		p5-Test2-Plugin-IOEvents>=0.001001:devel/p5-Test2-Plugin-IOEvents \
		p5-Test2-Plugin-NoWarnings>=0.10:devel/p5-Test2-Plugin-NoWarnings

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
