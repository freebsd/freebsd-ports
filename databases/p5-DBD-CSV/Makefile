# New ports collection makefile for:    p5-DBD-CSV
# Date created:				20 June 1999
# Whom:	      				dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	p5-DBD-CSV
PORTVERSION=	0.1022
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
DISTNAME=	DBD-CSV-${PORTVERSION}

MAINTAINER=	dirk.meyer@dinoex.sub.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Text/CSV_XS.pm:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/SQL/Statement.pm:${PORTSDIR}/databases/p5-SQL-Statement
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		DBD::File.3 \
		DBD::CSV.3 \
		Bundle::DBD::CSV.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
