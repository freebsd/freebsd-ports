# New ports collection makefile for:	databases/p5-Rose-DB
# Date created:				09 June 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Rose-DB
PORTVERSION=	0.763
PORTEPOCH=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/J/JS/JSIRACUSA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A DBI wrapper and abstraction layer

BUILD_DEPENDS=	p5-Rose-DateTime>=0.532:${PORTSDIR}/devel/p5-Rose-DateTime \
		${SITE_PERL}/SQL/ReservedWords.pm:${PORTSDIR}/databases/p5-SQL-ReservedWords \
		${SITE_PERL}/${PERL_ARCH}/Bit/Vector/Overload.pm:${PORTSDIR}/math/p5-Bit-Vector \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/DateTime/Format/MySQL.pm:${PORTSDIR}/devel/p5-DateTime-Format-MySQL \
		p5-DateTime-Format-Pg>=0.11:${PORTSDIR}/devel/p5-DateTime-Format-Pg \
		${SITE_PERL}/Clone/PP.pm:${PORTSDIR}/devel/p5-Clone-PP \
    		${SITE_PERL}/Time/Clock.pm:${PORTSDIR}/devel/p5-Time-Clock \
		${SITE_PERL}/${PERL_ARCH}/YAML/Syck.pm:${PORTSDIR}/textproc/p5-YAML-Syck
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Rose::DB.3 \
	Rose::DB::Cache.3 \
	Rose::DB::Cache::Entry.3 \
	Rose::DB::Constants.3 \
	Rose::DB::Generic.3 \
	Rose::DB::Informix.3 \
	Rose::DB::MySQL.3 \
	Rose::DB::Oracle.3 \
	Rose::DB::Pg.3 \
	Rose::DB::Registry.3 \
	Rose::DB::Registry::Entry.3 \
	Rose::DB::SQLite.3 \
	Rose::DB::Tutorial.3

.include <bsd.port.mk>
