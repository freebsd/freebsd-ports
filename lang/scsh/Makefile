# New ports collection makefile for:    scsh
# Version required:     0.5.1
# Date created:         Jul, 15, 1997
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $Id: Makefile,v 1.4 1997/07/15 15:00:30 cracauer Exp $
#

DISTNAME=	scsh-0.5.1
CATEGORIES=	shells lang
MASTER_SITES=	ftp://ftp-swiss.ai.mit.edu/pub/su/scsh/

MAINTAINER= 	cracauer@cons.org

GNU_CONFIGURE=	yes

ALL_TARGET=	enough
MAN1=		scsh.1
STRIP=

BROKEN_ELF=	build

post-install:
	@strip ${PREFIX}/bin/scsh
	(cd ${WRKSRC} ; \
	 ${INSTALL_DATA} README RELEASE NEWS COPYING ${PREFIX}/lib/scsh/doc)
	${RM} -f ${PREFIX}/share/doc/scsh
	ln -fs ${PREFIX}/lib/scsh/doc ${PREFIX}/share/doc/scsh

.include <bsd.port.mk>
