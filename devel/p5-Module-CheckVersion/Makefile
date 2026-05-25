PORTNAME=	Module-CheckVersion
PORTVERSION=	0.091
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PERLANCAR
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Check module (e.g. latest version) with CPAN (or equivalent repo)
WWW=		https://metacpan.org/release/Module-CheckVersion

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Slurper>=0:devel/p5-File-Slurper \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Parse-CPAN-Packages>=0:devel/p5-Parse-CPAN-Packages

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
