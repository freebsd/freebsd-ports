# New ports collection makefile for:	maatkit
# Date created:				14 December 2007
# Whom:	      				Steven Kreuzer <skreuzer@exit2shell.com>
#
# $FreeBSD$
#

PORTNAME=	maatkit
PORTVERSION=	1972
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	skreuzer@exit2shell.com
COMMENT=	Collection of essential command-line utilities for MySQL

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI

PERL_CONFIGURE=	yes

MAN1=	mk-archiver.1 \
		mk-checksum-filter.1 \
		mk-deadlock-logger.1 \
		mk-duplicate-key-checker.1 \
		mk-find.1 \
		mk-heartbeat.1 \
		mk-parallel-dump.1 \
		mk-parallel-restore.1 \
		mk-profile-compact.1 \
		mk-query-profiler.1 \
		mk-show-grants.1 \
		mk-slave-delay.1 \
		mk-slave-find.1 \
		mk-slave-move.1 \
		mk-slave-prefetch.1 \
		mk-slave-restart.1 \
		mk-table-checksum.1 \
		mk-table-sync.1 \
		mk-visual-explain.1
MAN3=	maatkit.3 maatkitdsn.3

.include <bsd.port.mk>
