# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	polypuzzle
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	games tcl tk
MASTER_SITES=	ftp://ibiblio.org/pub/Linux/games/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tessellation puzzle game

USES= 		tk:84,run
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

OPTIONS_DEFINE= DOCS
DOC_FILES=	About Bugs Changelog Install Instructions Links Math Readme \
		Thanks Todo
DATA_FILES=	menus pieces.3x20 pieces.783 pieces.bonus pieces.colours \
		pieces.flower pieces.large pieces.medium pieces.monster \
		pieces.round pieces.small pieces.square pieces.star \
		pieces.triangle

pre-install:
	 @${REINPLACE_CMD} -e "s:%%DATADIR%%:${DATADIR}:g" ${WRKSRC}/polypuzzle

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/polypuzzle ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
.for f in ${DATA_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
