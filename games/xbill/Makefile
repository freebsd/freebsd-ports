# ex:ts=8
# Ports collection makefile for:  xbill
# Date created:			  12 September 1995
# Whom:				  asami
#
# $FreeBSD$
#

PORTNAME=	xbill
PORTVERSION=	2.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
EXTRACT_SUFX=	.tgz

MAINTAINER=	obrien@FreeBSD.org

USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		xbill.1

post-install:
	${CP} ${WRKSRC}/README ${PREFIX}/share/xbill

.include <bsd.port.mk>
