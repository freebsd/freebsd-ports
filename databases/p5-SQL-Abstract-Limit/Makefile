PORTNAME=	SQL-Abstract-Limit
PORTVERSION=	0.143
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	SQL Portability layer for LIMIT emulation

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-SQL-Abstract>=1.2:databases/p5-SQL-Abstract \
		p5-DBI>=0:databases/p5-DBI
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		dos2unix perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
