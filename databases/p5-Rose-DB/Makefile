# New ports collection makefile for:	databases/p5-Rose-DB
# Date created:				09 June 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Rose-DB
PORTVERSION=	0.733
PORTEPOCH=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Rose
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	A DBI wrapper and abstraction layer

BUILD_DEPENDS=	p5-Rose-DateTime>=0.532:${PORTSDIR}/devel/p5-Rose-DateTime \
		${SITE_PERL}/SQL/ReservedWords.pm:${PORTSDIR}/databases/p5-SQL-ReservedWords \
		${SITE_PERL}/${PERL_ARCH}/Bit/Vector/Overload.pm:${PORTSDIR}/math/p5-Bit-Vector \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/DateTime/Format/MySQL.pm:${PORTSDIR}/devel/p5-DateTime-Format-MySQL \
		${SITE_PERL}/DateTime/Format/Pg.pm:${PORTSDIR}/devel/p5-DateTime-Format-Pg \
		${SITE_PERL}/Clone/PP.pm:${PORTSDIR}/devel/p5-Clone-PP \
    		${SITE_PERL}/Time/Clock.pm:${PORTSDIR}/devel/p5-Time-Clock
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Rose::DB.3 \
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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8 or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
