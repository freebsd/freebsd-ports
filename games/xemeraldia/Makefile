# New ports collection makefile for:    xemeraldia
# Version required:     0.3
# Date created:         22 Mar 1995
# Whom:                 asami
#
# $FreeBSD$
#

DISTNAME=       xemeraldia-0.3
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.kuis.kyoto-u.ac.jp/News.Archives/fj.sources/1995/
DISTFILES=	271.gz

MAINTAINER=	ports@FreeBSD.org

USE_IMAKE=      yes
NO_INSTALL_MANPAGES=	yes

do-extract:
	@(cd ${DISTDIR}; \
	  if [ ! -f ${DISTNAME}.tar.gz ]; then \
	    zcat ${DISTFILES} | uudecode; \
	  fi)
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@(cd ${WRKDIR}; tar -xzf \
		${DISTDIR}/${DISTNAME}.tar.gz)

post-install:
	touch ${PREFIX}/lib/X11/.xemeraldia.scores
	${CHMOD} 666 ${PREFIX}/lib/X11/.xemeraldia.scores

pre-clean:
	@${RM} -f ${DISTDIR}/${DISTNAME}.tar.gz

.include <bsd.port.mk>
