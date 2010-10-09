# New ports collection makefile for:	Data::Model
# Date created:		18 Jan 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Model
PORTVERSION=	0.00007
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for model interface which had more data sources unified

RUN_DEPENDS=	\
	p5-Class-Trigger>0:${PORTSDIR}/devel/p5-Class-Trigger \
	p5-DBD-SQLite>0:${PORTSDIR}/databases/p5-DBD-SQLite \
	p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
	p5-Params-Validate>0:${PORTSDIR}/devel/p5-Params-Validate
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Data::Model.3 \
	Data::Model::Driver::Cache::HASH.3 \
	Data::Model::Driver::Cache::Memcached.3 \
	Data::Model::Driver::DBI.3 \
	Data::Model::Driver::DBI::MasterSlave.3 \
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
	Data::Model::Transaction.3 \
	Data::Model::Tutorial::JA.3 \
	Data::README.3

.include <bsd.port.mk>
