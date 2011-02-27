# New ports collection makefile for:	duel
# Date created:				10 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	duel
PORTVERSION=	0.98
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alepulver
DISTNAME=	lin${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An overhead, OpenGL space shooter

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		ftgl.2:${PORTSDIR}/graphics/ftgl

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GL=		gl
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="`${SDL_CONFIG} --cflags` `freetype-config --cflags` -I${LOCALBASE}/include -I${LOCALBASE}/include/FTGL" \
		LDFLAGS="`${SDL_CONFIG} --libs` -L${LOCALBASE}/lib"
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
