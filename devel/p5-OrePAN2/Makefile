PORTNAME=	OrePAN2
PORTVERSION=	0.53
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:OALDERS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for yet another DarkPAN manager
WWW=		https://metacpan.org/release/OrePAN2

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Archive-Extract>=0.72:archivers/p5-Archive-Extract \
		p5-IO-File-AtomicChange>=0:devel/p5-IO-File-AtomicChange \
		p5-IO-Socket-SSL>=1.42:security/p5-IO-Socket-SSL \
		p5-libwww>=0:www/p5-libwww \
		p5-List-Compare>=0:misc/p5-List-Compare \
		p5-MetaCPAN-Client>=2.000000:devel/p5-MetaCPAN-Client \
		p5-Moo>=1.007000:devel/p5-Moo \
		p5-MooX-Options>=0:devel/p5-MooX-Options \
		p5-MooX-StrictConstructor>=0:devel/p5-MooX-StrictConstructor \
		p5-namespace-clean>=0:devel/p5-namespace-clean \
		p5-Parse-CPAN-Packages-Fast>=0.09:devel/p5-Parse-CPAN-Packages-Fast \
		p5-Parse-LocalDistribution>=0.14:devel/p5-Parse-LocalDistribution \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-Type-Tiny>=2.000000:devel/p5-Type-Tiny \
		p5-Types-Path-Tiny>=0:devel/p5-Types-Path-Tiny \
		p5-Types-Self>=0:devel/p5-Types-Self \
		p5-Types-URI>=0:devel/p5-Types-URI
TEST_DEPENDS=	p5-File-pushd>=0:devel/p5-File-pushd \
		p5-File-Touch>=0:devel/p5-File-Touch \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-Test-Needs>=0:devel/p5-Test-Needs \
		p5-Test-RequiresInternet>=0:devel/p5-Test-RequiresInternet

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
