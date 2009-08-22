# New ports collection makefile for:	c-a-i-r
# Date created:				18 Oct 2008
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	c-a-i-r
PORTVERSION=	2.17
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/CAIR%20v${PORTVERSION}
DISTNAME=	CAIR_MT_v2.17

MAINTAINER=	buganini@gmail.com
COMMENT=	Content Aware Image Resizer is an implementation of seam carving

USE_ZIP=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/cair

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/cair ${PREFIX}/bin

.include <bsd.port.mk>
