# New ports collection makefile for:    ecu
# Version required:     3.38.06
# Date created:         Feb 18, 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.6 1995/12/28 14:59:07 ache Exp $
#

DISTNAME=       ecu-3.38.06
CATEGORIES+=	comms
MASTER_SITES=   ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/Communications/ \
		ftp://ftp.kiae.su/unix/comm/

MAINTAINER=     ache@FreeBSD.ORG

do-configure:
	cd ${WRKSRC}; yes "" | ./Configure

pre-install:
	cd ${WRKSRC}/doc; \
	   ${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m 644 ecu.man ${PREFIX}/man/cat1/ecu.1; \
	   ${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m 644 proc.man ${PREFIX}/man/cat1/proc.1

.include <bsd.port.mk>
