# New ports collection makefile for:	pongix
# Date created:		2006-04-01
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	pongix
PORTVERSION=	0.4
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.losersjuegos.com.ar/_media/juegos/pongix/descargas/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free pong-like game

USE_SDL=	sdl image net
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

do-install:
	${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/src && \
		${INSTALL_PROGRAM} pongix  ${PREFIX}/bin
	@cd ${WRKSRC}/data && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
			${FIND} -E * -type f -iregex ".*\.(jpg|bmp)" \
				-exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && \
	${INSTALL_DATA} AUTHORS ChangeLog README ${DOCSDIR}
.endif

.include <bsd.port.mk>
