# New ports collection makefile for:    p5-DBD-CSV
# Date created:				20 June 1999
# Whom:	      				dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	DBD-CSV
PORTVERSION=	0.29
PORTEPOCH=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBI driver for CSV files

RUN_DEPENDS=	p5-DBI>=1.61.1:${PORTSDIR}/databases/p5-DBI \
		p5-SQL-Statement>=1.25:${PORTSDIR}/databases/p5-SQL-Statement \
		p5-Text-CSV_XS>=0.71:${PORTSDIR}/textproc/p5-Text-CSV_XS
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		DBD::CSV.3 Bundle::DBD::CSV.3

.include <bsd.port.mk>
