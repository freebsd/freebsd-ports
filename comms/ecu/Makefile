# New ports collection makefile for:    ecu
# Date created:         Feb 18, 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	ecu
PORTVERSION=    4.30
CATEGORIES=	comms
MASTER_SITES=  ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/Communications/

MAINTAINER=	ache@FreeBSD.org

do-configure:
	cd ${WRKSRC}; yes "" | ./Configure

post-install:
	cd ${WRKSRC}/doc; \
	   ${INSTALL_MAN} ecu.man ${PREFIX}/man/cat1/ecu.1; \
	   ${INSTALL_MAN} proc.man ${PREFIX}/man/cat1/proc.1

.include <bsd.port.mk>
