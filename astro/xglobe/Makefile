# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xglobe
PORTVERSION=	0.5
PORTREVISION=	11
CATEGORIES=	astro
MASTER_SITES=	LOCAL/kris

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays a view of the Earth (like xearth) with a rendered photo map

USES=		gmake
USE_QT4=	corelib gui qt3support moc_build

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/xglobe ${STAGEDIR}${PREFIX}/bin/
	@${INSTALL_DATA} ${WRKSRC}/map.bmp ${STAGEDIR}${DATADIR}/
	@${INSTALL_DATA} ${WRKSRC}/xglobe-markers ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
