# New ports collection makefile for:	kartofel
# Date created:		19 Jan 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kartofel
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://kartofel.jfedor.org/downloads/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Connect the dots in order without crossing over yourself

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

USE_GMAKE=	yes
USE_SDL=	sdl gfx mixer image ttf

ALL_TARGET=	default

DATA_DIRS=	sounds fonts music images levels

post-patch:
	@${REINPLACE_CMD} -e '/^CXXOPTIONS/ d; s|g++|${CXX} ${CXXFLAGS}|; \
		s|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/Makefile
.for d in ${DATA_DIRS}
	@${REINPLACE_CMD} -e 's|$d/|${DATADIR}/&|' ${WRKSRC}/config.h
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kartofel ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${DATA_DIRS}" ${DATADIR}

.include <bsd.port.mk>
