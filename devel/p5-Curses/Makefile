# New ports collection makefile for:	p5-Curses
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Curses
PORTVERSION=	1.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Curses
PKGNAMEPREFIX=	p5-

MAINTAINER=	jfitz@FreeBSD.org

USE_PERL5=	YES

MAN3=		Curses.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-configure:
		@ ${LN} -s ${WRKSRC}/hints/c-freebsd.ncurses.h ${WRKSRC}/c-config.h

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
