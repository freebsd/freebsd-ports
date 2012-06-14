# New ports collection makefile for:	SPOPS
# Date created:		17 Dec 2001
# Whom:			Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SPOPS
PORTVERSION=	0.87
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CWINTERS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple Perl Object Persistence with Security

BUILD_DEPENDS=	p5-Class-ISA>=0:${PORTSDIR}/devel/p5-Class-ISA \
		p5-Class-Date>=0:${PORTSDIR}/devel/p5-Class-Date \
		p5-Carp-Assert>=0:${PORTSDIR}/devel/p5-Carp-Assert \
		p5-Class-Fields>=0:${PORTSDIR}/devel/p5-Class-Fields \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Factory>=0:${PORTSDIR}/devel/p5-Class-Factory \
		p5-Devel-StackTrace>=0:${PORTSDIR}/devel/p5-Devel-StackTrace \
		p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Time-Piece>=0:${PORTSDIR}/devel/p5-Time-Piece
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	SPOPS.3 \
	SPOPS::ClassFactory.3 \
	SPOPS::ClassFactory::DBI.3 \
	SPOPS::ClassFactory::DefaultBehavior.3 \
	SPOPS::ClassFactory::LDAP.3 \
	SPOPS::DBI.3 \
	SPOPS::DBI::InterBase.3 \
	SPOPS::DBI::MySQL.3 \
	SPOPS::DBI::Oracle.3 \
	SPOPS::DBI::Pg.3 \
	SPOPS::DBI::SQLite.3 \
	SPOPS::DBI::Sybase.3 \
	SPOPS::DBI::TypeInfo.3 \
	SPOPS::Error.3 \
	SPOPS::Exception.3 \
	SPOPS::Exception::DBI.3 \
	SPOPS::Exception::LDAP.3 \
	SPOPS::Exception::Security.3 \
	SPOPS::Export.3 \
	SPOPS::Export::DBI::Data.3 \
	SPOPS::Export::Object.3 \
	SPOPS::Export::Perl.3 \
	SPOPS::Export::SQL.3 \
	SPOPS::Export::XML.3 \
	SPOPS::GDBM.3 \
	SPOPS::HashFile.3 \
	SPOPS::Import.3 \
	SPOPS::Import::DBI::Data.3 \
	SPOPS::Import::DBI::Delete.3 \
	SPOPS::Import::DBI::GenericOperation.3 \
	SPOPS::Import::DBI::Table.3 \
	SPOPS::Import::DBI::TableTransform.3 \
	SPOPS::Import::DBI::TableTransform::InterBase.3 \
	SPOPS::Import::DBI::TableTransform::MySQL.3 \
	SPOPS::Import::DBI::TableTransform::Oracle.3 \
	SPOPS::Import::DBI::TableTransform::Pg.3 \
	SPOPS::Import::DBI::TableTransform::SQLite.3 \
	SPOPS::Import::DBI::TableTransform::Sybase.3 \
	SPOPS::Import::DBI::Update.3 \
	SPOPS::Import::Object.3 \
	SPOPS::Initialize.3 \
	SPOPS::Iterator.3 \
	SPOPS::Iterator::DBI.3 \
	SPOPS::Iterator::LDAP.3 \
	SPOPS::Iterator::WrapList.3 \
	SPOPS::Key::DBI::HandleField.3 \
	SPOPS::Key::DBI::Identity.3 \
	SPOPS::Key::DBI::Pool.3 \
	SPOPS::Key::DBI::Sequence.3 \
	SPOPS::Key::Random.3 \
	SPOPS::Key::UUID.3 \
	SPOPS::LDAP.3 \
	SPOPS::LDAP::MultiDatasource.3 \
	SPOPS::Loopback.3 \
	SPOPS::Manual.3 \
	SPOPS::Manual::CodeGeneration.3 \
	SPOPS::Manual::Configuration.3 \
	SPOPS::Manual::Cookbook.3 \
	SPOPS::Manual::Datasource.3 \
	SPOPS::Manual::Exceptions.3 \
	SPOPS::Manual::ImportExport.3 \
	SPOPS::Manual::Intro.3 \
	SPOPS::Manual::Object.3 \
	SPOPS::Manual::ObjectRules.3 \
	SPOPS::Manual::Relationships.3 \
	SPOPS::Manual::Security.3 \
	SPOPS::Manual::Serialization.3 \
	SPOPS::SQLInterface.3 \
	SPOPS::Secure.3 \
	SPOPS::Secure::DBI.3 \
	SPOPS::Secure::Hierarchy.3 \
	SPOPS::Secure::Loopback.3 \
	SPOPS::Secure::Util.3 \
	SPOPS::Tie.3 \
	SPOPS::Tie::StrictField.3 \
	SPOPS::Tool::CreateOnly.3 \
	SPOPS::Tool::DBI::Datasource.3 \
	SPOPS::Tool::DBI::DiscoverField.3 \
	SPOPS::Tool::DBI::FindDefaults.3 \
	SPOPS::Tool::DBI::MaintainLinkedList.3 \
	SPOPS::Tool::DateConvert.3 \
	SPOPS::Tool::LDAP::Datasource.3 \
	SPOPS::Tool::ReadOnly.3 \
	SPOPS::Tool::UTFConvert.3 \
	SPOPS::Utility.3

post-install:
.ifndef(NOPORTDOCS)
		@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
		@${MKDIR} ${EXAMPLESDIR}/My
		@${INSTALL_SCRIPT} ${WRKSRC}/eg/*.pl ${EXAMPLESDIR}
		@${INSTALL_DATA} ${WRKSRC}/eg/*.sql ${WRKSRC}/eg/README \
			${EXAMPLESDIR}
		@${INSTALL_DATA} ${WRKSRC}/eg/My/*.pm ${EXAMPLESDIR}/My
.endif

.include <bsd.port.mk>
