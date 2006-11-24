# New ports collection makefile for:    ecu
# Date created:         Feb 18, 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	ecu
PORTVERSION=	4.30
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/Communications/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extended Call Utility

MAN1=		ecu.1

do-configure:
	cd ${WRKSRC}; yes "" | ./Configure

pre-patch:
	@${REINPLACE_CMD} -e "s|#include  *<malloc.h>||g" \
	    ${WRKSRC}/ecu.h ${WRKSRC}/ecunumrev.c ${WRKSRC}/ptyfork.c \
	    ${WRKSRC}/qmake.c ${WRKSRC}/unsupported/tts/tts.c

post-install:
	cd ${WRKSRC}; \
	   ${INSTALL_MAN} ecu.1 ${PREFIX}/man/man1/ecu.1; \
	   cd ${WRKSRC}/doc; \
	   ${MKDIR} ${PREFIX}/share/doc/ecu; \
	   ${INSTALL_MAN} ecu.man ${PREFIX}/share/doc/ecu/ecu.txt; \
	   ${INSTALL_MAN} proc.man ${PREFIX}/share/doc/ecu/proc.txt

.include <bsd.port.mk>
