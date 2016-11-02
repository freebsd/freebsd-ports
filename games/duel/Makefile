# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	duel
PORTVERSION=	0.98
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	LOCAL/alepulver
DISTNAME=	lin${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Overhead, OpenGL space shooter

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libftgl.so:graphics/ftgl

USES=		tar:bzip2 libtool
USE_GL=		gl
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CPPFLAGS+=	`${SDL_CONFIG} --cflags` `freetype-config --cflags` -I${LOCALBASE}/include -I${LOCALBASE}/include/FTGL
LDFLAGS+=	`${SDL_CONFIG} --libs` -L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}-sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/libexec
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/runDir && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
