# New ports collection makefile for:   mangband
# http://www.umr.edu/~keldon/MAngband/
# Version required:    0.5.4
# Date created:        30 Dec 1998
#
# $Id: Makefile,v 1.7 1998/08/05 09:30:52 asami Exp $
#

DISTNAME=       mangband-054
PKGNAME=        mangband-0.5.4
CATEGORIES=	games
MASTER_SITES=   http://www.umr.edu/~keldon/MAngband/

WRKSRC=         ${WRKDIR}/mangband/src
ALL_TARGET=     install

USE_XLIB=       yes

MAINTAINER=     ache@freebsd.org

MALIB=          ${PREFIX}/lib/mangband

do-install:
	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 555 ${MALIB}
	cd ${WRKSRC}/../lib; cp -R -p * ${MALIB}; \
	   cd ${MALIB}; \
	   touch file/wizards.txt; \
	   chmod 750 *; chown -R games.games *; \
	   chmod 755 user;
	cd ${WRKSRC}; \
	   ${INSTALL_PROGRAM} -o games -g games -m 4550 \
		mangband ${PREFIX}/bin; \
	   ${INSTALL_PROGRAM} -o games -g games -m 550 \
		mangconsole ${PREFIX}/bin; \
	   ${INSTALL_PROGRAM} mangclient ${PREFIX}/bin

.include <bsd.port.mk>
