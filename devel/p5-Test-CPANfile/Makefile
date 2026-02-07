PORTNAME=	Test-CPANfile
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	root@dc365.ru
COMMENT=	See if cpanfile lists every used modules
WWW=		https://metacpan.org/dist/Test-CPANfile

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-ExtUtils-MakeMaker-CPANfile>=0.06:devel/p5-ExtUtils-MakeMaker-CPANfile
RUN_DEPENDS=	p5-CPAN-Common-Index>=0:devel/p5-CPAN-Common-Index \
		p5-Module-CPANfile>=1.1004:devel/p5-Module-CPANfile \
		p5-Perl-PrereqScanner-NotQuiteLite>=0.9913:devel/p5-Perl-PrereqScanner-NotQuiteLite \
		p5-Test-UseAllModules>=0.17:devel/p5-Test-UseAllModules

USES=		perl5
USE_PERL5=	configure test

NO_ARCH=	yes

.include <bsd.port.mk>
