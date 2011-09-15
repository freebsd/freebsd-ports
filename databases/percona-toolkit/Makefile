# New ports collection makefile for:	percona-toolkit
# Date created:				15 September 2011
# Whom:	      				Florian Smeets <flo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	percona-toolkit
PORTVERSION=	1.0.1
CATEGORIES=	databases
MASTER_SITES=	http://www.percona.com/downloads/percona-toolkit/

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Collection of essential command-line utilities for MySQL

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

PERL_CONFIGURE=	yes

MAN1=	pt-mysql-summary.1 \
	pt-kill.1 \
	pt-online-schema-change.1 \
	pt-trend.1 \
	pt-table-sync.1 \
	pt-upgrade.1 \
	pt-fifo-split.1 \
	pt-slave-find.1 \
	pt-log-player.1 \
	pt-find.1 \
	pt-archiver.1 \
	pt-deadlock-logger.1 \
	pt-mext.1 \
	pt-slave-restart.1 \
	pt-summary.1 \
	pt-fk-error-logger.1 \
	pt-table-checksum.1 \
	pt-query-digest.1 \
	pt-show-grants.1 \
	percona-toolkit.1 \
	pt-pmp.1 \
	pt-heartbeat.1 \
	pt-slave-delay.1 \
	pt-sift.1 \
	pt-diskstats.1 \
	pt-visual-explain.1 \
	pt-query-advisor.1 \
	pt-variable-advisor.1 \
	pt-collect.1 \
	pt-index-usage.1 \
	pt-tcp-model.1 \
	pt-duplicate-key-checker.1 \
	pt-config-diff.1 \
	pt-stalk.1

.include <bsd.port.mk>
