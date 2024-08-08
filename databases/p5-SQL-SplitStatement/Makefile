PORTNAME=	SQL-SplitStatement
PORTVERSION=	1.00023
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Split any SQL code into atomic statements
WWW=		https://metacpan.org/dist/SQL-SplitStatement

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common
TEST_DEPENDS=	p5-Test-Differences>=0.680:devel/p5-Test-Differences \
		p5-Test-Exception>=0.27:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
