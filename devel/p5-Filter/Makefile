# New ports collection makefile for:    p5-Filter
# Version required:			1.12
# Date created:				June 26th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.ORG>
#
#   $Id$
#

DISTNAME=	Filter-1.12
PKGNAME=	p5-Filter-1.12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Filter

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5
MAN3=		Filter::Util::Call.3 Filter::Util::Exec.3 Filter::cpp.3 \
		Filter::decrypt.3 Filter::exec.3 Filter::sh.3 Filter::tee.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
