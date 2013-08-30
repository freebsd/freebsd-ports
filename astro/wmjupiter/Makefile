# Created by: pat
# $FreeBSD$

PORTNAME=	wmjupiter
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	astro windowmaker
MASTER_SITES=	http://www.inxsoft.net/wmjupiter/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp that displays information on Jupiter

PLIST_FILES=	bin/wmJupiter
WRKSRC=		${WRKDIR}/wmJupiter
USE_XORG=	x11 xext xpm
USES=		gmake

pre-patch:
	@${REINPLACE_CMD} -e 's|values.h|float.h|; s|MAXDOUBLE|DBL_MAX|g' \
		${WRKSRC}/wmJupiter.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmJupiter ${PREFIX}/bin

.include <bsd.port.mk>
