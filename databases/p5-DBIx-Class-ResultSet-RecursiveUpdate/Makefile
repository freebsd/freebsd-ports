# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class-ResultSet-RecursiveUpdate
PORTVERSION=	0.41
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Like update_or_create - but recursive

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Carp-Clan>=6.04:devel/p5-Carp-Clan \
		p5-DBD-SQLite>=1.21:databases/p5-DBD-SQLite \
		p5-DBIx-Class>=0.08103:databases/p5-DBIx-Class \
		p5-DBIx-Class-IntrospectableM2M>=0:databases/p5-DBIx-Class-IntrospectableM2M \
		p5-Data-Dumper-Concise>=2.020:devel/p5-Data-Dumper-Concise \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-List-MoreUtils>=0.22:lang/p5-List-MoreUtils \
		p5-SQL-Translator>=0.11016:databases/p5-SQL-Translator \
		p5-Try-Tiny>=0.30:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-NonMoose>=0:devel/p5-MooseX-NonMoose \
		p5-Test-Exception>=0.43:devel/p5-Test-Exception \
		p5-Test-Trap>=0.2.2:devel/p5-Test-Trap \
		p5-Test-Warn>=0.20:devel/p5-Test-Warn \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
