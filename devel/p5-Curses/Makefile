# New ports collection makefile for:	p5-Curses
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Curses
PORTVERSION=	1.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Curses
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Perl5 module for terminal screen handling and optimization

PERL_CONFIGURE=	yes

MAN3=		Curses.3

pre-configure:
		@${LN} -s ${WRKSRC}/hints/c-freebsd.ncurses.h \
			${WRKSRC}/c-config.h

.include <bsd.port.mk>
