# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	alienblaster
PORTVERSION=	1.1.0
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.schwardtnet.de/alienblaster/archives/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alien Blaster

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake tar:tgz
USE_SDL=	mixer sdl
REINPLACE_ARGS=	-i ''

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
# Fix make command
	@${REINPLACE_CMD} -e 's|make|${MAKE_CMD}|g' ${WRKSRC}/${MAKEFILE}

# Fix Makefile
	@${REINPLACE_CMD} -e 's|alienBlaster|${PORTNAME}|g ; \
			s|g++|${CXX}|g ; \
			s|-g||g ; \
			s|sdl-config|${SDL_CONFIG}|g ; \
			s|@echo ""||g' \
				${WRKSRC}/src/Makefile

# Fix paths to ${DATADIR}
	@${REINPLACE_CMD} -e 's|\./|${DATADIR}/|g' \
				${WRKSRC}/src/global.h \
				${WRKSRC}/src/global.cc
	@${REINPLACE_CMD} -e 's|\./|${DATADIR}/|g ; \
			s|=\(images\)|=${DATADIR}/\1|g' \
				${WRKSRC}/cfg/level*.cfg

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

# Data
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for d in cfg images sound
	${CP} -R ${WRKSRC}/${d} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
