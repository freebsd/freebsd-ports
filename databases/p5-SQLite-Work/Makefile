# Created by: Chris Larsen <darth@vader.dk>
# $FreeBSD$

PORTNAME=	SQLite-Work
PORTVERSION=	0.10.02
CATEGORIES=	databases www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RUBYKAT
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Report on and update an SQLite database

RUN_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Text-NeatTemplate>=0:${PORTSDIR}/textproc/p5-Text-NeatTemplate \
		p5-Getopt-ArgvFile>=1.10:${PORTSDIR}/devel/p5-Getopt-ArgvFile
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		SQLite::Work::Mail.3 \
		SQLite::Work.3 \
		SQLite::Work::CGI.3

MAN1=		sqlw_mail.1 \
		sqlw_import.1 \
		sqlreport.1

post-patch:
		${CHMOD} u+w ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
