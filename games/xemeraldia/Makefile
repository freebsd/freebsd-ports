# New ports collection makefile for:    xemeraldia
# Version required:     0.2
# Date created:         22 Mar 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.2 1995/03/24 05:47:58 asami Exp $
#

DISTNAME=       xemeraldia-0.2
DISTFILES=	250.gz
MASTER_SITES=	ftp://ftp.kuis.kyoto-u.ac.jp/News.Archives/fj.sources/1995/
USE_IMAKE=      yes
NO_INSTALL_MANPAGES=	yes
EXTRACT_COOKIE?=	${.CURDIR}/work/.extract_done

extract: fetch ${EXTRACT_COOKIE}

${EXTRACT_COOKIE}:
	@${MAKE} ${.MAKEFLAGS} checksum pre-extract
	@echo "===>  Extracting for ${DISTNAME}"
	@(cd ${DISTDIR}; zcat ${DISTFILES} | uudecode)
	@rm -rf ${WRKDIR}
	@mkdir -p ${WRKDIR}
	@(cd ${WRKDIR}; tar -xzf \
		${DISTDIR}/${DISTNAME}.tar.gz)
	@${TOUCH} ${TOUCH_FLAGS} ${EXTRACT_COOKIE}


pre-install:
	touch ${PREFIX}/lib/X11/.xemeraldia.scores
	chmod 666 ${PREFIX}/lib/X11/.xemeraldia.scores

.include <bsd.port.mk>
