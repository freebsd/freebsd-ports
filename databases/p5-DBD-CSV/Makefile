# New ports collection makefile for:    p5-DBD-CSV
# Date created:				20 June 1999
# Whom:	      				dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	DBD-CSV
PORTVERSION=	0.2002
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Text/CSV_XS.pm:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/SQL/Statement.pm:${PORTSDIR}/databases/p5-SQL-Statement
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		DBD::File.3 \
		DBD::CSV.3 \
		Bundle::DBD::CSV.3

.include <bsd.port.mk>
