PORTNAME=	Log-Log4perl-Layout-JSON
PORTVERSION=	0.59
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Layout a log message as a JSON hash, including MDC data

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Tiny>=0:devel/p5-Class-Tiny \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl
TEST_DEPENDS=	p5-Test-Most>=0:devel/p5-Test-Most \
		p5-Test-Warnings>=0:devel/p5-Test-Warnings

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
