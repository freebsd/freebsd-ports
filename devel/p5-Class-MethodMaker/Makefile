# New ports collection makefile for:   p5-Class-MethodMaker
# Date created:                                2000-07-09
# Whom:                                        Trevor Johnson <trevor@jpj.net>
#
# $FreeBSD$
#

PORTNAME=              Class-MethodMaker
PORTVERSION=           0.96
CATEGORIES=            devel perl5
MASTER_SITES=          ${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=    Class
PKGNAMEPREFIX=         p5-

MAINTAINER=    trevor@jpj.net

USE_PERL5=     yes

MAN3=          Class::MethodMaker.3
MANPREFIX=     ${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
