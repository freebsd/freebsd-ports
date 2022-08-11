PORTNAME=	Test-mysqld
PORTVERSION=	1.0013
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for mysqld test runner

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor-Lite>=0:devel/p5-Class-Accessor-Lite \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql \
		p5-DBI>=0:databases/p5-DBI \
		p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive
TEST_DEPENDS=	p5-Test-SharedFork>=0:devel/p5-Test-SharedFork

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
