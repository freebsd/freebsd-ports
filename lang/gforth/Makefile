# New ports collection makefile for:	gforth
# Date created:				12 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	gforth
PORTVERSION=	0.5.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gforth

MAINTAINER=	clefevre@citeweb.net

Y2K=		http://www.gnu.org/software/year2000.html

CFLAGS=		#none
STRIP=		#none

GNU_CONFIGURE=	yes

MAN1=		gforth.1

post-install:
	@install-info ${PREFIX}/info/gforth.info ${PREFIX}/info/dir
.if !exists(${PREFIX}/share/emacs/site-lisp/gforth.el)
	@${INSTALL_DATA} ${WRKSRC}/gforth.el ${PREFIX}/share/emacs/site-lisp
.endif

.include <bsd.port.mk>
