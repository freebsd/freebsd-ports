# New ports collection makefile for:	neverball
# Date created:				26 October 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	neverball
PORTVERSION=	1.4.0
CATEGORIES=	games
MASTER_SITES=	http://icculus.org/neverball/

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	Tilt the floor to guide a ball through an obstacle course

BUILD_DEPENDS=	${FREETYPE_CONFIG}:${PORTSDIR}/print/freetype2

FREETYPE_CONFIG?=	${LOCALBASE}/bin/freetype-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_SDL=	image mixer ttf

DOCS=		CHANGES COPYING README
DIRS=		back bgm map-back map-mym map-paxed map-putt map-rlk mtrl obj \
		png shot-mym shot-putt shot-rlk snd ttf

post-patch:
	@${REINPLACE_CMD} -e 's|./data|${DATADIR}/data|g' \
		${WRKSRC}/share/config.h
	@${REINPLACE_CMD} -e 's|%%FREETYPE_CONFIG%%|${FREETYPE_CONFIG}|g' \
		${WRKSRC}/Makefile

do-install:
.for ii in ${DIRS}
	@${MKDIR} ${DATADIR}/data/${ii}
	@${INSTALL_DATA} ${WRKSRC}/data/${ii}/* ${DATADIR}/data/${ii}/
.endfor
	@${INSTALL_DATA} ${WRKSRC}/data/*.txt ${DATADIR}/data/
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/neverputt ${PREFIX}/bin/

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
