# New ports collection makefile for:	pgtop
# Date created:				30 May 2006
# Whom:					Bartek Rutkowski <r@robakdesign.com>
#
# $FreeBSD$
#

PORTNAME=	pgtop
PORTVERSION=	0.04
CATEGORIES=	databases
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/C/CO/COSIMO

MAINTAINER=	r@robakdesign.com
COMMENT=	Display PostgreSQL performance info like top(1)

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg \
		${SITE_PERL}/${PERL_ARCH}/Bundle/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long

PERL_CONFIGURE=	yes

MAN1=	pgtop.1

.include <bsd.port.mk>
