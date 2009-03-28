# New ports collection makefile for:	maatkit
# Date created:				14 December 2007
# Whom:	      				Steven Kreuzer <skreuzer@exit2shell.com>
#
# $FreeBSD$
#

PORTNAME=	maatkit
PORTVERSION=	3119
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Collection of essential command-line utilities for MySQL

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

PERL_CONFIGURE=	yes

MAN1=	mk-archiver.1 \
		mk-audit.1 \
		mk-checksum-filter.1 \
		mk-deadlock-logger.1 \
		mk-duplicate-key-checker.1 \
		mk-find.1 \
		mk-heartbeat.1 \
		mk-parallel-dump.1 \
		mk-parallel-restore.1 \
		mk-profile-compact.1 \
		mk-query-digest.1 \
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
