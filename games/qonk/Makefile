# New ports collection makefile for:	qonk
# Date created:				10 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	qonk
PORTVERSION=	0.0.1
CATEGORIES=	games
MASTER_SITES=	http://anthony.liekens.net/pub/files/

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Small build and conquer strategy game

USE_GMAKE=	yes
USE_SDL=	gfx sdl ttf
USE_REINPLACE=	yes

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on

.include <bsd.port.pre.mk>

post-patch:
# Fix Makefile
	@${REINPLACE_CMD} -e 's|g++|${CXX}| ; \
			s|sdl-config|${SDL_CONFIG}| ; \
			s|\(-O3\)|${CFLAGS} \1|' \
				${WRKSRC}/${MAKEFILE}

# Fix paths to ${DATADIR}
	@${REINPLACE_CMD} -e 's|\(font\.ttf\)|${DATADIR}/\1|' \
				${WRKSRC}/main.cpp ${WRKSRC}/messages.cpp

# Enable/disable compilation optimizations
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|-O3||' \
				${WRKSRC}/${MAKEFILE}
.endif

do-install:
# Program
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Data
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/font.ttf ${DATADIR}

.include <bsd.port.post.mk>
