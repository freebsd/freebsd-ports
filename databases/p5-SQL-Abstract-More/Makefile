# Created by: Espen Tagestad <espen@tagestad.no>
# $FreeBSD$

PORTNAME=	SQL-Abstract-More
PORTVERSION=	1.30
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	espen@tagestad.no
COMMENT=	Extension of SQL::Abstract with more constructs and more flexible API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-MRO-Compat>0:devel/p5-MRO-Compat \
		p5-Params-Validate>0:devel/p5-Params-Validate \
		p5-SQL-Abstract>=1.84:databases/p5-SQL-Abstract \
		p5-namespace-clean>=0:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Pod>=0:devel/p5-Test-Pod

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
