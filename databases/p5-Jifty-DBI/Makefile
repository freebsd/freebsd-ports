# New ports collection makefile for:	databases/p5-Jifty-DBI
# Date created:				27 Dec 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Jifty-DBI
PORTVERSION=	0.57
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Jifty::DBI - An object-relational persistence framework

BUILD_DEPENDS=	\
		p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
		p5-Exporter-Lite>0:${PORTSDIR}/devel/p5-Exporter-Lite \
		p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-Lingua-EN-Inflect>0:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect \
		p5-Class-ReturnValue>=0.40:${PORTSDIR}/devel/p5-Class-ReturnValue \
		p5-Class-Data-Inheritable>0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Trigger>=0.12:${PORTSDIR}/devel/p5-Class-Trigger \
		p5-Clone>0:${PORTSDIR}/devel/p5-Clone \
		p5-Cache-Simple-TimedExpiry>=0.21:${PORTSDIR}/devel/p5-Cache-Simple-TimedExpiry \
		p5-Data-Page>0:${PORTSDIR}/databases/p5-Data-Page \
		p5-DateTime>=0.34:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-ISO8601>0:${PORTSDIR}/devel/p5-DateTime-Format-ISO8601 \
		p5-DateTime-Format-Strptime>0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-DBIx-DBSchema>=0.34:${PORTSDIR}/databases/p5-DBIx-DBSchema \
		p5-Test-Simple>=0.52:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Time-Duration>=0:${PORTSDIR}/devel/p5-Time-Duration \
		p5-Time-Duration-Parse>=0:${PORTSDIR}/devel/p5-Time-Duration-Parse \
		p5-DBD-SQLite>0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Hash-Merge>0:${PORTSDIR}/textproc/p5-Hash-Merge \
		p5-Object-Declare>=0.22:${PORTSDIR}/devel/p5-Object-Declare \
		p5-Scalar-Defer>=0.10:${PORTSDIR}/devel/p5-Scalar-Defer \
		p5-version>0:${PORTSDIR}/devel/p5-version \
		p5-YAML-Syck>0:${PORTSDIR}/textproc/p5-YAML-Syck \
		p5-Cache-Memcached>0:${PORTSDIR}/databases/p5-Cache-Memcached
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.3+

MAN3=	Jifty::DBI.3 \
	Jifty::DBI::Collection.3 \
	Jifty::DBI::Collection::Union.3 \
	Jifty::DBI::Collection::Unique.3 \
	Jifty::DBI::Column.3 \
	Jifty::DBI::Filter.3 \
	Jifty::DBI::Filter::Boolean.3 \
	Jifty::DBI::Filter::Date.3 \
	Jifty::DBI::Filter::DateTime.3 \
	Jifty::DBI::Filter::Duration.3 \
	Jifty::DBI::Filter::SaltHash.3 \
	Jifty::DBI::Filter::Storable.3 \
	Jifty::DBI::Filter::Time.3 \
	Jifty::DBI::Filter::Truncate.3 \
	Jifty::DBI::Filter::URI.3 \
	Jifty::DBI::Filter::YAML.3 \
	Jifty::DBI::Filter::base64.3 \
	Jifty::DBI::Filter::utf8.3 \
	Jifty::DBI::Handle.3 \
	Jifty::DBI::Handle::Informix.3 \
	Jifty::DBI::Handle::ODBC.3 \
	Jifty::DBI::Handle::Oracle.3 \
	Jifty::DBI::Handle::Pg.3 \
	Jifty::DBI::Handle::SQLite.3 \
	Jifty::DBI::Handle::Sybase.3 \
	Jifty::DBI::Handle::mysql.3 \
	Jifty::DBI::Handle::mysqlPP.3 \
	Jifty::DBI::HasFilters.3 \
	Jifty::DBI::Record.3 \
	Jifty::DBI::Record::Cachable.3 \
	Jifty::DBI::Record::Memcached.3 \
	Jifty::DBI::Record::Plugin.3 \
	Jifty::DBI::Schema.3 \
	Jifty::DBI::SchemaGenerator.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500807
BUILD_DEPENDS+=	p5-Encode>=2.10:${PORTSDIR}/converters/p5-Encode
RUN_DEPENDS+=	p5-Encode>=2.10:${PORTSDIR}/converters/p5-Encode
.endif

.include <bsd.port.post.mk>
