# New ports collection makefile for:   gifsicle
# Version required:    1.16.1
# Date created:                19 December 1998
# Whom:                        Brad Hendrickse <bradh@iafrica.com>
#
# $FreeBSD$
#

DISTNAME=	gifsicle-1.16.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.lcdf.org/gifsicle/

MAINTAINER=	bradh@uunet.co.za

MAN1=		gifsicle.1

GNU_CONFIGURE=	yes
USE_XLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/gifsicle
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/gifsicle
.endif

.include <bsd.port.mk>
