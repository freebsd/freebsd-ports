# New ports collection makefile for:    ecu
# Version required:     4.04
# Date created:         Feb 18, 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.14 1997/01/28 02:39:45 ache Exp $
#

DISTNAME=       ecu-4.04
CATEGORIES=	comms
MASTER_SITES=   ftp://ftp.relcom.ru/unix/comm/
#MASTER_SITES=   ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/Communications/

MAINTAINER=     ache@FreeBSD.ORG

do-configure:
	cd ${WRKSRC}; yes "" | ./Configure

post-install:
	cd ${WRKSRC}/doc; \
	   ${INSTALL_MAN} ecu.man ${PREFIX}/man/cat1/ecu.1; \
	   ${INSTALL_MAN} proc.man ${PREFIX}/man/cat1/proc.1

.include <bsd.port.mk>
