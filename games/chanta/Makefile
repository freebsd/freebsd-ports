# Created by: Charlie & <root@HellFire.BSD.org.pe>
# $FreeBSD$

PORTNAME=	chanta
PORTVERSION=	0.15
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	http://www.losersjuegos.com.ar/_media/juegos/chanta/descargas/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free 2D jump and run game

USES=		gmake
USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD}
OPTIONS_DEFINE=	DOCS

CHANTADIRS=	data ima

post-configure:
	@${REINPLACE_CMD} -e 's|-lSDL |`sdl-config --libs` |g' ${WRKSRC}/src/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|^CXXFLAGS|^CXXFLAGS?|g' ${WRKSRC}/src/${MAKEFILE}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/src && \
		${INSTALL_PROGRAM} chanta  ${STAGEDIR}${PREFIX}/bin && \
			${FIND} ${CHANTADIRS} -type d -exec ${MKDIR} "${STAGEDIR}${DATADIR}/{}" \; && \
				${FIND} -E ${CHANTADIRS} -type f -iregex ".*\.(png|dat)" \
					-exec ${INSTALL_DATA} "{}" "${STAGEDIR}${DATADIR}/{}" \;
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && \
		${INSTALL_DATA} AUTHORS ChangeLog README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
