# New ports collection makefile for:    yaps
# Date created:         Di  29 Sep 1998 15:51:27 CEST
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	yaps
PORTVERSION=	0.96
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/serialcomm/machines

MAINTAINER=	se@FreeBSD.org
COMMENT=	Yet Another Pager Software: send messages to pager (SMS, TAP, ...)

USE_GMAKE=	true

MAN1=		yaps.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/yaps.rc ${PREFIX}/etc/yaps.rc.sample
	${INSTALL_MAN} ${WRKSRC}/yaps.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/yaps
	${INSTALL_DATA} ${WRKSRC}/yaps.doc ${PREFIX}/share/doc/yaps
	${INSTALL_DATA} ${WRKSRC}/yaps.html ${PREFIX}/share/doc/yaps
.endif

.include <bsd.port.mk>
