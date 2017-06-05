# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class-Schema-Loader
PORTVERSION=	0.07043
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	des@FreeBSD.org
COMMENT=	Dynamic definition of a DBIx::Class::Schema

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Carp-Clan>=0:devel/p5-Carp-Clan \
		p5-Class-Accessor-Grouped>=0.10002:devel/p5-Class-Accessor-Grouped \
		p5-Class-C3-Componentised>=1.000800:devel/p5-Class-C3-Componentised \
		p5-Class-Inspector>=1.27:devel/p5-Class-Inspector \
		p5-Class-Load>=0:devel/p5-Class-Load \
		p5-Class-Unload>=0:devel/p5-Class-Unload \
		p5-DBIx-Class>=0.08127:databases/p5-DBIx-Class \
		p5-Data-Dump>1.06:devel/p5-Data-Dump \
		p5-Hash-Merge>=0:textproc/p5-Hash-Merge \
		p5-Lingua-EN-Inflect-Number>=1.1:textproc/p5-Lingua-EN-Inflect-Number \
		p5-Lingua-EN-Inflect-Phrase>=0.02:textproc/p5-Lingua-EN-Inflect-Phrase \
		p5-MRO-Compat>=0.09:devel/p5-MRO-Compat \
		p5-Scope-Guard>=0:devel/p5-Scope-Guard \
		p5-String-CamelCase>=0.02:textproc/p5-String-CamelCase \
		p5-String-ToIdentifier-EN>=0.05:textproc/p5-String-ToIdentifier-EN \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-namespace-clean>=0.20:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Config-General>=0:devel/p5-Config-General \
		p5-DBD-SQLite>=1.29:databases/p5-DBD-SQLite \
		p5-DBIx-Class-IntrospectableM2M>=0:databases/p5-DBIx-Class-IntrospectableM2M \
		p5-Moose>=1.12:devel/p5-Moose \
		p5-MooseX-MarkAsMethods>=0.13:devel/p5-MooseX-MarkAsMethods \
		p5-MooseX-NonMoose>=0.16:devel/p5-MooseX-NonMoose \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Pod>=1.14:devel/p5-Test-Pod \
		p5-Test-Warn>=0.21:devel/p5-Test-Warn

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

MYSQL_USE=		MYSQL=yes
PGSQL_USES=		pgsql
SQLITE_USES=		sqlite

.include <bsd.port.mk>
