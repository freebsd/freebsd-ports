# New ports collection makefile for:	p5-Parse-RecDescent
# Version required:			1.66
# Date created:				July 9th 1999
# Whom:	      				Jerry Hicks <wghicks@bellsouth.net>
#
# $FreeBSD$
#

DISTNAME=	Parse-RecDescent-1.66
PKGNAME=	p5-Parse-RecDescent-1.66
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Parse

MAINTAINER=	jhix@mindspring.com

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Parse::RecDescent.3 Text::Balanced.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
