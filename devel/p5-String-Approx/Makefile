# New ports collection makefile for:	p5-String-Approx
# Date created:				April 15th 2000
# Whom:	      				Ilia Chipitsine <ilia@cgu.chel.su>
#
# $FreeBSD$
#

PORTNAME=	String-Approx
PORTVERSION=	3.09
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	String
PKGNAMEPREFIX=	p5-

MAINTAINER=	ilia@cgu.chel.su

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		String::Approx.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
