# New ports collection makefile for:    xemeraldia
# Version required:     0.3
# Date created:         22 Mar 1995
# Whom:                 asami
#
# $Id: Makefile,v 1.10 1996/11/18 11:25:25 asami Exp $
#

DISTNAME=       xemeraldia-0.3
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.kuis.kyoto-u.ac.jp/News.Archives/fj.sources/1995/
DISTFILES=	271.gz

MAINTAINER=	asami@FreeBSD.ORG

USE_IMAKE=      yes
NO_INSTALL_MANPAGES=	yes

do-extract:
	@(cd ${DISTDIR}; \
	  if [ ! -f ${DISTNAME}.tar.gz ]; then \
	    zcat ${DISTFILES} | uudecode; \
	  fi)
	@rm -rf ${WRKDIR}
	@mkdir -p ${WRKDIR}
	@(cd ${WRKDIR}; tar -xzf \
		${DISTDIR}/${DISTNAME}.tar.gz)

post-install:
	touch ${PREFIX}/lib/X11/.xemeraldia.scores
	chmod 666 ${PREFIX}/lib/X11/.xemeraldia.scores

pre-clean:
	@rm -f ${DISTDIR}/${DISTNAME}.tar.gz

.include <bsd.port.mk>
