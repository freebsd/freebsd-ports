# New ports collection makefile for:	databases/p5-DBIx-SearchBuilder
# Date created:				29 May 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-SearchBuilder
PORTVERSION=	1.59
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Perl extension for easy SQL SELECT Statement generation

BUILD_DEPENDS=	${SITE_PERL}/Class/ReturnValue.pm:${PORTSDIR}/devel/p5-Class-ReturnValue \
		${SITE_PERL}/Cache/Simple/TimedExpiry.pm:${PORTSDIR}/devel/p5-Cache-Simple-TimedExpiry \
		${SITE_PERL}/${PERL_ARCH}/Want.pm:${PORTSDIR}/devel/p5-Want \
		${SITE_PERL}/capitalization.pm:${PORTSDIR}/devel/p5-capitalization \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/DBIx/DBSchema.pm:${PORTSDIR}/databases/p5-DBIx-DBSchema \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/${PERL_ARCH}/Clone.pm:${PORTSDIR}/devel/p5-Clone \
		${SITE_PERL}/${PERL_ARCH}/Encode.pm:${PORTSDIR}/converters/p5-Encode
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.7.3+

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
