# New ports collection makefile for:   gifsicle
# Version required:    1.9.1
# Date created:                19 December 1998
# Whom:                        Brad Hendrickse <bradh@iafrica.com>
#
# $Id: Makefile,v 1.3 1999/02/12 02:22:10 flathill Exp $
#

DISTNAME=	gifsicle-1.11.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.lcdf.org/gifsicle/ \
		http://www.freebsd.org/~flathill/distfiles/

MAINTAINER=	bradh@iafrica.com

MAN1=		gifsicle.1

GNU_CONFIGURE=	yes
USE_XLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/gifsicle
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/gifsicle
.endif

.include <bsd.port.mk>
