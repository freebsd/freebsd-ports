# New ports collection makefile for:    p5-Term-Query
# Version required:			2.0
# Date created:				21 May 1998
# Whom:	      				Garrett Wollman <wollman@lcs.mit.edu>
#
# $FreeBSD$
#

DISTNAME=	Term-Query-2.0
PKGNAME=	p5-Term-Query-2.0
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Term

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Array/PrintCols.pm:${PORTSDIR}/misc/p5-Array-PrintCols

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Term::Query.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
