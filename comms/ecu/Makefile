# New ports collection makefile for:    ecu
# Version required:     3.44
# Date created:         Feb 18, 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.9 1996/07/30 17:20:57 ache Exp $
#

DISTNAME=       ecu-3.44
CATEGORIES+=	comms
MASTER_SITES=   ftp://ftp.relcom.ru/unix/comm/
#MASTER_SITES=   ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/Communications/

MAINTAINER=     ache@FreeBSD.ORG

do-configure:
	cd ${WRKSRC}; yes "" | ./Configure

post-install:
	cd ${WRKSRC}/doc; \
	   ${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m 644 ecu.man ${PREFIX}/man/cat1/ecu.1; \
	   ${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m 644 proc.man ${PREFIX}/man/cat1/proc.1

.include <bsd.port.mk>
