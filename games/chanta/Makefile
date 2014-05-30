# Created by: Charlie & <root@HellFire.BSD.org.pe>
# $FreeBSD$

PORTNAME=	chanta
PORTVERSION=	0.15
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://www.losersjuegos.com.ar/_media/juegos/chanta/descargas/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free 2D jump and run game

USES=		gmake
USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD}

CHANTADIRS=	data ima

NO_STAGE=	yes
post-configure:
	@${REINPLACE_CMD} -e 's|-lSDL |`sdl-config --libs` |g' ${WRKSRC}/src/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|^CXXFLAGS|^CXXFLAGS?|g' ${WRKSRC}/src/${MAKEFILE}

do-install:
	${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/src && \
		${INSTALL_PROGRAM} chanta  ${PREFIX}/bin && \
			${FIND} ${CHANTADIRS} -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
				${FIND} -E ${CHANTADIRS} -type f -iregex ".*\.(png|dat)" \
					-exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && \
		${INSTALL_DATA} AUTHORS ChangeLog README ${DOCSDIR}
.endif

.include <bsd.port.mk>
