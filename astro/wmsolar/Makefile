# Created by: Patrick Li <pat@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmsolar
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	astro windowmaker
MASTER_SITES=	http://www.inxsoft.net/wmsolar/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp that displays the Solar System viewed from the top

PLIST_FILES=	bin/wmSolar
WRKSRC=		${WRKDIR}/wmSolar
USE_XORG=	x11 xext xpm
USES=		gmake

pre-patch:
	@${REINPLACE_CMD} -e 's|values.h|float.h|; s|MAXDOUBLE|DBL_MAX|g' \
		${WRKSRC}/wmSolar.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmSolar ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
