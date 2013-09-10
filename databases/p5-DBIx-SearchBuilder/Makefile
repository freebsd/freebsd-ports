# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	DBIx-SearchBuilder
PORTVERSION=	1.63
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Perl extension for easy SQL SELECT Statement generation

BUILD_DEPENDS=	p5-Class-ReturnValue>=0:${PORTSDIR}/devel/p5-Class-ReturnValue \
		p5-Cache-Simple-TimedExpiry>=0:${PORTSDIR}/devel/p5-Cache-Simple-TimedExpiry \
		p5-Want>=0:${PORTSDIR}/devel/p5-Want \
		p5-capitalization>=0:${PORTSDIR}/devel/p5-capitalization \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-DBIx-DBSchema>=0:${PORTSDIR}/databases/p5-DBIx-DBSchema \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Clone>=0:${PORTSDIR}/devel/p5-Clone \
		p5-Encode>=0:${PORTSDIR}/converters/p5-Encode
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

MAN3=	DBIx::SearchBuilder.3 DBIx::SearchBuilder::Handle.3 \
	DBIx::SearchBuilder::Handle::Informix.3 \
	DBIx::SearchBuilder::Handle::ODBC.3 \
	DBIx::SearchBuilder::Handle::Oracle.3 \
	DBIx::SearchBuilder::Handle::Pg.3 \
	DBIx::SearchBuilder::Handle::SQLite.3 \
	DBIx::SearchBuilder::Handle::Sybase.3 \
	DBIx::SearchBuilder::Handle::mysql.3 \
	DBIx::SearchBuilder::Handle::mysqlPP.3 \
	DBIx::SearchBuilder::Record.3 \
	DBIx::SearchBuilder::Record::Cachable.3 \
	DBIx::SearchBuilder::SchemaGenerator.3 \
	DBIx::SearchBuilder::Union.3 \
	DBIx::SearchBuilder::Unique.3

.include <bsd.port.mk>
