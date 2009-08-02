# New ports collection makefile for:	Class-Gomor
# Date created:				09 Jan 2007
# Whom:					Christopher Boumenot <boumenot@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	CPAN-SQLite
PORTVERSION=	0.197
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/R/RK/RKOBES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Search CPAN using a SQLite database

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite	\
		${SITE_PERL}/File/HomeDir.pm:${PORTSDIR}/devel/p5-File-HomeDir \
		${SITE_PERL}/CPAN/DistnameInfo.pm:${PORTSDIR}/devel/p5-CPAN-DistnameInfo \
		${SITE_PERL}/IO/Zlib.pm:${PORTSDIR}/archivers/p5-IO-Zlib \
		${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN1=	cpandb.1
MAN3=	CPAN::SQLite::Index.3 \
	CPAN::SQLite::META.3 \
	CPAN::SQLite.3 \
	CPAN::SQLite::State.3 \
	CPAN::SQLite::DBI::Search.3 \
	CPAN::SQLite::DBI::Index.3 \
	CPAN::SQLite::DBI.3 \
	CPAN::SQLite::Util.3 \
	CPAN::SQLite::Populate.3 \
	CPAN::SQLite::Info.3 \
	CPAN::SQLite::Search.3

.include <bsd.port.mk>
