# New ports collection makefile for:    p5-Term-Size
# Date created:				6 December 2000
# Whom:	      				Brad Jones <brad@kazrak.com>
#
# $FreeBSD$
#

PORTNAME=	Term-Size
PORTVERSION=	0.2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Term
PKGNAMEPREFIX=	p5-

MAINTAINER=	brad@kazrak.com

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Term::Size.3

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL \
		CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>
