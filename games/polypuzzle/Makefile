# New ports collection makefile for:	polypuzzle
# Date created:		30 June 2004
# Whom:			janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	polypuzzle
PORTVERSION=	1.5.1
CATEGORIES=	games tcl84 tk84
MASTER_SITES=	ftp://ibiblio.org/pub/Linux/games/
EXTRACT_SUFX=	.tgz

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Tessellation puzzle game

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_REINPLACE=	yes
NO_BUILD=	yes

DOC_FILES=	About Bugs Changelog Copyright Install Math Readme Thanks Todo
DATA_FILES=	menus pieces.3x20 pieces.783 pieces.bonus pieces.colours \
		pieces.flower pieces.large pieces.medium pieces.monster \
		pieces.small pieces.square pieces.star pieces.triangle

pre-install:
	 @${REINPLACE_CMD} -e "s:%%DATADIR%%:${DATADIR}:g" ${WRKSRC}/polypuzzle
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/polypuzzle ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.for f in ${DATA_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
