# New ports collection makefile for:	meandmyshadow
# Date created:		15 Jan 2012
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	meandmyshadow
PORTVERSION=	0.2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Me and My Shadow puzzle/platform game

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

USE_CMAKE=	yes
USE_SDL=	sdl ttf image mixer image gfx
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	*

DESKTOP_ENTRIES="Me and My Shadow" \
		"Puzzle/platform game" \
		"${DATADIR}/meandmyshadow.ico" \
		"meandmyshadow" \
		"Game;LogicGame;" \
		false

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/FindSDL_gfx.cmake

post-install:
	${INSTALL_DATA} ${WRKSRC}/windows-icon/meandmyshadow.ico \
		${DATADIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Controls.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
