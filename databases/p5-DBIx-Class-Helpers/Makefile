# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class-Helpers
PORTVERSION=	2.018002
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Simplify the common case stuff for DBIx::Class

RUN_DEPENDS=	p5-DBIx-Class>=0.08123:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-DBIx-Class-Candy>=0:${PORTSDIR}/databases/p5-DBIx-Class-Candy \
		p5-String-CamelCase>=0:${PORTSDIR}/textproc/p5-String-CamelCase \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean \
		p5-Carp-Clan>=0:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-Sub-Exporter-Progressive>=0:${PORTSDIR}/devel/p5-Sub-Exporter-Progressive \
		p5-Lingua-EN-Inflect>=0:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	configure

MAN3=	DBIx::Class::Helpers.3 \
	DBIx::Class::Helper::IgnoreWantarray.3 \
	DBIx::Class::Helper::JoinTable.3 \
	DBIx::Class::Helper::Random.3 \
	DBIx::Class::Helper::ResultSet.3 \
	DBIx::Class::Helper::ResultSet::AutoRemoveColumns.3 \
	DBIx::Class::Helper::ResultSet::CorrelateRelationship.3 \
	DBIx::Class::Helper::ResultSet::IgnoreWantarray.3 \
	DBIx::Class::Helper::ResultSet::Me.3 \
	DBIx::Class::Helper::ResultSet::NoColumns.3 \
	DBIx::Class::Helper::ResultSet::Random.3 \
	DBIx::Class::Helper::ResultSet::RemoveColumns.3 \
	DBIx::Class::Helper::ResultSet::ResultClassDWIM.3 \
	DBIx::Class::Helper::ResultSet::SearchOr.3 \
	DBIx::Class::Helper::ResultSet::SetOperations.3 \
	DBIx::Class::Helper::ResultSet::Shortcut.3 \
	DBIx::Class::Helper::ResultSet::Shortcut::AddColumns.3 \
	DBIx::Class::Helper::ResultSet::Shortcut::Columns.3 \
	DBIx::Class::Helper::ResultSet::Shortcut::Distinct.3 \
	DBIx::Class::Helper::ResultSet::Shortcut::GroupBy.3 \
	DBIx::Class::Helper::ResultSet::Shortcut::HRI.3 \
	DBIx::Class::Helper::ResultSet::Shortcut::HasRows.3 \
	DBIx::Class::Helper::ResultSet::Shortcut::Limit.3 \
	DBIx::Class::Helper::ResultSet::Shortcut::OrderBy.3 \
	DBIx::Class::Helper::ResultSet::Shortcut::OrderByMagic.3 \
	DBIx::Class::Helper::ResultSet::Shortcut::Prefetch.3 \
	DBIx::Class::Helper::ResultSet::Shortcut::Rows.3 \
	DBIx::Class::Helper::ResultSet::Union.3 \
	DBIx::Class::Helper::ResultSet::VirtualView.3 \
	DBIx::Class::Helper::Row::JoinTable.3 \
	DBIx::Class::Helper::Row::NumifyGet.3 \
	DBIx::Class::Helper::Row::OnColumnChange.3 \
	DBIx::Class::Helper::Row::ProxyResultSetMethod.3 \
	DBIx::Class::Helper::Row::ProxyResultSetUpdate.3 \
	DBIx::Class::Helper::Row::RelationshipDWIM.3 \
	DBIx::Class::Helper::Row::SelfResultSet.3 \
	DBIx::Class::Helper::Row::StorageValues.3 \
	DBIx::Class::Helper::Row::SubClass.3 \
	DBIx::Class::Helper::Row::ToJSON.3 \
	DBIx::Class::Helper::Schema::GenerateSource.3 \
	DBIx::Class::Helper::Schema::LintContents.3 \
	DBIx::Class::Helper::Schema::QuoteNames.3 \
	DBIx::Class::Helper::SubClass.3 \
	DBIx::Class::Helper::VirtualView.3 \
	DBIx::Class::Helpers::Util.3

NO_STAGE=	yes
.include <bsd.port.mk>
