# New ports collection makefile for:   gifsicle
# Version required:    1.8
# Date created:                5 December 1998
# Whom:                        Brad Hendrickse <bradh@iafrica.com>
#
# $Id:$
#

DISTNAME=      gifsicle-1.8
CATEGORIES=    graphics
MASTER_SITES=  http://www.lcdf.org/gifsicle/

MAINTAINER=    bradh@iafrica.com

MAN1=          gifsicle.1

GNU_CONFIGURE= yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/gifsicle
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/gifsicle
.endif

.include <bsd.port.mk>
