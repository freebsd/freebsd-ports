# New ports collection makefile for:	p5-Time-Period
# Date created:			October 30th, 2000
# Whom:	      			Nicholas Esborn <nick@netdot.net>
#
# $FreeBSD$
#

PORTNAME=	Time-Period
PORTVERSION=	1.20
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Time
PKGNAMEPREFIX=	p5-
DISTNAME=	Period-${PORTVERSION}

MAINTAINER=	nick@netdot.net

USE_PERL5=	YES

MAN3=		Time::Period.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
