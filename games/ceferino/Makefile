# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	ceferino
PORTVERSION=	0.97.8
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	http://www.losersjuegos.com.ar/_media/juegos/ceferino/descargas/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Game similar to Super Pang

LICENSE=	GPLv2

USE_SDL=	sdl mixer image
GNU_CONFIGURE=	yes
USES=		gmake
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD}

CEFEDIRS=	ima music levels sounds

PORTDOCS=	AUTHORS ChangeLog README
OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

DESKTOP_ENTRIES="Don Ceferino Hazaña" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

.include <bsd.port.options.mk>

post-extract:
	@${REINPLACE_CMD} -e 's/-lSDL /`sdl-config --libs`/g' ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's/-pthread/-pthread -lintl/g' ${WRKSRC}/src/Makefile

do-install:
	@cd ${WRKSRC}/src && \
		${INSTALL_PROGRAM} ceferino ceferinoeditor ceferinosetup ${STAGEDIR}${PREFIX}/bin
	@cd ${WRKSRC}/data && \
		${FIND} ${CEFEDIRS} -type d -exec ${MKDIR} "${STAGEDIR}${DATADIR}/{}" \; && \
		${FIND} -E ${CEFEDIRS} -type f -iregex ".*\.(png|jpg|xm|map|wav)" -exec ${INSTALL_DATA} {} "${STAGEDIR}${DATADIR}/{}" \;
	${LN} -sf ${DATADIR}/ima/icono.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MNLS}
.for f in es ca fr
	${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${f}/LC_MESSAGES && \
		${INSTALL_DATA} ${WRKSRC}/po/${f}.gmo ${STAGEDIR}${PREFIX}/share/locale/${f}/LC_MESSAGES/${PORTNAME}.mo
.endfor
.endif

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
