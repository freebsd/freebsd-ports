# New ports collection makefile for:    ecu
# Version required:     4.00
# Date created:         Feb 18, 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.12 1996/11/17 03:00:37 obrien Exp $
#

DISTNAME=       ecu-4.00
CATEGORIES=	comms
MASTER_SITES=   ftp://ftp.relcom.ru/unix/comm/
#MASTER_SITES=   ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/Communications/
EXTRACT_SUFX=   .cpio.gz

MAINTAINER=     ache@FreeBSD.ORG

EXTRACT_CMD=    ( gzcat | cpio -idm )
EXTRACT_ARGS=   <

do-configure:
	cd ${WRKSRC}; yes "" | ./Configure

post-install:
	cd ${WRKSRC}/doc; \
	   ${INSTALL_MAN} ecu.man ${PREFIX}/man/cat1/ecu.1; \
	   ${INSTALL_MAN} proc.man ${PREFIX}/man/cat1/proc.1

.include <bsd.port.mk>
