# New ports collection makefile for:    yaps
# Version required:     0.96
# Date created:         Di  29 Sep 1998 15:51:27 CEST
# Whom:                 se
#
# $Id: Makefile,v 1.2 1998/10/10 20:18:31 jseger Exp $
#

DISTNAME=       yaps-0.96
CATEGORIES=	comms
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/unix/comm/ \
		ftp://ftp.cdrom.com/pub/linux/sunsite/apps/serialcomm/machines/

MAINTAINER=     se@FreeBSD.ORG

USE_GMAKE=	true

MAN1=		yaps.1

post-install:
	${MKDIR} ${PREFIX}/share/doc/yaps; \
	${INSTALL_DATA} ${WRKSRC}/yaps.rc ${PREFIX}/etc/yaps.rc.sample; \
	${INSTALL_DATA} ${WRKSRC}/yaps.doc ${PREFIX}/share/doc/yaps; \
	${INSTALL_DATA} ${WRKSRC}/yaps.html ${PREFIX}/share/doc/yaps; \
	${INSTALL_MAN} ${WRKSRC}/yaps.1 ${PREFIX}/man/man1;

.include <bsd.port.mk>
