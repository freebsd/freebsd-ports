# New ports collection makefile for:    xemeraldia
# Version required:     0.3
# Date created:         22 Mar 1995
# Whom:                 asami
#
# $Id: Makefile,v 1.7 1995/04/01 12:45:17 jkh Exp $
#

DISTNAME=       xemeraldia-0.3
CATEGORIES+=	games
MASTER_SITES=	ftp://ftp.kuis.kyoto-u.ac.jp/News.Archives/fj.sources/1995/
DISTFILES=	271.gz

MAINTAINER=	asami@FreeBSD.ORG

USE_IMAKE=      yes
NO_INSTALL_MANPAGES=	yes

EXTRACT_COOKIE?=	${.CURDIR}/work/.extract_done

extract: fetch ${EXTRACT_COOKIE}

${EXTRACT_COOKIE}:
	@${MAKE} ${.MAKEFLAGS} checksum pre-extract
	@echo "===>  Extracting for ${DISTNAME}"
	@(cd ${DISTDIR}; \
	  if [ ! -f ${DISTNAME}.tar.gz ]; then \
	    zcat ${DISTFILES} | uudecode; \
	  fi)
	@rm -rf ${WRKDIR}
	@mkdir -p ${WRKDIR}
	@(cd ${WRKDIR}; tar -xzf \
		${DISTDIR}/${DISTNAME}.tar.gz)
	@${TOUCH} ${TOUCH_FLAGS} ${EXTRACT_COOKIE}


pre-install:
	touch ${PREFIX}/lib/X11/.xemeraldia.scores
	chmod 666 ${PREFIX}/lib/X11/.xemeraldia.scores

.include <bsd.port.mk>
