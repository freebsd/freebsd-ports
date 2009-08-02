# New ports collection makefile for:	vultures-claw
# Date created:				25 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	vultures
PORTVERSION=	2.1.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.darkarts.co.za/projects/vultures/attachment/wiki/downloads/${PORTVERSION}/
PKGNAMESUFFIX=	-claw
DISTFILES=	${DISTNAME}-full${EXTRACT_SUFX}?format=raw

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An isometric interface to Slash'EM based on Falcon's Eye

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl ttf mixer

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/slashem
DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

post-configure:
	@${REINPLACE_CMD} -e \
		"s|/local||g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		"s|^PREFIX|\#PREFIX|g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		"s|slashemdir|share/vultures-claw|g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|#include <SDL_image.h>||g' \
		${WRKSRC}/win/vultures/vultures_gfl.c

.include <bsd.port.mk>
