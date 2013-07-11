# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	meandmyshadow
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Me and My Shadow puzzle/platform game

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USES=		cmake
USE_SDL=	sdl ttf image mixer image gfx
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	*

DESKTOP_ENTRIES="Me and My Shadow" \
		"Puzzle/platform game" \
		"${PREFIX}/share/pixmaps/meandmyshadow.png" \
		"meandmyshadow" \
		"Game;LogicGame;" \
		false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/FindSDL_gfx.cmake

post-install:
	${MKDIR} ${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/icons/64x64/meandmyshadow.png \
		${PREFIX}/share/pixmaps/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS ChangeLog docs/*
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
