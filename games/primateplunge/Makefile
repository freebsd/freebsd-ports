# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	primateplunge
PORTVERSION=	1.1
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.aelius.com/primateplunge/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Primate Plunge is an arcade game

RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer
PRIMATEDIR=	sounds graphics
OPTIONS_DEFINE=	DOCS

do-install:
	@${INSTALL_PROGRAM} ${STRIP} ${WRKSRC}/src/primateplunge ${STAGEDIR}${PREFIX}/bin/primateplunge
	@cd ${WRKSRC} && \
		${FIND}	${PRIMATEDIR} -type d -exec ${MKDIR} "${STAGEDIR}${DATADIR}/{}" \; && \
		${FIND} -E ${PRIMATEDIR} -type f -iregex ".*\.(bmp|wav|mid)" -exec ${INSTALL_DATA} "{}" "${STAGEDIR}${DATADIR}/{}" \;
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/AUTHORS ${WRKSRC}/TIPS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
