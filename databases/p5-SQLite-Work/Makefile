# New ports collection makefile for:	p5-SQLite-Work
# Date created:				2005-10-27
# Whom:					Chris Larsen <darth@vader.dk>
#
# $FreeBSD$
#

PORTNAME=	SQLite-Work
PORTVERSION=	0.03
CATEGORIES=	databases www perl5
MASTER_SITES=	http://www.cpan.org/authors/id/R/RU/RUBYKAT/
PKGNAMEPREFIX=	p5-

MAINTAINER=	darth@vader.dk
COMMENT=	Report on and update an SQLite database

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/Getopt/ArgvFile.pm:${PORTSDIR}/devel/p5-Getopt-ArgvFile
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		SQLite::Work::Mail.3 \
		SQLite::Work.3 \
		SQLite::Work::Template.3 \
		SQLite::Work::CGI.3

MAN1=		sqlw_mail.1 \
		sqlw_import.1 \
		sqlreport.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
