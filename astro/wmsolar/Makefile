# New ports collection makefile for:	wmsolar
# Date created:				Tue Jan 15 17:28:49 EST 2002
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	wmsolar
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	astro windowmaker
MASTER_SITES=	http://www.inxsoft.net/wmsolar/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockapp that displays the solar system viewed from top

PLIST_FILES=	bin/wmSolar
WRKSRC=		${WRKDIR}/wmSolar
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's|values.h|float.h|; s|MAXDOUBLE|DBL_MAX|g' \
		${WRKSRC}/wmSolar.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmSolar ${PREFIX}/bin

.include <bsd.port.mk>
