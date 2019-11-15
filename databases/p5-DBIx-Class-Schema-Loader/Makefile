# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class-Schema-Loader
PORTVERSION=	0.07049
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	des@FreeBSD.org
COMMENT=	Dynamic definition of a DBIx::Class::Schema

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Carp-Clan>=0:devel/p5-Carp-Clan \
		p5-Class-Accessor-Grouped>=0.10008:devel/p5-Class-Accessor-Grouped \
		p5-Class-C3-Componentised>=1.0008:devel/p5-Class-C3-Componentised \
		p5-Class-Inspector>=1.27:devel/p5-Class-Inspector \
		p5-Class-Unload>=0.07:devel/p5-Class-Unload \
		p5-curry>=1.000000:devel/p5-curry \
		p5-Data-Dump>1.06:devel/p5-Data-Dump \
		p5-DBIx-Class>=0.08127:databases/p5-DBIx-Class \
		p5-Hash-Merge>=0.12:textproc/p5-Hash-Merge \
		p5-Lingua-EN-Inflect-Number>=1.1:textproc/p5-Lingua-EN-Inflect-Number \
		p5-Lingua-EN-Tagger>=0.23:textproc/p5-Lingua-EN-Tagger \
		p5-Lingua-EN-Inflect-Phrase>=0.15:textproc/p5-Lingua-EN-Inflect-Phrase \
		p5-MRO-Compat>=0.09:devel/p5-MRO-Compat \
		p5-namespace-clean>=0.23:devel/p5-namespace-clean \
		p5-Scope-Guard>=0:devel/p5-Scope-Guard \
		p5-String-ToIdentifier-EN>=0.05:textproc/p5-String-ToIdentifier-EN \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-DBD-SQLite>=1.29:databases/p5-DBD-SQLite \
		p5-Test-Exception>=0.31:devel/p5-Test-Exception \
		p5-Test-Warn>=0.21:devel/p5-Test-Warn \
		p5-Test-Deep>=1.107:devel/p5-Test-Deep \
		p5-Test-Differences>=0.60:devel/p5-Test-Differences

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

MYSQL_USES=		mysql
PGSQL_USES=		pgsql
SQLITE_USES=		sqlite

.include <bsd.port.mk>
