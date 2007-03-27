# New ports collection makefile for:	duel
# Date created:				10 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	duel
PORTVERSION=	0.98
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alepulver
DISTNAME=	lin${PORTNAME}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	An overhead, OpenGL space shooter

BUILD_DEPENDS=	${X11BASE}/lib/libftgl.a:${PORTSDIR}/graphics/ftgl
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_GL=		yes
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="`${SDL_CONFIG} --cflags` `freetype-config --cflags` -I${X11BASE}/include -I${X11BASE}/include/FTGL" \
		LDFLAGS="`${SDL_CONFIG} --libs` -L${X11BASE}/lib"
WRKSRC=		${WRKDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}-sh

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-sh ${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/libexec
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/runDir/* ${DATADIR}
	${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
	${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} ${BINMODE}

.include <bsd.port.mk>
