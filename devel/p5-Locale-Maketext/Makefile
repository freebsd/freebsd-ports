# New ports collection makefile for:	p5-Locale-Maketext
# Date created:			March 13, 2000
# Whom:				Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	Locale-Maketext
PORTVERSION=	0.17
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Locale
PKGNAMEPREFIX=	p5-

MAINTAINER=	frank@exit.com

USE_PERL5=	YES

MAN3=		Locale::Maketext.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
