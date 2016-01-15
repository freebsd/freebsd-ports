# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	pongix
PORTVERSION=	0.4
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	http://www.losersjuegos.com.ar/_media/juegos/pongix/descargas/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free pong-like game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_SDL=	sdl image net
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-lm
PORTDOCS=	AUTHORS ChangeLog README

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/src && \
		${INSTALL_PROGRAM} pongix ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/data && ${FIND} * -type d \
		-exec ${MKDIR} "${STAGEDIR}${DATADIR}/{}" \; && \
		${FIND} -E * -type f -iregex ".*\.(jpg|bmp)" \
		-exec ${INSTALL_DATA} "{}" "${STAGEDIR}${DATADIR}/{}" \;
	cd ${WRKSRC} && ${INSTALL_DATA} \
		AUTHORS ChangeLog README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
