# ex:ts=8
# New ports collection makefile for:    lrzsz
# Version required:     0.12.x
# Date created:         29 Sept 1996
# Whom:                 David O'Brien <obrien@cs.ucdavis.edu>
#
# $Id$

DISTNAME=	lrzsz-0.12.11
CATEGORIES+=	comms
MASTER_SITES=	ftp://ftp.ihg.uni-duisburg.de/uwe/

MAINTAINER=	obrien@cs.ucdavis.edu

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
	${COMPRESS_MAN} \
		${PREFIX}/man/man1/lrz.1  \
		${PREFIX}/man/man1/lsz.1

.include <bsd.port.mk>
