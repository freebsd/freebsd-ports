# New ports collection makefile for:	SN
# Date created:			23 July 2000
# Whom:				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	SN
PORTVERSION=	4.5.1
CATEGORIES=	devel
MASTER_SITES=	ftp://sources.redhat.com/pub/sourcenav/releases/
DISTNAME=	SN451

MAINTAINER=	dburr@FreeBSD.ORG

PREFIX=		${LOCALBASE}/SN
USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/SN451

post-install:
		@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
