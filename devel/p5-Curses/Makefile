# New ports collection makefile for:	p5-Curses
# Version required:			1.0
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1996/10/24 09:58:18 jfitz Exp $
#

DISTNAME=	Curses-1.0
PKGNAME=	p5-Curses-1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Curses

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

MAN3=		Curses.3
MANPREFIX=	${PREFIX}/lib/perl5

pre-configure:
		@ ln -s ${WRKSRC}/hints/c-freebsd.ncurses.h ${WRKSRC}/c-config.h

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
