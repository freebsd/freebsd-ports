# New ports collection makefile for:	neverputt
# Date created:				26 October 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	neverputt
PORTVERSION=	0.18.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://icculus.org/neverball/

MAINTAINER=	mezz7@cox.net
COMMENT=	3D miniature golf for 1-4 players

BUILD_DEPENDS=	${FREETYPE_CONFIG}:${PORTSDIR}/print/freetype2

FREETYPE_CONFIG?=	${LOCALBASE}/bin/freetype-config

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_SDL=	image mixer ttf sdl

DIRS=		bgm map mtrl png snd sol ttf

post-patch:
	@${REINPLACE_CMD} -e 's|./data|${DATADIR}/data|g' \
		${WRKSRC}/config.h
	@${REINPLACE_CMD} -e 's|%%FREETYPE_CONFIG%%|${FREETYPE_CONFIG}|g' \
		${WRKSRC}/Makefile

do-install:
.for ii in ${DIRS}
	@${MKDIR} ${DATADIR}/data/${ii}
	@${INSTALL_DATA} ${WRKSRC}/data/${ii}/* ${DATADIR}/data/${ii}/
.endfor
	@${INSTALL_DATA} ${WRKSRC}/data/*.txt ${DATADIR}/data/
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
