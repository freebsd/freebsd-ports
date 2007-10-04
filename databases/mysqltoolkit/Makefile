# New ports collection makefile for:	mysqltoolkit
# Date created:				19 July 2007
# Whom:	      				Steven Kreuzer <skreuzer@exit2shell.com>
#
# $FreeBSD$
#

PORTNAME=	mysqltoolkit
PORTVERSION=	946
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	skreuzer@exit2shell.com
COMMENT=	Collection of essential command-line utilities for MySQL

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \

PERL_CONFIGURE=	yes

MAN1=	mysql-archiver.1 \
	mysql-checksum-filter.1 \
	mysql-deadlock-logger.1 \
	mysql-duplicate-key-checker.1 \
	mysql-find.1 \
	mysql-heartbeat.1 \
	mysql-parallel-dump.1 \
	mysql-profile-compact.1 \
	mysql-query-profiler.1 \
	mysql-show-grants.1 \
	mysql-slave-delay.1 \
	mysql-slave-restart.1 \
	mysql-table-checksum.1 \
	mysql-table-sync.1 \
	mysql-visual-explain.1
MAN3=	mysqltoolkit.3

.include <bsd.port.mk>
