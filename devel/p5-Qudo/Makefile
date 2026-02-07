PORTNAME=	Qudo
PORTVERSION=	0.0214
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KARUPA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for simple and extensible job queue manager
WWW=		https://metacpan.org/release/Qudo

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBI>0:databases/p5-DBI \
		p5-DBIx-Skinny>0:databases/p5-DBIx-Skinny \
		p5-UNIVERSAL-require>0:devel/p5-UNIVERSAL-require \
		p5-YAML>0:textproc/p5-YAML
TEST_DEPENDS=	p5-Test-Output>=0:devel/p5-Test-Output \
		p5-Test-Requires>=0:devel/p5-Test-Requires

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
