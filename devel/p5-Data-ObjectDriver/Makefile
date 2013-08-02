# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Data-ObjectDriver
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple, transparent data interface, with caching

RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-Trigger>=0:${PORTSDIR}/devel/p5-Class-Trigger \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Text-SimpleTable>=0:${PORTSDIR}/textproc/p5-Text-SimpleTable
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Data::ObjectDriver.3 Data::ObjectDriver::BaseObject.3 \
		Data::ObjectDriver::Driver::BaseCache.3 \
		Data::ObjectDriver::Driver::Cache::Apache.3 \
		Data::ObjectDriver::Driver::Cache::Memcached.3 \
		Data::ObjectDriver::Driver::DBD.3 \
		Data::ObjectDriver::Driver::DBD::SQLite.3 \
		Data::ObjectDriver::Driver::DBD::Oracle.3 \
		Data::ObjectDriver::Driver::MultiPartition.3 \
		Data::ObjectDriver::Driver::Multiplexer.3 \
		Data::ObjectDriver::Driver::Partition.3 \
		Data::ObjectDriver::Driver::SimplePartition.3 \
		Data::ObjectDriver::Errors.3 Data::ObjectDriver::Profiler.3 \
		Data::ObjectDriver::ResultSet.3 \
		Data::ObjectDriver::SQL.3 \
		Data::ObjectDriver::SQL::Oracle.3

.include <bsd.port.mk>
