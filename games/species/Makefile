# Created by: alepulver
# $FreeBSD$

PORTNAME=	species
PORTVERSION=	1.2d
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alepulver
DISTNAME=	redcoder

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Corewars evolver - generates warriors using genetic algorithms

USE_DOS2UNIX=	yes
USE_BZIP2=	yes
USES=		gmake
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	VISITOOL
VISITOOL_DESC=	Buil GUI tool for displaying evolution

OPTIONS_SUB=	yes

VISITOOL_USE=	WX=2.4
VISITOOL_ALL_TARGET=	all visitool

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} koen.* species.ini *.rc ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${CP} -r bench evolver_hill wilfiz ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MVISITOOL}
	${INSTALL_PROGRAM} ${WRKSRC}/visitool ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-visitool
.endif

.include <bsd.port.mk>
