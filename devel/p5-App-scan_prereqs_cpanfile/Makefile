PORTNAME=	App-scan_prereqs_cpanfile
PORTVERSION=	1.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for scanning prerequisite modules to generate cpanfile

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Module-CPANfile>=0.9020:devel/p5-Module-CPANfile \
		p5-Perl-PrereqScanner-Lite>=0.21:devel/p5-Perl-PrereqScanner-Lite

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
