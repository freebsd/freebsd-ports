# New ports collection makefile for:    ecu
# Version required:     3.33
# Date created:         Feb 18, 1995
# Whom:                 ache
#
# $Id$
#

DISTNAME=       ecu-3.33
CATEGORIES+=	comms
MASTER_SITES=   ftp://ftp.kiae.su/unix/comm/
EXTRACT_SUFX=   .cpio.Z

MAINTAINER=     ache@FreeBSD.ORG

EXTRACT_CMD=    (zcat | cpio -idm)
EXTRACT_ARGS=   <
HAS_CONFIGURE=  yes
CONFIGURE_SCRIPT= Configure
IS_INTERACTIVE= yes

pre-install:
	cd ${WRKSRC}/doc; \
	   ${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m 644 ecu.man ${PREFIX}/man/cat1/ecu.1; \
	   ${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m 644 proc.man ${PREFIX}/man/cat1/proc.1

.include <bsd.port.mk>
