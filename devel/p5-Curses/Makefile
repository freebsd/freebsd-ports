# New ports collection makefile for:	p5-Curses
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Curses
PORTVERSION=	1.08b
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Curses
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Perl5 module for terminal screen handling and optimization

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-1.08

MAN3=		Curses.3

pre-configure:
		@${LN} -s ${WRKSRC}/hints/c-freebsd.ncurses.h \
			${WRKSRC}/c-config.h

.include <bsd.port.mk>
