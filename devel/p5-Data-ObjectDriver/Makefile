# New ports collection makefile for:	p5-Data-ObjectDriver
# Date created:		2007-02-25
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Data-ObjectDriver
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Simple, transparent data interface, with caching

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/Class/Trigger.pm:${PORTSDIR}/devel/p5-Class-Trigger \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${SITE_PERL}/Text/SimpleTable.pm:${PORTSDIR}/textproc/p5-Text-SimpleTable
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

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
