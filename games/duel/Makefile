# New ports collection makefile for:	duel
# Date created:				10 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	duel
PORTVERSION=	0.98
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.personal.rdg.ac.uk/~sir03me/
DISTNAME=	lin${PORTNAME}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	An overhead, OpenGL space shooter

BUILD_DEPENDS=	${X11BASE}/lib/libftgl.a:${PORTSDIR}/graphics/ftgl
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_GL=		yes
USE_SDL=	sdl
REINPLACE_ARGS=	-i ''

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="`${SDL_CONFIG} --cflags` `freetype-config --cflags` -I${X11BASE}/include -I${X11BASE}/include/FTGL" \
		LDFLAGS="`${SDL_CONFIG} --libs` -L${X11BASE}/lib"

SUB_FILES=	${PORTNAME}-sh

post-patch:
# Fix SDL include statement
.for f in *.cpp *.h
	@${FIND} ${WRKSRC}/src -type f -name ${f} -print0 | \
		${XARGS} -0 \
		${REINPLACE_CMD} -e 's|\(#include.*\)SDL/\(SDL.*\)|\1\2|'
.endfor

# Remove -lSDL flag
	@${REINPLACE_CMD} -e 's|-lSDL ||' ${WRKSRC}/src/Makefile.in

do-install:
# Script
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-sh ${PREFIX}/bin/${PORTNAME}

# Program
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/libexec

# Data
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/runDir/* ${DATADIR}

post-install:
# Fix permissions
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	${FIND} ${DATADIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
	${FIND} ${DATADIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} ${BINMODE}

.include <bsd.port.mk>
