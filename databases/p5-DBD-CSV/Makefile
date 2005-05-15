# New ports collection makefile for:    p5-DBD-CSV
# Date created:				20 June 1999
# Whom:	      				dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	DBD-CSV
PORTVERSION=	0.22
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	DBI driver for CSV files

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Text/CSV_XS.pm:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		${SITE_PERL}/SQL/Statement.pm:${PORTSDIR}/databases/p5-SQL-Statement \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		DBD::CSV.3 Bundle::DBD::CSV.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
