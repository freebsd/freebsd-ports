PORTNAME=	Archive-Libarchive
PORTVERSION=	0.09
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Modern Perl bindings to libarchive
WWW=		https://metacpan.org/dist/Archive-Libarchive

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-FFI-C-Stat>=0:devel/p5-FFI-C-Stat \
		p5-FFI-CheckLib>=0.30:devel/p5-FFI-CheckLib \
		p5-FFI-Platypus>=1.38:devel/p5-FFI-Platypus \
		p5-FFI-Platypus-Type-Enum>=0.05:devel/p5-FFI-Platypus-Type-Enum \
		p5-FFI-Platypus-Type-PtrObject>=0:devel/p5-FFI-Platypus-Type-PtrObject \
		p5-Ref-Util>=0:devel/p5-Ref-Util
TEST_DEPENDS=	p5-FFI-C>=0:devel/p5-FFI-C \
		p5-File-chdir>=0:devel/p5-File-chdir \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Sub-Identify>=0:devel/p5-Sub-Identify \
		p5-Term-Table>=0:devel/p5-Term-Table \
		p5-Test-Archive-Libarchive>=0:devel/p5-Test-Archive-Libarchive \
		p5-Test-Script>=1.09:devel/p5-Test-Script \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple \
		p5-Test2-Tools-MemoryCycle>=0:devel/p5-Test2-Tools-MemoryCycle

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
