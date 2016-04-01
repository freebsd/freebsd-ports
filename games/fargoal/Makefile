# Created by: chris_pressey@yahoo.ca
# $FreeBSD$

PORTNAME=	fargoal
PORTVERSION=	20040629
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/squidfighter/${PORTNAME}/20040630
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Remake of classic roguelike game "Sword of Fargoal"

LIB_DEPENDS=	liballeg.so:devel/allegro

WRKSRC=		${WRKDIR}/${PORTNAME}/src

USES=		gmake zip

SUB_FILES=	${PORTNAME}-sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/../sword ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	cd ${WRKSRC}/.. && ${COPYTREE_SHARE} "agreement.txt data gfx sfx" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
