PORTNAME=	SQL-Abstract-More
DISTVERSION=	1.44
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Extension of SQL::Abstract with more constructs and more flexible API
WWW=		https://metacpan.org/release/SQL-Abstract-More

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/README

BR_DEPENDS=	p5-MRO-Compat>0:devel/p5-MRO-Compat \
		p5-namespace-clean>=0:devel/p5-namespace-clean \
		p5-Params-Validate>0:devel/p5-Params-Validate \
		p5-SQL-Abstract-Classic>=1.91:databases/p5-SQL-Abstract-Classic \
		p5-SQL-Abstract>=1.84:databases/p5-SQL-Abstract
BUILD_DEPENDS=	${BR_DEPENDS}
RUN_DEPENDS=	${BR_DEPENDS}
TEST_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Pod>=0:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
