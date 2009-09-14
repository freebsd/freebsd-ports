# New ports collection makefile for:	maatkit
# Date created:				14 December 2007
# Whom:	      				Steven Kreuzer <skreuzer@exit2shell.com>
#
# $FreeBSD$
#

PORTNAME=	maatkit
PORTVERSION=	4623
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Collection of essential command-line utilities for MySQL

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

PERL_CONFIGURE=	yes

MAN1=	maatkit.1p \
		mk-archiver.1p \
		mk-audit.1p \
		mk-checksum-filter.1p \
		mk-deadlock-logger.1p \
		mk-duplicate-key-checker.1p \
		mk-fifo-split.1p \
		mk-find.1p \
		mk-heartbeat.1p \
		mk-log-player.1p \
		mk-parallel-dump.1p \
		mk-parallel-restore.1p \
		mk-profile-compact.1p \
		mk-query-digest.1p \
		mk-query-profiler.1p \
		mk-show-grants.1p \
		mk-slave-delay.1p \
		mk-slave-find.1p \
		mk-slave-move.1p \
		mk-slave-prefetch.1p \
		mk-slave-restart.1p \
		mk-table-checksum.1p \
		mk-table-sync.1p \
		mk-upgrade.1p \
		mk-visual-explain.1p

.include <bsd.port.mk>
