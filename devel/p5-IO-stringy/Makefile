# New ports collection makefile for:	p5-IO-stringy
# Version required:			1.105
# Date created:				April 27 1998
# Whom:	      				Eivind Eklund <eivind@FreeBSD.ORG>
#
# $Id$
#

DISTNAME=	IO-stringy-1.105
PKGNAME=	p5-IO-stringy-1.105
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO

MAINTAINER=	eivind@FreeBSD.ORG

USE_PERL5=	YES

MAN3=          IO::Wrap.3 IO::ScalarArray.3 IO::Scalar.3
MANPREFIX=     ${PREFIX}/lib/perl5

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
