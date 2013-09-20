# $FreeBSD$

PORTNAME=	Data-Model
PORTVERSION=	0.00008
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for model interface which had more data sources unified

RUN_DEPENDS=	\
	p5-Module-Build-Tiny>=0.020:${PORTSDIR}/devel/p5-Module-Build-Tiny \
	p5-Class-Trigger>0:${PORTSDIR}/devel/p5-Class-Trigger \
	p5-DBD-SQLite>0:${PORTSDIR}/databases/p5-DBD-SQLite \
	p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
	p5-Params-Validate>0:${PORTSDIR}/devel/p5-Params-Validate
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Sub-Uplevel>0:${PORTSDIR}/devel/p5-Sub-Uplevel \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Test-Class>=0:${PORTSDIR}/devel/p5-Test-Class \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

USES=	perl5
USE_PERL5=	modbuild

MAN3=	Data::Model.3 \
	Data::Model::Accessor.3 \
	Data::Model::Driver.3 \
	Data::Model::Driver::Cache.3 \
	Data::Model::Driver::Cache::HASH.3 \
	Data::Model::Driver::Cache::Memcached.3 \
	Data::Model::Driver::DBI.3 \
	Data::Model::Driver::DBI::DBD.3 \
	Data::Model::Driver::DBI::DBD::SQLite.3 \
	Data::Model::Driver::DBI::DBD::mysql.3 \
	Data::Model::Driver::DBI::MasterSlave.3 \
	Data::Model::Driver::Hash.3 \
	Data::Model::Driver::Logic.3 \
	Data::Model::Driver::Memcached.3 \
	Data::Model::Driver::Memory.3 \
	Data::Model::Driver::Queue::Q4M.3 \
	Data::Model::Iterator.3 \
	Data::Model::Mixin.3 \
	Data::Model::Mixin::FindOrCreate.3 \
	Data::Model::Mixin::Queue::Q4M.3 \
	Data::Model::Row.3 \
	Data::Model::SQL.3 \
	Data::Model::Schema.3 \
	Data::Model::Schema::Inflate.3 \
	Data::Model::Schema::Inflate::UUID.3 \
	Data::Model::Schema::Properties.3 \
	Data::Model::Schema::SQL.3 \
	Data::Model::Transaction.3 \
	Data::Model::Tutorial::JA.3
NO_STAGE=	yes
.include <bsd.port.mk>
