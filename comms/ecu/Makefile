# New ports collection makefile for:    ecu
# Version required:     4.07
# Date created:         Feb 18, 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.16 1997/03/26 14:02:55 ache Exp $
#

DISTNAME=       ecu-4.07
CATEGORIES=	comms
MASTER_SITES=   ftp://ftp.kiarchive.ru/unix/comm/
#MASTER_SITES=   ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/Communications/

MAINTAINER=     ache@FreeBSD.ORG

do-configure:
	cd ${WRKSRC}; yes "" | ./Configure

post-install:
	cd ${WRKSRC}/doc; \
	   ${INSTALL_MAN} ecu.man ${PREFIX}/man/cat1/ecu.1; \
	   ${INSTALL_MAN} proc.man ${PREFIX}/man/cat1/proc.1

.include <bsd.port.mk>
