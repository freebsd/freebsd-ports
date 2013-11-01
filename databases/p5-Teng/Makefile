# $FreeBSD$

PORTNAME=	Teng
PORTVERSION=	0.20
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SATOH
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for simple DBI wrapper/ORMapper

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>=0.05:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
	p5-Class-Load>=0.06:${PORTSDIR}/devel/p5-Class-Load \
	p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
	p5-DBIx-Inspector>=0.06:${PORTSDIR}/databases/p5-DBIx-Inspector \
	p5-DBIx-TransactionManager>=1.06:${PORTSDIR}/databases/p5-DBIx-TransactionManager \
	p5-Data-Page>0:${PORTSDIR}/databases/p5-Data-Page \
	p5-Data-Page-NoTotalEntries>=0.02:${PORTSDIR}/devel/p5-Data-Page-NoTotalEntries \
	p5-SQL-Maker>=0.14:${PORTSDIR}/databases/p5-SQL-Maker
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-DBD-SQLite>=1.12:${PORTSDIR}/databases/p5-DBD-SQLite \
	p5-Test-Mock-Guard>0:${PORTSDIR}/devel/p5-Test-Mock-Guard \
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires \
	p5-Test-SharedFork>=0.06:${PORTSDIR}/devel/p5-Test-SharedFork \
	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple \
	p5-Class-Method-Modifiers>0:${PORTSDIR}/devel/p5-Class-Method-Modifiers

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
