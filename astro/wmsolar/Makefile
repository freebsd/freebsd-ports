# New ports collection makefile for:	wmsolar
# Date created:				Tue Jan 15 17:28:49 EST 2002
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	wmsolar
PORTVERSION=	1.0
CATEGORIES=	astro windowmaker
MASTER_SITES=	http://www.inxsoft.net/wmsolar/

MAINTAINER=	pat@FreeBSD.org

WRKSRC=		${WRKDIR}/wmSolar
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes

pre-patch:
	@${PERL} -pi.orig -e 's|values.h|float.h|; s|MAXDOUBLE|DBL_MAX|g' \
		${WRKSRC}/wmSolar.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmSolar ${PREFIX}/bin

.include <bsd.port.mk>
