# New ports collection makefile for:	p5-SQLite-Work
# Date created:				2005-10-27
# Whom:					Chris Larsen <darth@vader.dk>
#
# $FreeBSD$
#

PORTNAME=	SQLite-Work
PORTVERSION=	0.10.02
CATEGORIES=	databases www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/R/RU/RUBYKAT
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Report on and update an SQLite database

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Text/NeatTemplate.pm:${PORTSDIR}/textproc/p5-Text-NeatTemplate \
		p5-Getopt-ArgvFile>=1.10:${PORTSDIR}/devel/p5-Getopt-ArgvFile
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		SQLite::Work::Mail.3 \
		SQLite::Work.3 \
		SQLite::Work::CGI.3

MAN1=		sqlw_mail.1 \
		sqlw_import.1 \
		sqlreport.1

post-patch:
		${CHMOD} u+w ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500807
RUN_DEPENDS+=	p5-CGI.pm>=3.10:${PORTSDIR}/www/p5-CGI.pm
.endif

.include <bsd.port.post.mk>
