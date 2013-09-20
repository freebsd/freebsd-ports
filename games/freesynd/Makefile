# Created by: Lars Engels <lars.engels@0x20.net>
# $FreeBSD$

PORTNAME=	freesynd
PORTVERSION=	0.2
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	FreeSynd GPLed reimplementation of the classic Bullfrog game Syndicate

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
USE_ZIP=	yes
USE_SDL=	sdl mixer

WRKSRC=		${WRKDIR}/${PORTNAME}/src

SUB_FILES=	freesynd.sh

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's|-lpng|-lpng -L${LOCALBASE}/lib|g; \
		s|g++|${CXX}|g; \
		s|CXXFLAGS +=|CXXFLAGS=${CXXFLAGS} -DSYSTEM_SDL -DUSE_RWOPS|;' \
		${WRKSRC}/Makefile

do-install:
	${MKDIR} ${DATADIR}/data
	${INSTALL_PROGRAM} ${WRKSRC}/freesynd ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/freesynd.sh ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/*.mp3 ${DATADIR}
.for datafile in ${WRKDIR}/${PORTNAME}/data/*
	${INSTALL_DATA} ${WRKDIR}/${datafile} ${DATADIR}/data
.endfor

.include <bsd.port.mk>
