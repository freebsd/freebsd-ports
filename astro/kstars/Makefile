# New ports collection makefile for:	kstars
# Date created:				Thu Sep 13 16:00:55 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	kstars
PORTVERSION=	0.9
CATEGORIES=	astro kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}.kde3

MAINTAINER=	pat@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=	3
CONFIGURE_ENV=	KDEDIR="${LOCALBASE}"

.include <bsd.port.mk>
