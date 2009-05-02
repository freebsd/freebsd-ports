# New ports collection makefile for:	p5-ORLite-Migrate
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	ORLite-Migrate
PORTVERSION=	0.03
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/A/AD/ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Perl5 extremely light weight SQLite-specific schema migration

BUILD_DEPENDS=	${SITE_PERL}/File/pushd.pm:${PORTSDIR}/devel/p5-File-pushd \
		${SITE_PERL}/IPC/Run3.pm:${PORTSDIR}/devel/p5-IPC-Run3 \
		${SITE_PERL}/ORLite.pm:${PORTSDIR}/databases/p5-ORLite \
		${SITE_PERL}/Probe/Perl.pm:${PORTSDIR}/sysutils/p5-Probe-Perl \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/${PERL_ARCH}/Params/Util.pm:${PORTSDIR}/devel/p5-Params-Util
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		ORLite::Migrate.3

.include <bsd.port.mk>
