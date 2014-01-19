# Created by: alepulver
# $FreeBSD$

PORTNAME=	species
PORTVERSION=	1.2d
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	LOCAL/alepulver
DISTNAME=	redcoder

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Corewars evolver - generates warriors using genetic algorithms

LICENSE=	GPLv1 # (or later)

USE_BZIP2=	yes
USES=		gmake dos2unix
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	VISITOOL
VISITOOL_DESC=	Buil GUI tool for displaying evolution

OPTIONS_SUB=	yes

VISITOOL_USE=	WX=2.4
VISITOOL_ALL_TARGET=	all visitool

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MVISITOOL)
MAKE_ENV+=	WX_CONFIG="${TRUE}"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} koen.* species.ini *.rc ${STAGEDIR}${DATADIR}
.for i in bench evolver_hill wilfiz
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${DATADIR})
.endfor
.if ${PORT_OPTIONS:MVISITOOL}
	${INSTALL_PROGRAM} ${WRKSRC}/visitool ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-visitool
.endif

.include <bsd.port.mk>
