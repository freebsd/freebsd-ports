# Created by: <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Dancer2-Session-DBIC
PORTVERSION=	0.120
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBIx::Class based session engine for Dancer2

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBICx-Sugar>=0:databases/p5-DBICx-Sugar \
		p5-DBIx-Class>=0:databases/p5-DBIx-Class \
		p5-Dancer2>=0.140000:www/p5-Dancer2 \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Try-Tiny>=0.01:lang/p5-Try-Tiny \
		p5-namespace-clean>=0:devel/p5-namespace-clean
TEST_DEPENDS=	p5-DBICx-TestDatabase>=0:databases/p5-DBICx-TestDatabase \
		p5-DBIx-Class-TimeStamp>=0:databases/p5-DBIx-Class-TimeStamp \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
