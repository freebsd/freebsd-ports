# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	ceferino
PORTVERSION=	0.97.8
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	http://www.losersjuegos.com.ar/_media/juegos/ceferino/descargas/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Game similar to Super Pang

USE_SDL=	sdl mixer image
GNU_CONFIGURE=	yes
USES=		gmake
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD}

CEFEDIRS=	ima music levels sounds

OPTIONS_DEFINE=	NLS DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
PLIST_SUB+=	NLS=""
FLAG_NLS=	true
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
	@${REINPLACE_CMD} -e 's/-lSDL /`sdl-config --libs`/g' ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's/-pthread/-pthread -lintl/g' ${WRKSRC}/src/Makefile

do-install:
	@cd ${WRKSRC}/src && \
		${INSTALL_PROGRAM} ceferino ceferinoeditor ceferinosetup ${STAGEDIR}${PREFIX}/bin
	@cd ${WRKSRC}/data && \
		${FIND} ${CEFEDIRS} -type d -exec ${MKDIR} "${STAGEDIR}${DATADIR}/{}" \; && \
		${FIND} -E ${CEFEDIRS} -type f -iregex ".*\.(png|jpg|xm|map|wav)" -exec ${INSTALL_DATA} "{}" "${STAGEDIR}${DATADIR}/{}" \;
.if defined(FLAG_NLS)
.for f in es ca fr
	${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${f}/LC_MESSAGES && \
		${INSTALL_DATA} ${WRKSRC}/po/${f}.gmo ${STAGEDIR}${PREFIX}/share/locale/${f}/LC_MESSAGES/${PORTNAME}.mo
.endfor
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && \
		${INSTALL_DATA} AUTHORS ChangeLog README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
