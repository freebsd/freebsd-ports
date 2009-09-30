# New ports collection makefile for:	p5-ORLite-Migrate
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	ORLite-Migrate
PORTVERSION=	1.05
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/A/AD/ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Perl5 extremely light weight SQLite-specific schema migration

BUILD_DEPENDS=	p5-File-pushd>=1.00:${PORTSDIR}/devel/p5-File-pushd \
		p5-IPC-Run3>=0.042:${PORTSDIR}/devel/p5-IPC-Run3 \
		p5-ORLite>=1.28:${PORTSDIR}/databases/p5-ORLite \
		p5-Probe-Perl>=0.01:${PORTSDIR}/sysutils/p5-Probe-Perl \
		p5-DBI>=1.58:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-SQLite>=1.21:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Params-Util>0.37:${PORTSDIR}/devel/p5-Params-Util
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		ORLite::Migrate.3

.include <bsd.port.mk>
