# New ports collection makefile for:    ecu
# Version required:     3.34beta
# Date created:         Feb 18, 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.4 1995/05/11 19:32:28 ache Exp $
#

DISTNAME=       ecu-3.34beta
PKGNAME=	ecu-3.34b
CATEGORIES+=	comms
MASTER_SITES=   ftp://ftp.kiae.su/unix/comm/
EXTRACT_SUFX=   .cpio.Z
WRKSRC=         ${WRKDIR}/ecu

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
