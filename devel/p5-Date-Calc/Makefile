# New ports collection makefile for:	p5-Date-Calc
# Date created:				25 February 2000
# Whom:	      				Brad Hendrickse <bradh@uunet.co.za>
#
# $FreeBSD$
#

PORTNAME=	Date-Calc
PORTVERSION=	4.3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date
PKGNAMEPREFIX=	p5-

MAINTAINER=	bradh@uunet.co.za

USE_PERL5=	YES

MAN3=		Date::Calc.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
