# New ports collection makefile for:   mangband
# Version required:    0.5.4
# Date created:        30 Dec 1998
#
# $FreeBSD$
#

DISTNAME=       mangband-054
PKGNAME=        mangband-0.5.4
CATEGORIES=	games
MASTER_SITES=   http://www.umr.edu/~keldon/MAngband/

MAINTAINER=     ache@freebsd.org

WRKSRC=         ${WRKDIR}/mangband/src
ALL_TARGET=     install

USE_XLIB=       yes

MALIB=          ${PREFIX}/lib/mangband

do-install:
	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 555 ${MALIB}
	cd ${WRKSRC}/../lib; ${CP} -R -p * ${MALIB}; \
	   cd ${MALIB}; \
	   ${TOUCH} file/wizards.txt; \
	   ${CHMOD} 750 *; ${CHOWN} -R root.games *; \
	   ${CHMOD} 755 user;
	cd ${WRKSRC}; \
	   ${INSTALL_PROGRAM} -o root -g games -m 2550 \
		mangband ${PREFIX}/bin; \
	   ${INSTALL_PROGRAM} -o root -g games -m 550 \
		mangconsole ${PREFIX}/bin; \
	   ${INSTALL_PROGRAM} mangclient ${PREFIX}/bin

.include <bsd.port.mk>
