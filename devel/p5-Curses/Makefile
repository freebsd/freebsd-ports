# New ports collection makefile for:	p5-Curses
# Version required:			1.01
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.6 1997/05/24 13:17:01 jfitz Exp $
#

DISTNAME=	Curses-1.01
PKGNAME=	p5-Curses-1.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Curses

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		Curses.3
MANPREFIX=	${PREFIX}/lib/perl5

pre-configure:
		@ ln -s ${WRKSRC}/hints/c-freebsd.ncurses.h ${WRKSRC}/c-config.h

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
