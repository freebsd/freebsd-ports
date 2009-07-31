# New ports collection makefile for:	chanta
# Date created:		2006-04-01
# Whom:			Charlie & <root@HellFire.BSD.org.pe>
#
# $FreeBSD$
#

PORTNAME=	chanta
PORTVERSION=	0.15
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.losersjuegos.com.ar/_media/juegos/chanta/descargas/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free 2D jump and run game

USE_SDL=	sdl image mixer
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CHANTADIRS=	data ima

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
