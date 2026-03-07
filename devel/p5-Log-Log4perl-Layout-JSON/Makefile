PORTNAME=	Log-Log4perl-Layout-JSON
DISTVERSION=	0.61
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSCHOUT
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Layout a log message as a JSON hash, including MDC data
WWW=		https://metacpan.org/dist/Log-Log4perl-Layout-JSON

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BR_DEPENDS=	p5-Class-Tiny>=0:devel/p5-Class-Tiny \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl
BUILD_DEPENDS=	${BR_DEPENDS}
RUN_DEPENDS=	${BR_DEPENDS}
TEST_DEPENDS=	p5-Test-Most>=0:devel/p5-Test-Most \
		p5-Test-Warnings>=0:devel/p5-Test-Warnings

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
