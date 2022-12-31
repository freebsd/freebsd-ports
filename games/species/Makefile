PORTNAME=	species
PORTVERSION=	1.2d
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	LOCAL/alepulver
DISTNAME=	redcoder

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Corewars evolver - generates warriors using genetic algorithms
WWW=		http://redcoder.sourceforge.net/?p=species

LICENSE=	GPLv1+ # though COPYING files mention LGPL21 and GPLv2 instead

USES=		gmake dos2unix tar:bzip2

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	VISITOOL
OPTIONS_SUB=	yes

VISITOOL_DESC=	Build GUI tool for displaying evolution

VISITOOL_USE=	WX=3.0
VISITOOL_MAKE_ENV=	WX_CONFIG="${TRUE}"
VISITOOL_ALL_TARGET=	all visitool

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} koen.* species.ini *.rc ${STAGEDIR}${DATADIR}
.for i in bench evolver_hill wilfiz
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${STAGEDIR}${DATADIR})
.endfor

do-install-VISITOOL-on:
	${INSTALL_PROGRAM} ${WRKSRC}/visitool ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-visitool

.include <bsd.port.mk>
