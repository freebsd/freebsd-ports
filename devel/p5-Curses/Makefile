# New ports collection makefile for:	p5-Curses
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Curses
PORTVERSION=	1.28
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for terminal screen handling and optimization

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	PANELS MENUS FORMS
CONFIGURE_ENV=	CURSES_CFLAGS="-I${WRKSRC}/usr/include/ncurses"\
		CURSES_LDFLAGS="-L/usr/lib/ -lncurses"

MAN3=		Curses.3

pre-configure:
	@${LN} -sf ${WRKSRC}/hints/c-freebsd.ncurses.h \
		${WRKSRC}/c-config.h
	@${MKDIR} ${WRKSRC}/usr/include/ncurses
.for i in form.h ncurses.h menu.h panel.h
	@${LN} -fs /usr/include/${i} ${WRKSRC}/usr/include/ncurses/${i}
.endfor

.include <bsd.port.mk>
