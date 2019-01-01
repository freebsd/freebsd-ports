# Created by: ports@c0decafe.net
# $FreeBSD$

PORTNAME=	App-perlbrew
PORTVERSION=	0.85
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GUGOD
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl Environment manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CPAN-Perl-Releases>=3.66:devel/p5-CPAN-Perl-Releases \
		p5-Capture-Tiny>=0.36:devel/p5-Capture-Tiny \
		p5-Devel-PatchPerl>=1.52:devel/p5-Devel-PatchPerl \
		p5-local-lib>=2.000014:devel/p5-local-lib
TEST_DEPENDS=	p5-File-Which>=1.21:sysutils/p5-File-Which \
		p5-IO-All>=0.51:devel/p5-IO-All \
		p5-Path-Class>=0.33:devel/p5-Path-Class \
		p5-Test-Exception>=0.32:devel/p5-Test-Exception \
		p5-Test-NoWarnings>=1.04:devel/p5-Test-NoWarnings \
		p5-Test-Output>=1.030:devel/p5-Test-Output \
		p5-Test-Spec>=0.47:devel/p5-Test-Spec \
		p5-Test-TempDir-Tiny>=0.016:devel/p5-Test-TempDir-Tiny

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
