# New ports collection makefile for:	p5-Date-Manip
# Version required:			5.10
# Date created:				April 28th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1997/05/24 13:17:01 jfitz Exp $
#

DISTNAME=	DateManip-5.10
PKGNAME=	p5-Date-Manip-5.10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		Date::Manip.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
